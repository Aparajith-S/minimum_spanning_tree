#include<iostream>
#include"include/kruskal_simulation.h"
using KruskalSim::KruskalSimulation;

int main()
{
	std::string fileName("SampleTestData_mst_data.txt");
	KruskalSimulation sim(fileName);
	sim.printGraph();
	sim.runKruskal();
	sim.printResult();
	return 0;
}