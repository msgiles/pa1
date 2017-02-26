#include <cstdlib>
#include <ctime>
#include <iostream>
#include "rand_graph.h"

using namespace std;

matrix rand_matrix(int n){ // Returns half of a random nxn matrix
	srand(time(NULL));
	matrix M(n, std::vector<float>(n));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n - i; j++){
			float v = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
			M[i][j] = v;
		}
		M[i].shrink_to_fit(); // Return extra memory
	}
	return M;
}

AdjMatrix::AdjMatrix(int n){
	data = rand_matrix(n-1);
}

float AdjMatrix::access(vertex m, vertex n){
	if (m == n){
		return INFTY;
	}
	else if (n < m){
		return data[n][m-n-1];
	}
	else{
		return data[m][n-m-1];
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

	AdjMatrix M(n);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << M.access(i, j) << " ";
		}
		cout << endl;
	}

	vertex s = 0;

	dist[s] = 0;
	prev[s] = 0;

	MinHeap H(dist);

	while(!H.isempty()){
		Elt e = H.deletemin();
		e.print();
		vertex v = e.vert;
		visited[v] = true;
		W += e.distance;
		cout << W << endl;
		for (int i = 0; i < n; i++){
			float len = M.access(i,v);
			if (dist[i] > len && !visited[i]){
				cout << i << " -> " << len << endl;
				dist[i] = len;
				prev[i] = v;
				H.decreasekey(i, len);
			}

		}
	}
	cout << endl;
	for (int i = 0; i < dist.size(); i++){
			cout << dist[i] << endl;
		}
		cout << endl;
		for (int i = 0; i < prev.size(); i++){
			cout << prev[i]<<endl;
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
