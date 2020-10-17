/// @brief		Minimum spanning tree class declarations
/// @file		minimum_spanning_tree.cpp
/// @author		Aparajith Sridharan (s.aparajith@live.com)
/// @date		27-08-2020
/// @details	
/// @history
/// @see ReadMe.md for more details

#pragma once
#include"minimum_spanning_tree.h"
#include<string>
#include<vector>
using undirectedGraph::Edge;
namespace Kruskal{
/// @brief gets the parent of a child node
/// @see minimum_spanning_tree.h
std::string MinimumSpanningTree::getParent(const std::string& node)
{
	std::string parent = ChildParentMap[node];
	std::string child = node;
	while (parent!=child)
	{
		child = parent;
		parent = ChildParentMap[child];
	}
	return parent;
}

/// @brief computes using the Kruskals algorithm, the minimum spanning tree
/// @see minimum_spanning_tree.h
std::vector<Edge> MinimumSpanningTree::ComputeKruskalMST()
{
	std::vector<Edge> edgeList;
	std::vector<Edge> selectedEdges;
	edgeList = G.getEdgeList();
	for (auto& e : edgeList) {
		std::string parent1 = getParent(e.start_node);
		std::string parent2 = getParent(e.end_node);
		
		//check if there is a cycle in the graph
		if (parent1 != parent2)
		{
			//there was no cycle so push it into the list 
			selectedEdges.push_back(e);
			//rank is used to determine who shall be the parent.
			//it is obvious that a higher rank indicates that the 
			//parent has many children and will take ownership of a lesser rank parent
			if (Rank[parent1] < Rank[parent2])
			{
				ChildParentMap[parent1] = parent2;
				Rank[parent2]++;
			}
			else
			{
				ChildParentMap[parent2] = parent1;
				Rank[parent1]++;
			}
		}
	}
	return selectedEdges;
}
}