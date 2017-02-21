#ifndef rand_graph
#define rand_graph

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

int INFTY = 2;

matrix rand_mtrx(int n) // Returns random nxn adjacency matrix with real-valued edge weights [0,1]
{
	srand(time(NULL));
	matrix M(n, std::vector<float>(n));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n - i; j++){
			if(!(i==j)){
				float v = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
				cout << v << endl;
				M[i][j] = v;
			}
			else{
				M[i][j] = INFTY;
			}
		};
	};
	return M;
}

matrix rand_points(int n, int d) // Returns random n-array of d-dimensional random points
{
	srand(time(NULL));
	matrix A(n, std::vector<float>(d));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < d; j++){
			A[i][j] = INFTY;
		};
	};
	return A;
}