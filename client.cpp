//
// Created by fanzhengchen on 1/5/19.
//

#include <iostream>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>
#include <thrift/stdcxx.h>

#include "gen-cpp/AIFilterService.h"

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;


int
main(int argc, char **argv) {

    std::ios::sync_with_stdio(false);
    std::cout << "thrift client begin" << std::endl;

    stdcxx::shared_ptr<TTransport> socket(new TSocket("localhost", 9000));
    stdcxx::shared_ptr<TTransport> transport(new TFramedTransport(socket));
    stdcxx::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));

    transport->open();
    AIFilterServiceClient client(protocol);
//
    AIFilterRequest request;
    AIFilterResponse response;
    request.__set_url(
            "https://qhrenderpicoss.kujiale.com/dev/2018/12/26/L3D268S14ENDIE6OD3AUIY6WYGMW3P3WK888_1280x720.jpg");
    request.__set_taskId("L3D268S14ENDIE6OD3AUIY6WYGMW3P3WK888");

    client.invokeAIFilter(response, request);

    transport->close();

    response.printTo(std::cout);

    std::cout << "end" << std::endl;
    return 0;
}