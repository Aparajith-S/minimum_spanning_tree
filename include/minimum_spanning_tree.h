/// @project    Kruskals Minimum Spanning Tree 
/// @brief		Minimum Spanning Tree class declarations
/// @file		minimum_spanning_tree.h
/// @author		Aparajith Sridharan (s.aparajith@live.com)
/// @date		27-08-2020
/// @details	
/// @history
/// @see ReadMe.md for more details

#pragma once

///////////////////////////////////////
// Includes
///////////////////////////////////////
#include"undirected_graph.h"
#include<string>
#include<vector>
#include<iostream>
namespace Kruskal {
	///////////////////////////////////////
	// Class definitions
	///////////////////////////////////////
	class MinimumSpanningTree
	{
	public:
		MinimumSpanningTree(undirectedGraph::Graph& graph) :G(graph), ChildParentMap(), Rank()
		{
			uint32 nrVertices = G.V();
			for (uint32 i = 0;
				i < nrVertices;
				i++)
			{
				std::string node = undirectedGraph::name_generator(i);
				ChildParentMap[node] = node;
				Rank[node] = 0;
			}
		}

		/// @brief Computes the minimum spanning tree according to kruskal-s algorithm
		/// @details
		/// @return Edge list with the selected edges forming the minimum spanning tree
		std::vector<undirectedGraph::Edge> ComputeKruskalMST();

		/// @brief find the top most parent of the child
		/// @details recurse into the parents-child list and get the topmost parent of the given child
		/// @param child of type string
		/// @return parent of type string
		std::string getParent(const std::string& child);
	private:

		undirectedGraph::Graph& G;
		std::unordered_map<std::string, std::string> ChildParentMap;
		std::unordered_map<std::string, uint32> Rank;
	};
}