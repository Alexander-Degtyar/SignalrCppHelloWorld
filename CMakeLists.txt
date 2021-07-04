cmake_minimum_required(VERSION 3.5)
project(SignalrCppHelloWorld)

set(CMAKE_CXX_STANDARD 17)

if (UNIX)
    add_compile_definitions(NO_SIGNALRCLIENT_EXPORTS)
endif(UNIX)

find_package(microsoft-signalr REQUIRED)
find_package(Boost REQUIRED COMPONENTS
        random
        system
        thread
        filesystem
        chrono
        atomic
        date_time
        regex)

add_executable(SigralrCppHelloWorld client.cpp)
target_link_libraries(SigralrCppHelloWorld PUBLIC
        microsoft-signalr::microsoft-signalr
        ${Boost_LIBRARIES})
