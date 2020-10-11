/// @brief	Undirected graph class declarations
/// @file	undirected_graph.h
/// @author Aparajith Sridharan (s.aparajith@live.com)
/// @date	25-08-2020
/// @details 
/// @history
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

/// @class Graph Storage
/// @details creates and manages a graph based on adjacency lists
class Graph
{
	//fwd declarations 
	struct Edge;
	struct Vertex;
public:

	///@brief constructor that takes number of vertices and creates a graph with only vertices and no edges.
	///@see DijkstraSimulation class in DijkstraSimulaiton.h to understand how a random graph is created. 
	Graph(const uint32 NrOfVertices) : vertices() 
	{ 
		Vertex temp = Vertex();
		vertices.rehash(NrOfVertices);
		std::string name;
		for (uint32 i = 0; i < NrOfVertices; i++)
		{ 
			name = name_generator(i);
			vertices[name]=temp;
		}
	};

	///@brief constructor that takes number of vertices and creates a graph with vertices and egdes as it is read from a file
	///@see ReadMe.md to understand how the file needs to be input
	Graph(const std::string& fileName) : vertices()
	{
		Vertex temp = Vertex();
		std::ifstream fptr(fileName);
		std::istream_iterator<std::string> fstart(fptr);
		std::istream_iterator<std::string> fend;
		uint16 NrOfVertices=0;
		std::vector<std::string> words;
		vertices.rehash(NrOfVertices);
		std::string name;
		for (uint32 i = 0; i < NrOfVertices; i++)
		{
			name = name_generator(i);
			vertices[name] = temp;
		}
	};

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

private:

	struct Edge
	{
		std::string node; // node to which it is an edge to
		float value; // weight of the edge such as distance
		Edge() {}
		Edge(const std::string& node, const float& val):node(node),value(val){}
		virtual ~Edge(){}
	};
	
	struct Vertex
	{
		float value; // distance from the source
		std::vector<Edge> edges; 

		/// @brief constructor
		/// @details set initial value to infinity i.e. max Float value
		Vertex():value(FLT_MAX), edges(){}
		Vertex(const float& val) :value(val),edges(){}
		virtual ~Vertex() {}
	};

	std::unordered_map<std::string,Vertex> vertices; ///< store name of vertex and its properties
};

