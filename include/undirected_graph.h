/// @project    Kruskals Minimum Spanning Tree 
/// @brief	Undirected graph class declarations
/// @file	undirected_graph.h
/// @author Aparajith Sridharan (s.aparajith@live.com)
/// @date	25-08-2020
/// @details an application can use this graph to construct an undirected graph.
/// @see ReadMe.md for more details

#pragma once

///////////////////////////////////////
// Includes
///////////////////////////////////////
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<float.h>
#include<fstream>
#include"types.h"

namespace undirectedGraph {
	///////////////////////////////////////
	// function prototypes
	///////////////////////////////////////

	/// @brief : vertex name generator
	/// @details : generates increasing one or two letter names based on vertex index.
	///            sort of how an MS excel table columns increase A,...,Z,AA,...AZ,... so on till ZZ.
	///            which is 702 vertices maximum this name generator can handle.
	/// @returns : string containing the generated vertex name.
	std::string name_generator(uint32 vertex_idx);

	///////////////////////////////////////
	// Class definitions
	///////////////////////////////////////

	struct Edge
	{
		std::string start_node; // node from which it is an edge
		std::string end_node; // node to which it is an edge
		float value; // weight of the edge such as distance
		Edge() {}
		Edge(const std::string& src_node,
			const std::string& dst_node,
			const float& val) :start_node(src_node), end_node(dst_node), value(val) {}
		virtual ~Edge() {}
	};

	/// @class Graph Storage
	/// @details creates and manages a graph based on adjacency lists
	class Graph
	{
	public:

		Graph(const uint32 nodes);

		///@brief constructor that takes number of vertices and creates a graph with vertices and egdes as it is read from a file
		///@see ReadMe.md to understand how the file needs to be input
		Graph(const std::string& fileName);

		virtual ~Graph()
		{
			//empty destructor as vector is responsible to free the memory it allocates during destruction
		}

		///@brief fetches the number of vertices in the graph
		///@return unsigned integer number of vertices
		uint32 V();

		///@brief fetches the number of edges in the graph
		///@return unsigned integer number of edges
		uint32 E();

		///@brief fetches a list of neighbors of the node name in the argument
		///@param[in] x : node name 
		///@return list of neighboring node names
		std::vector<std::string> neighbors(const std::string& x);

		///@brief tests if the given nodes are neigbors or not
		///@param[in] x: node name string
		///@param[in] y: node name string
		///@return true if they have an edge
		///@return false if they don-t have an edge
		bool adjacent(const std::string& x, const std::string& y);

		///@brief adds an edge between the two nodes and assigns the distance 
		///@param[in] edgeValue : distance between x and y
		///@return true if the operation was successful
		///@return false if the operation fails
		bool add(const std::string& x, const std::string& y, const float edgeValue);

		///@brief removes an edge between the two nodes
		///@param[in] x: node name string
		///@param[in] y: node name string
		///@return true if the operation was successful
		///@return false if the operation fails
		bool del(const std::string& x, const std::string& y);

		///@brief get the nodevalue
		///@param[in] x: node name string
		///@return cost associated with the node
		float getNodeValue(const std::string& x);

		///@brief get the nodevalue
		///@param[in] x: node name string
		///@param[in] nodeValue: node value
		///@return true if the operation was successful
		///@return false if the operation fails
		bool setNodeValue(const std::string& x, const float nodeValue);

		///@brief get the edge value or distance between the two nodes
		///@details constant time to identify the vertex and O(E) to access the edge
		///@param[in] x: node name string
		///@param[in] y: node name string
		///@return distance between x and y
		float getEdgeValue(const std::string& x, const std::string& y);

		///@brief sets the EdgeValue or the distance between two nodes
		///@details constant time to identify the vertex and constant time to push the edge
		///@param[in] x: node name string
		///@param[in] y: node name string
		///@param[in] edgeValue : distance between x and y
		///@return true if the operation was successful
		///@return false if the operation fails
		bool setEdgeValue(const std::string& x, const std::string& y, const float edgeValue);

		std::vector<Edge> getEdgeList();

	private:

		uint32 numNodes;
		std::vector<Edge> edgeList; ///< store Edge list and its properties
		std::vector<std::pair<std::string, float>> nodeCost;
	};
}