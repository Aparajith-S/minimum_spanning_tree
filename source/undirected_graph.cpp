/// @brief   Undirected graph class definitions
/// @file    undirected_graph.cpp
/// @author  Aparajith Sridharan (s.aparajith@live.com)
/// @date	 25-08-2020
/// @details 
/// @history

#include"undirected_graph.h"
#include<algorithm>

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

uint32 Graph::V() 
{
	return vertices.size();
}

uint32 Graph::E()
{
	uint32 sum = 0;
	for (auto iter = vertices.begin(); 
		iter != vertices.end(); 
		iter++)
	{	
		sum+= iter->second.edges.size();
	}
	return sum;
}

std::vector<std::string> Graph::neighbors(const std::string& x) 
{
	std::vector<std::string> temp= std::vector<std::string>();
	if (vertices.find(x)!= vertices.end())
	{
		for (auto iter = vertices.at(x).edges.begin(); 
			iter != vertices.at(x).edges.end(); 
			iter++)
		{
			temp.push_back(iter->node);
		}
	}
	return temp;
}

bool Graph::adjacent(const std::string& x, const std::string& y)
{
	bool isTrue = false;
    auto found = std::find_if(vertices.at(x).edges.begin(), 
		vertices.at(x).edges.end(), 
		[&](Edge edge) {return (edge.node == y);});
	
	isTrue = found != vertices.at(x).edges.end();
	return isTrue;
}

bool Graph::add(const std::string& x, const std::string& y, const float edgeValue)
{
	bool success=false;
	if (vertices.find(x) != vertices.end() && vertices.find(y) != vertices.end())
	{
		success = true;
		Edge temp(y, edgeValue);
		vertices.at(x).edges.push_back(temp);
		temp.node = x;
		vertices.at(y).edges.push_back(temp);
	}
	return success;
}

bool Graph::del(const std::string& x, const std::string& y) 
{

	bool success = false;
	if (vertices.find(x) != vertices.end() && vertices.find(y) != vertices.end())
	{
		success = adjacent(x, y);
		if (success)
		{

			for (auto iter = vertices.at(x).edges.begin();
				iter != vertices.at(x).edges.end();
				iter++)
			{
				if (iter->node == y)
				{
					vertices.at(x).edges.erase(iter);
					break;
				}
			}

			for (auto iter = vertices.at(y).edges.begin();
				iter != vertices.at(y).edges.end();
				iter++)
			{
				if (iter->node == x)
				{
					vertices.at(y).edges.erase(iter);
					break;
				}
			}


		}
	}
	return success;
}

float Graph::getNodeValue(const std::string& x)
{
	if (vertices.find(x) != vertices.end())
	{
		return vertices.at(x).value;
	}
	else
	{
		return FLT_MAX;
	}
}

bool Graph::setNodeValue(const std::string& x, const float nodeValue)
{
	bool success = false;
	if (vertices.find(x) != vertices.end())
	{
		vertices.at(x).value = nodeValue;
		success = true;
	}
	return success;
}

float Graph::getEdgeValue(const std::string& x, const std::string& y) 
{
	float egdeVal = FLT_MAX;
	if (vertices.find(x) != vertices.end())
	{
		auto found = std::find_if(vertices.at(x).edges.begin(),
			vertices.at(x).edges.end(),
			[&](Edge edge) { return(edge.node == y); });
		if (found != vertices.at(x).edges.end())
		{
			egdeVal = found->value;
		}
	}
	return egdeVal;
}

bool Graph::setEdgeValue(const std::string& x, const std::string& y, const float edgeValue)
{
	bool success = false;
	if (vertices.find(x) != vertices.end())
	{
		auto found = std::find_if(vertices.at(x).edges.begin(),
			vertices.at(x).edges.end(),
			[&](Edge edge) { return(edge.node == y); });
		if (found != vertices.at(x).edges.end())
		{
			found->value = edgeValue;
			success = true;
		}
	}

	if (vertices.find(y) != vertices.end())
	{
		auto found = std::find_if(vertices.at(y).edges.begin(),
			vertices.at(y).edges.end(),
			[&](Edge edge) { return(edge.node == x); });
		if (found != vertices.at(y).edges.end())
		{
			found->value = edgeValue;
		    success &= true;
		}
	}

	return success;
}
