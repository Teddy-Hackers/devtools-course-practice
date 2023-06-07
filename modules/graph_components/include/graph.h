// Copyright Simeunovic Aleksandar 2023

#include<iostream>
#include<unordered_map>
#include<list>
#include<utility>
#define MAXN 1000

class Graph {
public:
	Graph(uint64_t num_of_nodes);
	Graph(bool** matrix_adjacency, uint64_t num_of_nodes);
	Graph(const std::unordered_map<int, std::list<int>>& adjacency_map, uint64_t num_of_nodes);
	void Add_Edge(uint64_t u, uint64_t w);
	void Delete_Edge(uint64_t, uint64_t w);
	bool Has_Edge(uint64_t, uint64_t w);
private:
	std::unordered_map<int, std::list<int>> adjacency_map;
	uint64_t __num_of_nodes;
};