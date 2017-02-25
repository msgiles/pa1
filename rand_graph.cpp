#include <cstdlib>
#include <ctime>
#include <iostream>
#include "rand_graph.h"

using namespace std;

matrix rand_matrix(int n){ // Returns random nxn adjacency matrix with real-valued edge weights [0,1]
	srand(time(NULL));
	matrix M(n, std::vector<float>(n));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n - i; j++){
			if(!(i==j)){
				float v = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
				// cout << v << endl;
				M[i][j] = v;
			}
			else{
				M[i][j] = INFTY;
			}
		};
		M[i].shrink_to_fit(); // Return extra memory
	};
	return M;
}

float access_matrix(const matrix &M, vertex v1, vertex v2){
	if (v1 > v2){
		return M[v1][v2];
	}
	else{
		return M[v2][v1];
	}
}

float matrix_Prims(int n){  // Generates a random adjacency matrix and runs Prim's Algorithm on it
							// Start node is by default 0
	std::vector<vertex> prev;
	std::vector<float> dist;
	std::vector<bool> visited;
	prev.reserve(n);
	dist.reserve(n);
	visited.reserve(n);

	float W;

	for (int i = 0; i < n; i++){
		dist.push_back(INFTY);
		prev.push_back(-1);
		visited.push_back(false);
	}

	matrix M = rand_matrix(n);

	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4 - i; j++){
			cout << M[i][j] << " ";
		}
		cout << endl;
	}

	vertex s = 0;

	dist[s] = 0;
	prev[s] = 0;

	MinHeap H(dist);

	while(!H.isempty()){
		Elt e = H.deletemin();
		vertex v = e.vert;
		visited[v] = true;
		W += e.distance;
		for (int i = 0; i < n; i++){
			int len = access_matrix(M, i, v);
			if (dist[i] > len && !visited[i]){
				dist[i] = len;
				prev[i] = v;
				H.decreasekey(i, len);
			}

		}
	}
	return W;
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

