// Array implementation of binary heap
#include <vector>
using namespace std;

#ifndef HEAP_H
#define HEAP_H

typedef int vertex;

class Edge{
public:
	Edge(vertex vert, float dist);
	float distance;
	vertex vert;
	float get_dist();
	void print();
};

class MinHeap{
private:
	std::vector<Edge> keys;
	void bubble_down(int idx);
	void bubble_up(int idx);
	void make_heap();
public:
	MinHeap();
    MinHeap(Edge* array, int length);
    MinHeap(const std::vector<Edge>& vector);
	void insert(Edge item);
	Edge deletemin();
	void print();
	bool isempty();
};

#endif