#ifndef RAND_GRAPH_H
#define RAND_GRAPH_H
#include "heap.h"

typedef std::vector< std::vector<float> > matrix;

const int INFTY = 2;

class AdjMatrix
{
public:
	AdjMatrix(int n);
	float access(vertex m, vertex n);
private:
	matrix data;
};

matrix rand_matrix(int n);

float access_matrix(vertex v1, vertex v2);

float matrix_Prims(int n);

matrix rand_npoints(int n, int d);

float euclid_distance(std::vector<float> p1, std::vector<float> p2);

float euclid_Prims(int n, int d);
#endif