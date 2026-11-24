cmake_minimum_required(VERSION 3.20)

project(EmbeddedTelemetryNode
    VERSION 1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(EmbeddedTelemetryNode
    src/main.cpp
)

target_include_directories(EmbeddedTelemetryNode
    PRIVATE
        include
)

enable_testing()

add_executable(RingBufferTests
    tests/ring_buffer_tests.cpp
)

target_include_directories(RingBufferTests 
    PRIVATE 
    include
)

add_test(NAME RingBufferTests COMMAND RingBufferTests)