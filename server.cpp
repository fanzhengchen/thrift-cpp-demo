#include <thrift/concurrency/ThreadManager.h>
#include <thrift/concurrency/PlatformThreadFactory.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/server/TNonblockingServer.h>
#include <thrift/server/TThreadPoolServer.h>
#include <thrift/server/TThreadedServer.h>
#include <thrift/transport/TNonblockingServerSocket.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>
#include <thrift/TToString.h>
#include <thrift/stdcxx.h>

#include <iostream>
#include <stdexcept>
#include <sstream>

using namespace apache::thrift;
using namespace apache::thrift::concurrency;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;
using namespace apache::thrift::server;

#include "gen-cpp/AIFilterService.h"

class AIHandler : public AIFilterServiceIf {

public:
    AIHandler() {

    }

    void invokeAIFilter(AIFilterResponse &response, const AIFilterRequest &req) {
        response.brightness = 0.1;
        response.gamma = 0.5;
        response.saturation = 0.0;
        response.shape = 0.2;
        response.contrast = 0.3;
        response.url = req.url;
        response.taskId = req.url;
        
        std::cout << "echo" << std::endl;
        response.printTo(std::cout);
    }
};


int
main(int argc, char **argv) {
    
    int port = 9000;
    ::apache::thrift::stdcxx::shared_ptr<AIHandler> handler(new AIHandler());
    ::apache::thrift::stdcxx::shared_ptr<TProcessor> processor(new AIFilterServiceProcessor(handler));
    ::apache::thrift::stdcxx::shared_ptr<TNonblockingServerSocket> serverSocket(new TNonblockingServerSocket(port));
    ::apache::thrift::stdcxx::shared_ptr<server::TNonblockingServer> server(
            new TNonblockingServer(processor, serverSocket));
    server->serve();


    return 0;
}