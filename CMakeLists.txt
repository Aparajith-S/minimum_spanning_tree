CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "RelWithDebInfo" CACHE STRING "Choose the type of build, options are: Debug Release RelWithDebInfo MinSizeRel." FORCE)
endif()
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

project(MinimumSpanningTree)

add_subdirectory(source)
add_executable(myapp main.cpp)
target_link_libraries(myapp MSTree)
install(TARGETS myapp DESTINATION bin)