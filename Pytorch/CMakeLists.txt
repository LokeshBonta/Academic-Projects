cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(custom_ops)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ../)


find_package(Torch REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")

add_executable(example-app torchscript.cpp)
target_link_libraries(example-app "${TORCH_LIBRARIES}")
set_property(TARGET example-app PROPERTY CXX_STANDARD 14)