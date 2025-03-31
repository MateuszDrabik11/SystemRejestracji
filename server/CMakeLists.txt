cmake_minimum_required(VERSION 3.0)
project(server)

set(CMAKE_CXX_STANDARD 20)

find_package(Qt6 COMPONENTS Widgets REQUIRED)

include(FetchContent)
FetchContent_Declare(
  gRPC
  GIT_REPOSITORY https://github.com/grpc/grpc
  GIT_TAG v1.51.1
)
set(FETCHCONTENT_QUIET OFF)
FetchContent_MakeAvailable(gRPC)

add_executable(server
    main.cpp
    ../lib/sqlite3.c
    ../lib/com.pb.h ../lib/com.pb.cc
    ../lib/com.grpc.pb.h ../lib/com.grpc.pb.cc
    ../lib/med_event.h ../lib/med_event.cpp
    ../lib/exam_results.h ../lib/exam_results.cpp
        ../lib/schedule.cpp
        ../lib/schedule.h
        ../lib/schedule.h
        app_control.cpp
        app_control.h
        server.cpp
        server.h
)

target_link_libraries(server PRIVATE Qt6::Widgets grpc++)

if(MINGW)
    target_link_libraries(server PRIVATE ws2_32)
endif()
