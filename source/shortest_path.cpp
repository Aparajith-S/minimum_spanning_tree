/// @brief		Shortest Path class declarations
/// @file		shortest_path.cpp
/// @author		Aparajith Sridharan (s.aparajith@live.com)
/// @date		27-08-2020
/// @details	
/// @history
/// @see ReadMe.md for more details

#pragma once
#include"shortest_path.h"
#include<string>
#include<vector>

std::vector<std::string> ShortestPath::vertices()
{
	std::vector<std::string> nodes;
	for (auto iter = ChildParentMap.begin();
		iter != ChildParentMap.end();
		iter++)
	{
		nodes.push_back(iter->first);
	}
	return nodes;
}

void ShortestPath::ComputeKruskalSP(const std::string& u, const std::string& w)
{
	//set the source node cost as 0 because it is the source.
	G.setNodeValue(u, 0.F);

	
}

std::vector<std::string> ShortestPath::path(const std::string& u, const std::string& w)
{
	std::vector<std::string> path;

	path.push_back(w);
	// store the src and dst nodes for future uses to improve efficiency
	srcNode = u;
	dstNode = w;

	// computes the Kruskal Shortest path from u till w
	ComputeKruskalSP(u, w);

	while (ChildParentMap[path.at(path.size() - 1)].size())
	{
		path.push_back(ChildParentMap[path.at(path.size() - 1)]);
	}

	return path;
}

float ShortestPath::path_size(const std::string& u, const std::string& w)
{
	// run the path finder again if different nodes were chosen as source and destination
	if (srcNode != u || dstNode != w)
	{
		static_cast<void>(path(u, w));
	}
	return G.getNodeValue(w);
}