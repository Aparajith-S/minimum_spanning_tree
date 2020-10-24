# Kruskal's Minimum Spanning Tree
author: Aparajith Sridharan  
date : 11.10.2020  

## Description
This project implements the Kruskal's minimum spanning tree algorithm.

## Dependencies
CMake - recommended latest version, minimum version 2.8  
C++ min version 11  
Windows x64 compiler : VC100(minimum) tested on VC142(VS 2019)  
currently not tested on linux, since the concepts used are made to compile with C++11 standard, it should compile on gcc > 4.6

## Build the Project
This is a CMake project built to work with MS Visual Studio 2010 onwards.  
If you do not own a copy of Visual Studio you can download a community version for free here : https://visualstudio.microsoft.com/downloads/  
If you do not have Cmake installed get the latest version over here: https://cmake.org/download/

1. Clone the project from git from here https://github.com/Aparajith-S/minimum_spanning_tree or download it to your PC.
2. open cmd from the root folder of this project and type in the following commands
	
		mkdir build  
		cmake -B build  

This should generate the visual studio .sln solution file in \build folder.  
Open it in VS and right click the project `MinimumSpanningTree` on the solution explorer and click `set as Startup project`.  
Clicking on `Debug -> run without Debug` will now run the project and display the output.  

## Code
The project builds the library `MSTree.lib` and it contains three main classes
`Graph` class under `undirected_graph.h` which accepts a filename to a text file that follows the specific description of a graph, it's vertices and edges.  
see to the end under the text file contents for more context.  

`MinimumSpanningTree` class declared in `minimum_spanning_tree.h` file uses `Graph` class to construct a graph from a given filename.
 - The `std::vector<Edge> ComputeKruskalMST()` member function will compute the minimum spanning tree for the given graph in file and return all selected edges.

`KruskalSimulation` class declared in `kruskal_simulation.h` file uses `MinimumSpanningTree` class to initialize a object of `Graph` and execute kruskals algorithm.
 - The member function `void runKruskal()` will run the algorithm and save the selected edges list in the object.
 - The member function `void printGraph()` will print the input graph
 - The member function `void printResult()` will print the list of edges that form the Minimum Spanning Tree and the cost of the tree.

## Text file contents
the text file shall contain only numbers and delimiter used shall be a single space or carriage return.  

the first line denotes the number of vertices in the graph.
the second line onwards shall contain the following 


e.g. for edge between node 1 and 2 with cost of 3:  
20  
0 1 3  
1 0 3  
and so on..  

## Troubleshooting problems
Application displays "ERROR! File not found". 
Make sure the input text file is available at the project root directory and named exactly as the filename given in the `main.cpp` file.  
Once this is solved, run the cmake build as described in `Build the Project` section.  
If the error still persists, copy the .txt file and paste it both in the \build folder and 
in the folder where `MinimumSpanningTree.exe` is present and run the .exe from the command prompt.
