// Copyright Simeunovic Aleksandar 2023

#include"include/graph.h"

Graph::Graph(uint64_t num_of_nodes=10) : __num_of_nodes(num_of_nodes) {}

Graph::Graph(bool** matrix_adjacency, uint64_t num_of_nodes) :__num_of_nodes(num_of_nodes) {
	for (int i = 0; i < num_of_nodes; i++) {
		for (int j = i; j < num_of_nodes; j++) {
			if (matrix_adjacency[i][j]) {
				adjacency_map[i].push_back(j);
				adjacency_map[j].push_back(i);
			}
		}
	}
}

bool Graph::Has_Edge(uint64_t u, uint64_t w) {
	auto find = std::find(adjacency_map[u].begin(), adjacency_map[u].end(), w);
	return (find != adjacency_map[u].end()) ? true : false;
}

void Graph::Add_Edge(uint64_t u, uint64_t w) {
	if (!Has_Edge(u, w)) {
		adjacency_map[u].push_back(w);
		adjacency_map[w].push_back(u);
	}
}

void Graph::Delete_Edge(uint64_t u, uint64_t w) {
	if (Has_Edge(u, w)) {
		adjacency_map[u].remove(w);
		adjacency_map[w].remove(u);
	}
}