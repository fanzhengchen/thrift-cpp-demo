# - Find Thrift (a cross platform RPC lib/tool)
# This module defines
#  THRIFT_VERSION_STRING, version string of ant if found
#  THRIFT_LIBRARIES, libraries to link
#  THRIFT_INCLUDE_DIR, where to find THRIFT headers
#  THRIFT_COMPILER, thrift compiler executable
#  THRIFT_FOUND, If false, do not try to use ant
# Function
#  thrift_gen_cpp(<path to thrift file> <output variable with file list>)
#
# Initial work was done by Cloudera https://github.com/cloudera/Impala
# 2014 - modified by snikulov

# prefer the thrift version supplied in THRIFT_HOME (cmake -DTHRIFT_HOME then environment)
find_path(THRIFT_INCLUDE_DIR
        NAMES
        thrift/Thrift.h
        HINTS
        ${THRIFT_HOME}
        ENV THRIFT_HOME
        /usr/local
        /opt/local
        PATH_SUFFIXES
        include
        )

# prefer the thrift version supplied in THRIFT_HOME
find_library(THRIFT_LIBRARIES
        NAMES
        thrift libthrift
        HINTS
        ${THRIFT_HOME}
        ENV THRIFT_HOME
        /usr/local
        /opt/local
        PATH_SUFFIXES
        lib lib64
        )

find_library(THRIFTNB_LIBRARIES
        NAMES
        thriftnb libthriftnb
        HINTS
        ${THRIFT_HOME}
        ENV THRIFT_HOME
        /usr/local
        /opt/local
        PATH_SUFFIXES
        lib lib64
        )

find_program(THRIFT_COMPILER
        NAMES
        thrift
        HINTS
        ${THRIFT_HOME}
        ENV THRIFT_HOME
        /usr/local
        /opt/local
        PATH_SUFFIXES
        bin bin64
        )

include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(THRIFT DEFAULT_MSG THRIFT_LIBRARIES THRIFT_INCLUDE_DIR THRIFT_COMPILER)
mark_as_advanced(THRIFT_LIBRARIES THRIFT_INCLUDE_DIR THRIFTNB_LIBRARIES THRIFT_COMPILER THRIFT_VERSION_STRING)