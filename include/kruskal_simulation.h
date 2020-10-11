/// @brief		Shortest Path class declarations
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
#include"shortest_path.h"

///////////////////////////////////////
// Class definitions
///////////////////////////////////////
class KruskalSimulation
{
public:
	KruskalSimulation(const uint32 numVertices,
		const float ProbDensity,
		const std::pair<float, float> distRange) :
		G(numVertices),
		SP(G),
		density(ProbDensity),
		numOfVertices(numVertices),
		distanceRange(distRange)
	{
		weight_generator();
		random_graph_generator();
	};

	KruskalSimulation(const std::string& fileName) :
		G(fileName),
		SP(G),
		density(0),
		distanceRange({ 0 , 0})
	{
		numOfVertices = G.V();
	};

	/// @brief run the shortest path algorithm workflow for all nodes and print paths, average, etc.
	/// @return path average for all paths from the source.
	float runKruskalAverage(std::string source);

	///@brief prints the graph
	void printGraph();

	///@brief prints the shortest path link from source to destination if it exists
	void print_path(const std::vector<std::string>& path, const std::string& srcNode);

	/// @brief generates a weight given by range between all vertices randomly.
	void weight_generator();
	
	/// @brief generates a random graph based on the density given
	void random_graph_generator();

	/// @brief re-draws the graph with a new density
	/// @details Worst-case quadratic time complexity
	void reGraph(float probDensity);

private:

	/// @brief Computes and returns the value based on probability density function on random values.
	/// @details Treat this as an integral over the likelihood of a outcome in the normal distribution.
	/// @return outcome [min,max] = [0.0 , 1.0]
	float probability_density();

	/// @brief A hash function used to hash a pair of any kind 
	struct hash_pair {
		template <class T1, class T2>
		size_t operator()(const std::pair<T1, T2>& p) const
		{
			auto hash1 = std::hash<T1>{}(p.first);
			auto hash2 = std::hash<T2>{}(p.second);
			return hash1 ^ hash2;
		}
	};

	Graph G;
	ShortestPath SP;
	std::unordered_map<std::pair<uint32, uint32>, float, hash_pair> edgeWeights;
	float density;
	uint32 numOfVertices;
	std::pair<float, float> distanceRange;
};