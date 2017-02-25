// Array implementation of binary heap
#include <vector>
using namespace std;

#ifndef HEAP_H
#define HEAP_H

typedef int vertex;

class Elt{
public:
	Elt(vertex vert, float dist);
	float distance;
	vertex vert;
	float get_dist();
	void print();
};

class MinHeap{
private:
	std::vector<Elt> keys;
	std::vector<vertex> map;
	void bubble_down(int idx);
	void bubble_up(int idx);
	void make_heap();
public:
	MinHeap();
    MinHeap(Elt* array, int length);
    MinHeap(std::vector<float> vector);
	void insert(Elt item);
	Elt deletemin();
	void decreasekey(vertex v, float val);
	void print();
	bool isempty();
};

#endif