/// @project    Kruskals Minimum Spanning Tree
/// @brief		kruskal simulation class declarations
/// @file		kruskal_simulation.h
/// @author		Aparajith Sridharan (s.aparajith@live.com)
/// @date		11-10-2020
/// @details	Main entry point for the entire project. Ostream usage is assumed to be allowed to print to console/file
/// @history
/// @see		ReadMe.md for more details

#pragma once

///////////////////////////////////////
// Includes
///////////////////////////////////////
#include"minimum_spanning_tree.h"

namespace KruskalSim {
	///////////////////////////////////////
	// Class definitions
	///////////////////////////////////////
	class KruskalSimulation
	{
	public:

		KruskalSimulation(const std::string& fileName) :
			G(fileName),
			MST(G)
		{};

		///@brief runs the kruskals algorithm. it saves the result in member selectedEdges
		/// @details use printResult to print the result of this computation 
		void runKruskal();

		///@brief prints the graph
		void printGraph();

		///@brief prints the edge lists forming the minimum spanning tree
		void printResult();

	private:

		undirectedGraph::Graph G;
		Kruskal::MinimumSpanningTree MST;
		std::vector<undirectedGraph::Edge> selectedEdges;
	};
}