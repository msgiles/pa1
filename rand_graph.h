#ifndef RAND_GRAPH_H
#define RAND_GRAPH_H

typedef std::vector< std::vector<float> > matrix;

int INFTY;

matrix rand_matrix(int n);

matrix rand_npoints(int n, int d);

#endif