#ifndef RAND_GRAPH_H
#define RAND_GRAPH_H
#include "heap.h"

typedef std::vector< std::vector<float> > matrix;

class AdjMatrix
{
public:
	AdjMatrix(int n, int d);
	float access(vertex m, vertex n);
private:
	matrix data;
};

float access_matrix(vertex v1, vertex v2);

matrix rand_points(int n, int d);

float euclid_distance(std::vector<float> p1, std::vector<float> p2, int d);

float Prims(int n, int d);

// float matrix_Prims(int n);

// float euclid_Prims(int n, int d);

// float euclid_Prims_Longest_Edge(int n, int d);

// float matrix_Prims_Longest_Edge(int n);
#endif