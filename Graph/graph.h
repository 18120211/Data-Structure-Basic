#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <queue>
#include <stack>
#include <functional>
#include "graph.h"
using namespace std;

#define MAX 100
#define oo 1000000000
#define ii pair<int,int>
#define mp make_pair

struct Graph
{
	int num_vertices; // number of vertices
	int adjacency_matrix[MAX][MAX]; // adjacency matrix
	bool free[MAX];
};

Graph CreateGraphFromFile(string file_name); //Hàm tạo đồ thị từ tập tin

bool IsValidGraph(Graph g); //bool IsValidGraph(Graph g)

bool IsUndirectedGraph(Graph g); //bool IsUndirectedGraph(Graph g)

void DisplayGraph(Graph g);//Hàm hiển thị đồ thi

int CountEdge(Graph g); //Đếm số lượng cạnh trong đồ thị:

int CountVertices(Graph g, int flag); //Đếm số lượng đỉnh có yêu cầu

void resetState(Graph g); //

void BFS(Graph g, int start_vertex); //Duyệt đồ thị theo chiều rộng

void DFS(Graph g, int start_vertex); //Duyệt đồ thị theo chiều sâu

int CountConnectedComponents(Graph g); //int CountConnectedComponents(Graph g)

bool IsConnectedGraph(Graph g); //Kiểm tra đồ thị có liên thông không

void FindShortestPathDijkstra(Graph g, int start_vertex); //Theo thuật toán Dijkstra

void FindShortestPathFloyd(Graph g, int start_vertex); //Theo thuật toán Floyd

void FindShortestPathBellman(Graph g, int start_vertex); //Theo thuật toán Bellman

#endif