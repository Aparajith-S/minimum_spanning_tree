CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

project(MinimumSpanningTree)

add_subdirectory(source)
add_executable(${PROJECT_NAME} main.cpp)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/SampleTestData_mst_data.txt
    ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
target_link_libraries(${PROJECT_NAME} MSTree)
