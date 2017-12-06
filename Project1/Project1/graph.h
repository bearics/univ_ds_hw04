#pragma once

#include <iostream>
#include <cstddef>
#include <set>

using namespace std;

template <class Item>
class graph
{
public:
	static const size_t MAX = 20;

	// constructor
	graph() : many_vertices(0) {}

private:
	Item edges[MAX][MAX];
	Item labels[MAX];
	size_t many_vertices;

	void add_vertex(const Item& label);
	void add_edge(size_t source, size_t target, Item data);
	void remove_edge(size_t source, size_t target);
	Item& operator[](size_t vertex);
	size_t size() { return many_vertices;   }
	Item is_edge(size_t source, size_t target) const;
	set<size_t> neighbors(size_t vertex) const;
	void shortestPath(size_t start);

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
void graph<Item>::add_edge(size_t source, size_t target, Item data )
{
	assert(source < size());
	assert(target < size());
	edges[source][target] = data;
}

template<class Item>
Item graph<Item>::is_edge(size_t source, size_t target) const
{
	assert(source < size());
	assert(target < size());
	return edges[source][target];
}

template <class Item>
set<size_t> graph<Item>::neighbors(size_t vertex) const
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