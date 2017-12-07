#include "graph.h"

using namespace std;

/*
	For this assignment, assume that your graph class can have maximum of 20 vertices
	and your graph has 10 vertices and 15 edges with some weights.
*/


int main(void)
{
	graph<double> g;

	// Add vertex 6
	for (int i = 0; i < 10; i++)
	{
		g.add_vertex((double)i);
	}

	g.add_edge(0, 1, 2);
	g.add_edge(0, 7, 8);
	g.add_edge(1, 8, 9);
	g.add_edge(1, 9, 6);
	g.add_edge(6, 7, 15);
	g.add_edge(9, 6, 1);
	g.add_edge(8, 6, 7);
	g.add_edge(8, 2, 3);
	g.add_edge(6, 2, 12);
	g.add_edge(9, 2, 1);
	g.add_edge(5, 9, 9);
	g.add_edge(4, 5, 11);
	g.add_edge(3, 4, 3);
	g.add_edge(2, 3, 8);
	g.add_edge(8, 3, 1);

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout.width(5);
			cout << g.is_edge(i, j);
		}
		cout << endl;
	}

	g.shortestPath(0);

	g.shortestPath(5);
	while (1) {}

	return 0;
}