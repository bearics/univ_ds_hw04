#pragma once

#include <iostream>
#include <cstdlib>
#include <cassert>
#include <set>
#include <limits>
#include <vector>

using namespace std;

template <class Item>
class graph
{
public:
	static const size_t MAX = 20;

	// constructor
	graph() : many_vertices(0) {}
	void add_vertex(const Item& label);
	void add_edge(size_t source, size_t target, Item data);
	void remove_edge(size_t source, size_t target);
	Item& operator[](size_t vertex);
	size_t size() { return many_vertices; }
	Item is_edge(size_t source, size_t target);
	set<size_t> neighbors(size_t vertex);
	void shortestPath(size_t start);

private:
	Item edges[MAX][MAX];
	Item labels[MAX];
	size_t many_vertices;



};
/*
	function that finds and prints all the shortest paths and
	distances from the start vertex to every other vertex
	in the graph using Dijkstra’s algorithm.

	The output should look like the following
	(assuming there are 5 vertices in a graph and vertex 3 is the start vertex):
	From vertex 3,
	the shortest path to vertex 0 is 3, 1, 2, 0 with distance 15.
	the shortest path to vertex 1 is 3, 1 with distance 3.
	the shortest path to vertex 2 is 3, 1, 2 with distance 8.
	the shortest path to vertex 3 is EMPTY with distance 0.
	the shortest path to vertex 4 is 3, 4 with distance 11.
*/
template<class Item>
void graph<Item>::shortestPath(size_t start)
{
	set<size_t> allowed_vertices;
	set<size_t> neighbor;

	set<size_t>::iterator vit;
	Item distance[MAX];
	vector<size_t> path[MAX];
	size_t now = start;
	size_t next = start;


	assert(start < size());

	// setting all label to infinity
	for (int i = 0; i < many_vertices; i++)
	{
		distance[i] = numeric_limits<Item>::infinity();
		path[i].push_back(start);
	}
	distance[start] = 0;
	allowed_vertices.insert(start);

	for (int i = 0; i < (many_vertices-1); i++)
	{

		neighbor = neighbors(now);
		Item temp = 0;
		Item min = numeric_limits<Item>::infinity();

		if ( !neighbor.empty() )
		{
			set<size_t>::iterator it = neighbor.begin();

			do
			{
				temp = is_edge(now, *it);


				if (distance[*it] > (distance[now] + temp))
				{
					distance[*it] = (distance[now] + temp);
					path[*it] = path[now];
					path[*it].push_back(*it);
				}


			} while (++it != neighbor.end());

		}


		for (int j = 0; j < many_vertices; j++)
		{
			if (std::find(allowed_vertices.begin(), allowed_vertices.end(), j) != allowed_vertices.end())
				continue;
			if (min > distance[j])
			{
				min = distance[j];
				now = j;
			}
		}

		allowed_vertices.insert(now);


	}

	cout << "From vertex " << start << "," << endl;
	for (int i = 0; i < many_vertices ; i++)
	{
		vector<size_t>::iterator it;
		cout << "the shortest path to vertex " << i << " is ";
		for (it = path[i].begin(); it != path[i].end(); it++)
		{
			if (path[i].size() == 1)
			{
				cout << "EMPTY";
				continue;
			}
			if (it != path[i].begin())
				cout << ", " << *it;
			else
				cout << *it;
		}
		cout << " with distance " << distance[i] << ".\n";
	}
	
}

template<class Item>
Item& graph<Item>::operator[](size_t vertext)
{
	assert(vertex < size());
	return labels[vertex];
}

template<class Item>
void graph<Item>::add_vertex(const Item& label)
{
	size_t new_vertex_number;
	size_t vertex;
	assert(size() < MAX);
	new_vertex_number = many_vertices;
	++many_vertices;
	for (vertex = 0; vertex < many_vertices; ++vertex)
	{	// 대각선은 자기 자신이니까 false 
		edges[vertex][new_vertex_number] = false;
		edges[new_vertex_number][vertex] = false;
	}
	labels[new_vertex_number] = label;
}

template<class Item>
void graph<Item>::add_edge(size_t source, size_t target, Item data)
{
	assert(source < size());
	assert(target < size());
	edges[source][target] = data;
}

template<class Item>
Item graph<Item>::is_edge(size_t source, size_t target)
{
	assert(source < size());
	assert(target < size());
	return edges[source][target];
}

template <class Item>
set<size_t> graph<Item>::neighbors(size_t vertex)
{
	set<size_t> answer;
	size_t i;
	assert(vertex < size());
	for (i = 0; i < size(); ++i) {
		if (edges[vertex][i])
			answer.insert(i);
	}
	return answer;
}

template <class Item>
void  graph<Item>::remove_edge(std::size_t  source, std::size_t  target)
{
	assert(source < size());
	assert(target < size());
	edges[source][target] = false;
}