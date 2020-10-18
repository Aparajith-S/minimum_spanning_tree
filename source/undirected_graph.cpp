/// @project    Kruskals Minimum Spanning Tree
/// @brief   Undirected graph class definitions
/// @file    undirected_graph.cpp
/// @author  Aparajith Sridharan (s.aparajith@live.com)
/// @date	 25-08-2020
/// @details 
/// @history

#include"undirected_graph.h"
#include<algorithm>
#include"myalgorithm.h"
#include<iostream>
namespace undirectedGraph {
	/// @brief : vertex name generator
	/// @see : undirected_graph.h for more details
	std::string name_generator(uint32 vertex_idx)
	{
		std::string temp;
		int number = vertex_idx;
		int i = 0;
		if (number > 25)
		{
			int first = number / 26;
			temp.push_back(char(64 + first));
			int second = number % 26;
			temp.push_back(char(65 + second));
		}
		else
		{
			int second = number % 26;
			temp.push_back(char(65 + second));
		}
		return temp;
	}

	Graph::Graph(const uint32 nodes) :numNodes(nodes)
	{}

	Graph::Graph(const std::string& fileName) : numNodes(0), edgeList()
	{
		std::ifstream fptr(fileName);
		std::istream_iterator<std::string> fstart(fptr);
		std::istream_iterator<std::string> fend;
		uint16 NrOfVertices = 0;
		std::vector<std::string> words(fstart, fend);
		if (!fptr)
			std::cout << "ERROR! File not found";
		else
		{
			if (words.size())
			{
				NrOfVertices = std::stoi(words.at(0));
			}
			if (NrOfVertices)
			{
				numNodes = NrOfVertices;
				for (auto iter = words.begin() + 1;
					iter != words.end();
					)
				{
					//first is the source vertex
					uint16 src = std::stoi(*iter);
					iter++;
					//second is the destination vertex
					uint16 dest = std::stoi(*iter);
					iter++;
					//third is the edge value
					float32 edge = std::stof(*iter);
					iter++;
					this->add(name_generator(src), name_generator(dest), edge);
				}
			}
		}
	}

	uint32 Graph::V()
	{
		return numNodes;
	}

	uint32 Graph::E()
	{
		return edgeList.size() / 2;
	}

	std::vector<std::string> Graph::neighbors(const std::string& x)
	{
		std::vector<std::string> temp;
		for (auto iter = edgeList.begin();
			iter != edgeList.end();
			iter++)
		{
			if (iter->start_node == x)
			{
				temp.push_back(iter->end_node);
			}
		}
		return temp;
	}

	bool Graph::adjacent(const std::string& x, const std::string& y)
	{
		bool isTrue = false;
		auto found = std::find_if(edgeList.begin(),
			edgeList.end(),
			[&](Edge edge) {return (edge.start_node == x && edge.end_node == y); });
		isTrue = found != edgeList.end();
		return isTrue;
	}

	bool Graph::add(const std::string& x, const std::string& y, const float edgeValue)
	{
		bool success = false;
		Edge temp(x, y, edgeValue);
		if (edgeList.size())
		{
			auto pos = myalgo::binary_search(edgeList.begin(),
				edgeList.end(),
				temp,
				[&](Edge left, Edge right) {return (left.value > right.value); });

			static_cast<void>(edgeList.insert(pos, temp));
			success = true;
		}
		else
		{
			success = true;
			edgeList.push_back(temp);
		}
		return success;
	}

	bool Graph::del(const std::string& x, const std::string& y)
	{

		bool success = false;
		success = adjacent(x, y);
		if (success)
		{
			uint8 count = 0;
			for (auto iter = edgeList.begin();
				iter != edgeList.end();
				iter++)
			{
				if (iter->start_node == x && iter->end_node == y ||
					iter->start_node == y && iter->end_node == x)
				{
					success = true;
					edgeList.erase(iter);
					if (++count == 2)
					{
						break;
					}
				}
			}

		}
		return success;
	}

	float Graph::getNodeValue(const std::string& x)
	{
		auto found = find_if(nodeCost.begin(),
			nodeCost.end(),
			[&](std::pair<std::string, float> val) {return val.first == x; });
		if (found != nodeCost.end())
		{
			return found->second;
		}
		else
		{
			return FLT_MAX;
		}
	}

	bool Graph::setNodeValue(const std::string& x, const float nodeValue)
	{
		bool success = false;
		auto found = find_if(nodeCost.begin(),
			nodeCost.end(),
			[&](std::pair<std::string, float> val) {return val.first == x; });
		if (found != nodeCost.end())
		{
			found->second = nodeValue;
			success = true;
		}
		return success;
	}

	float Graph::getEdgeValue(const std::string& x, const std::string& y)
	{
		float edgeVal = FLT_MAX;
		bool success = false;
		auto found = std::find_if(edgeList.begin(),
			edgeList.end(),
			[&](Edge edge) {return (edge.start_node == x && edge.end_node == y); });
		if (found != edgeList.end())
		{
			edgeVal = found->value;
		}
		return edgeVal;
	}

	bool Graph::setEdgeValue(const std::string& x, const std::string& y, const float edgeValue)
	{
		bool success = false;
		success = del(x, y);
		success &= add(x, y, edgeValue);
		success &= add(y, x, edgeValue);
		return success;
	}

	std::vector<Edge> Graph::getEdgeList()
	{
		return edgeList;
	}
}