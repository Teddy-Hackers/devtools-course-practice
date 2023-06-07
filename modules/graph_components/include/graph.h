// Copyright Simeunovic Aleksandar 2023

#include<iostream>
#include<unordered_map>
#include<list>
#include<utility>

class Graph {
public:
	Graph();
	Graph(bool** matrix_adjacency, uint64_t num_of_nodes);
	Graph(const std::unordered_map<int, std::list<int>>& adjacency_map, uint64_t num_of_nodes);
private:
	std::unordered_map<int, std::list<int>> adjacency_map;
	uint64_t __num_of_nodes;
};