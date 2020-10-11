/// @brief		Shortest Path class declarations
/// @file		shortest_path.h
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

///////////////////////////////////////
// Class definitions
///////////////////////////////////////
class ShortestPath
{
public:
	ShortestPath(Graph& graph) :G(graph) {};

	/// @brief lists all the vertices that form the shortest path
	/// @return vector of names of the vertices in the shortest path
	std::vector<std::string> vertices();

	/// @brief Computes the shortest path 
	/// @param[in] u: source node name
	/// @param[in] w: destination node name
	void ComputeKruskalSP(const std::string& u, const std::string& w);
	
	/// @brief returns the shortest path list of vertices 
	/// @param[in] u: source node name
	/// @param[in] w: destination node name
	/// @return vector of names of the vertices in the shortest path
	std::vector<std::string> path(const std::string& u, const std::string& w);

	/// @brief returns the shortest path list of vertices 
	/// @param[in] u: source node name
	/// @param[in] w: destination node name
	/// @return total cost associated with the shortest path
	float path_size(const std::string& u, const std::string& w);

private:
	
	Graph& G;
	std::string srcNode;
	std::string dstNode;
	std::unordered_map<std::string,std::string> ChildParentMap;
};
