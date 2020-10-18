/// @project    Kruskals Minimum Spanning Tree 
/// @brief		simulation class definitions
/// @file		kruskal_simulation.cpp
/// @author		Aparajith Sridharan (s.aparajith@live.com)
/// @date		30-08-2020
/// @details	Main entry point for the entire project. Ostream usage is assumed to be allowed to print to console/file
/// @history
/// @see		ReadMe.md for more details. 
/// @see		kruskal_simulation.h for more details

#include"kruskal_simulation.h"
#include<iostream>
using undirectedGraph::Edge;
using undirectedGraph::name_generator;
namespace KruskalSim {
	void KruskalSimulation::runKruskal()
	{ 
		selectedEdges = MST.ComputeKruskalMST();
	}

	void KruskalSimulation::printGraph()
	{
		std::cout << "Graph layout" << std::endl;
		std::cout << "Src Node" << "   " << "Dst Node" << "  Distance " << std::endl;
		for (uint32 i = 0; i < G.V(); i++)
		{
			for (uint32 j = 0; j < G.V(); j++)
			{
				if (i < j)
				{
					std::string x = name_generator(i);
					std::string y = name_generator(j);
					if (G.adjacent(x, y))
					{
						std::cout << '\t' << x << '\t' << y << '\t' << G.getEdgeValue(x, y) << "\t" << std::endl;
					}
				}
			}
		}
	}

	void KruskalSimulation::printResult()
	{
		float cost = 0.0F;
		std::cout << "Edges of minimum spanning tree : ";
		for (auto& edge : selectedEdges) 
		{
			std::cout << std::endl<< "[" << edge.start_node << "-" << edge.end_node << "](" << edge.value << ") ";
			cost += edge.value;
		}
		std::cout << std::endl;
		std::cout << "The cost for the minimum spanning tree is:"<<cost;
	}
}
