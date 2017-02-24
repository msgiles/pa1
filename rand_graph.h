#ifndef RAND_GRAPH_H
#define RAND_GRAPH_H
#include "heap.h"

typedef std::vector< std::vector<float> > matrix;

const int INFTY = 2;

matrix rand_matrix(int n);

float access_weight(vertex v1, vertex v2);

matrix matrix_Prims(int n);

matrix rand_npoints(int n, int d);

#endif