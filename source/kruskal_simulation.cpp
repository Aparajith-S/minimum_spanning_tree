/// @brief		Shortest Path class definitions
/// @file		dijkstra_simulation.cpp
/// @author		Aparajith Sridharan (s.aparajith@live.com)
/// @date		30-08-2020
/// @details	Main entry point for the entire project. Ostream usage is assumed to be allowed to print to console/file
/// @history
/// @see		ReadMe.md for more details. 
/// @see		dijkstra_simulation.h for more details

#include"kruskal_simulation.h"
#include<iostream>

float KruskalSimulation::runKruskalAverage(std::string source)
{
	int i = 0;
	float averageCost = 0;
	int numberFairTrials = G.V()-1;

	while (i < G.V())
	{
		float cost = FLT_MAX;
		std::string destination = name_generator(i++);
		if (source != destination)
		{
			//prints the path using the shortest path obtained
			print_path(SP.path(source, destination), source);
			//gets the path size associated with the obtained shortest path
			cost = SP.path_size(source, destination);
			//print the path
			std::cout << "Total cost is : " << cost << std::endl;
			
			if (cost == FLT_MAX)
			{
				numberFairTrials--;
			}
			else
			{
				averageCost += cost;
			}
		}
	}
	averageCost /= numberFairTrials;
	std::cout << "Average Cost for 50 paths:" << averageCost << std::endl;
	
	return averageCost;
}

void KruskalSimulation::printGraph()
{
	std::cout << "Graph layout"<<std::endl;
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

void KruskalSimulation::print_path(const std::vector<std::string>& path, const std::string& srcNode)
{

	if (path.at(path.size() - 1) != srcNode)
	{
		std::cout << "node "<<path[0]<<" is isolated." << std::endl;
	}
	else
	{
		std::cout << "Path: Source =>";
		for (auto iter = path.rbegin();
			iter != path.rend();
			iter++)
		{
			if (iter != path.rend() - 1)
			{
				std::cout << *iter << " --> ";
			}
			else
			{
				std::cout << *iter;
			}
		}

		std::cout << "<= Destination" << std::endl;
	}
}

/// @brief generates a weight given by range between all vertices randomly.
void KruskalSimulation::weight_generator()
{
	for (uint32 i = 0; i < numOfVertices - 1; i++)
	{
		for (uint32 j = 0; j < numOfVertices; j++)
		{
			//this is a undirected graph so remember we need only the upper triangle 
			//of the vertex matrix in case of full connectivity. 
			//Also it stores only the i->j connection weight as the converse j->i is redundant information.
			if (i < j)
			{
				edgeWeights.insert({ {i,j}, float(rand() % (static_cast<uint32>(distanceRange.second - distanceRange.first) * 100) + distanceRange.first * 100) / 100.0F });
			}
		}
	}
}

/// @brief generates a random graph based on the density given
void KruskalSimulation::random_graph_generator()
{
	for (uint32 i = 0; i < numOfVertices - 1; i++)
	{
		for (uint32 j = 0; j < numOfVertices; j++)
		{
			if (i < j && probability_density() < density)
			{
				G.add(name_generator(i), name_generator(j), edgeWeights.at({ i, j }));
			}
		}
	}
}

/// @brief re-draws the graph with a new density
/// @details Worst-case quadratic time complexity
void KruskalSimulation::reGraph(float probDensity)
{
	density = probDensity;
	random_graph_generator();
}

float KruskalSimulation::probability_density()
{
	return float(rand() % 101) / 100.0F;
}
