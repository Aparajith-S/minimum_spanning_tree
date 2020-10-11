#include<iostream>
#include"include/kruskal_simulation.h"
int main()
{
	std::string fileName("SampleTestData_mst_data.txt");
	KruskalSimulation sim(fileName);
	sim.printGraph();

	return 0;
}