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