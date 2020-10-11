set(LIB_NAME "MSTree")

add_library(
${LIB_NAME}
#sources
${CMAKE_SOURCE_DIR}/source/minimum_spanning_tree.cpp
${CMAKE_SOURCE_DIR}/source/undirected_graph.cpp
#includes
${CMAKE_SOURCE_DIR}/include/undirected_graph.h
${CMAKE_SOURCE_DIR}/include/minimum_spanning_tree.h
${CMAKE_SOURCE_DIR}/include/types.h
)

include_directories(
${LIB_NAME}
PUBLIC
${CMAKE_SOURCE_DIR}/include
)

target_include_directories(
${LIB_NAME}
PUBLIC
${CMAKE_SOURCE_DIR}/include
)

target_link_libraries (
${LIB_NAME}
PRIVATE
PUBLIC
)