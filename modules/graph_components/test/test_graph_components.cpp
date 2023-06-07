// Copyright Simeunovic Aleksandar 2023

#include"include/graph.h"
#include<random>
#include<gtest/gtest.h>

TEST(Simeunovic_Aleksandar_Graph_Components, default_constructor_test) {
	Graph g();
	ASSERT_NO_THROW();
}

TEST(Simeunovic_Aleksandar_Graph_Components, matrix_adjacency_test1) {
	bool** matrix;
	matrix = new bool* [3];
	for (int i = 0; i < 3; i++) {
		matrix[i] = new bool[3];
		for (int j = 0; j < 3; j++) {
			if (i == j)matrix[i][j] = false;
			else matrix[i][j] = true;
		}
	}
	Graph g(matrix, 3);
	ASSERT_NO_THROW();
}

TEST(Simeunovic_Aleksandar_Graph_Components, matrix_adjacency_test2) {
	bool** matrix;
	matrix = new bool* [3];
	for (int i = 0; i < 3; i++) {
		matrix[i] = new bool[3];
		for (int j = 0; j < 3; j++) {
			if (i == j)matrix[i][j] = false;
			else matrix[i][j] = true;
		}
	}
	Graph g(matrix, 3);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i != j)EXPECT_EQ(true, g.Has_Edge(i, j));
		}
	}
}

TEST(Simeunovic_Aleksandar_Graph_Components, matrix_adjacency_test3) {
	std::random_device dev;
	std::mt19937 rand_r(dev());
	uint64_t num_of_nodes = rand_r() % 100;
	bool** matrix;
	matrix = new bool* [num_of_nodes];
	for (int i = 0; i < num_of_nodes; i++) {
		matrix[i] = new bool[num_of_nodes];
		for (int j = i; j < num_of_nodes; j++) {
			if (i == j)matrix[i][j] = false;
			else {
				int num = rand_r() % 2;
				if (num)matrix[i][j] = true;
				else matrix[i][j] = false;
			}
		}
	}
	Graph g(matrix, num_of_nodes);
	for (int i = 0; i < num_of_nodes; i++) {
		for (int j = i; j < num_of_nodes; j++) {
			EXPECT_EQ(matrix[i][j], g.Has_Edge(i, j));
		}
	}
}

TEST(Simeunovic_Aleksandar_Graph_Components, adding_edge) {
	Graph g(5); // There are no edges between any two pair of nodes
	EXPECT_EQ(false, g.Has_Edge(1, 3));
	g.Add_Edge(1, 3);
	EXPECT_EQ(true, g.Has_Edge(1, 3));
	EXPECT_EQ(true, g.Has_Edge(3, 1));
}

TEST(Simeunovic_Aleksandar_Graph_Components, deleting_edge) {
	Graph g(5);
	g.Add_Edge(1, 3);
	EXPECT_EQ(true, g.Has_Edge(1, 3));
	g.Delete_Edge(1, 3);
	EXPECT_EQ(false, g.Has_Edge(1, 3));
	EXPECT_EQ(false, g.Has_Edge(3, 1));
}