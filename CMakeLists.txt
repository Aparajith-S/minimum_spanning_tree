CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

project(MinimumSpanningTree)

set(LIB_NAME "MSTree")

add_library(
${LIB_NAME}
#sources
${CMAKE_SOURCE_DIR}/source/undirected_graph.cpp
${CMAKE_SOURCE_DIR}/source/kruskal_simulation.cpp
${CMAKE_SOURCE_DIR}/source/minimum_spanning_tree.cpp
#includes
${CMAKE_SOURCE_DIR}/include/undirected_graph.h
${CMAKE_SOURCE_DIR}/include/myalgorithm.h
${CMAKE_SOURCE_DIR}/include/kruskal_simulation.h
${CMAKE_SOURCE_DIR}/include/minimum_spanning_tree.h
)

include_directories(
${LIB_NAME}
PUBLIC
${CMAKE_SOURCE_DIR}/include/
)

target_include_directories(
${LIB_NAME}
PUBLIC
${CMAKE_SOURCE_DIR}/include/
)

target_link_libraries (
${LIB_NAME}
PRIVATE
PUBLIC
)

add_executable(${PROJECT_NAME} main.cpp)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/SampleTestData_mst_data.txt
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(${PROJECT_NAME} MSTree)

add_custom_command(
  TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy 
    ${CMAKE_CURRENT_SOURCE_DIR}/SampleTestData_mst_data.txt
    $<TARGET_FILE_DIR:${PROJECT_NAME}>)