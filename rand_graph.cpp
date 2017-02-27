#include <cstdlib>
#include <math.h>
#include <ctime>
#include <iostream>
#include "rand_graph.h"

using namespace std;

void rand_matrix(int n, matrix &M){ // Returns half of a random nxn matrix
	// srand(time(NULL));
	cout << "Initializing Matrix..." << endl;
	cout << "Resizing Outer Vector..." << endl;
	M.resize(n);
	for(int i = 0; i < n; i++){
		if (i % 10000 == 0){
			cout << "Resizing Inner: " << i << endl;
			cout << "Generating Values..." << endl;
		}
		M[i].resize(n-i);
		for(int j = 0; j < n - i; j++){
			float v = (float) (rand()) / (float) (RAND_MAX);
			M[i][j] = v;
		}
	}
	cout << "Returning Matrix" << endl;
}

AdjMatrix::AdjMatrix(int n){
	rand_matrix(n-1, data);
}

AdjMatrix::AdjMatrix(int n, int d){
	matrix Ps = rand_points(n, d);
	matrix A;
	A.resize(n - 1);
	for(int i = 0; i < n-1; i++){
		A[i].resize(n - i - 1);
		for(int j = 0; j < n - i-1; j++){
			A[i][j] = euclid_distance(Ps[i], Ps[j+i+1], d);
		}
		// M[i].shrink_to_fit(); // Return extra memory
	}
	data = A;
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
	// std::vector<vertex> prev;
	std::vector<float> dist;
	std::vector<bool> visited;
	// prev.reserve(n);
	dist.reserve(n);
	visited.reserve(n);

	float W = 0.0;

	for (int i = 0; i < n; i++){
		dist.push_back(INFTY);
		// prev.push_back(-1);
		visited.push_back(false);
	}
	cout << "Making Adjacency Matrix..." << endl;
	AdjMatrix M(n);
	cout << "Adjacency Matrix Made!" << endl;

	// for(int i = 0; i < n; i++){
	// 	for(int j = 0; j < n; j++){
	// 		cout << M.access(i, j) << " ";
	// 	}
	// 	cout << endl;
	// }

	vertex s = 0;

	dist[s] = 0;
	// prev[s] = 0;

	cout << "Making Heap" << endl;
	MinHeap H(dist);
	cout << "Heap Made!" << endl;

	while(!H.isempty()){
		Elt e = H.deletemin();
		// e.print();
		vertex v = e.vert;
		visited[v] = true;
		W += e.distance;
		// cout << W << endl;
		for (int i = 0; i < n; i++){
			float len = M.access(i,v);
			if (dist[i] > len && !visited[i]){
				// cout << i << " -> " << len << endl;
				dist[i] = len;
				// prev[i] = v;
				H.decreasekey(i, len);
			}

		}
	}
	// cout << endl;
	// for (int i = 0; i < dist.size(); i++){
	// 		cout << dist[i] << endl;
	// 	}
	// 	cout << endl;
	// 	for (int i = 0; i < prev.size(); i++){
	// 		cout << prev[i]<<endl;
	// 	}
	return W;
}

matrix rand_points(int n, int d) // Returns random n-array of d-dimensional random points
{
	// srand(time(NULL));
	matrix A(n, std::vector<float>(d));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < d; j++){
			float v = (float) (rand()) / (float) (RAND_MAX);
			A[i][j] = v;
		};
	};
	return A;
}

float euclid_distance(std::vector<float> p1, std::vector<float> p2, int d){
	float res = 0.0;
	for (int i = 0; i < d; i++){
		res += pow((p1[i] - p2[i]),2);
	}
	return sqrt(res);
}

float euclid_Prims(int n, int d){
	// std::vector<vertex> prev;
	std::vector<float> dist;
	std::vector<bool> visited;
	// prev.reserve(n);
	dist.reserve(n);
	visited.reserve(n);

	float W = 0.0;
	AdjMatrix M(n, d);

	// for (int i = 0; i<n; i++){
	// 	cout << "{";
	// 	for (int j = 0; j < d; j++){
	// 		cout << Ps[i][j];
	// 		if (j < d-1){
	// 			cout << ", ";
	// 		}
	// 	}
	// 	cout << "}," << endl;
	// }

	for (int i = 0; i < n; i++){
		dist.push_back(INFTY);
		// prev.push_back(-1);
		visited.push_back(false);
	}

	vertex s = 0;

	dist[s] = 0;
	// prev[s] = 0;

	MinHeap H(dist);

	while(!H.isempty()){
		Elt e = H.deletemin();
		// e.print();
		vertex v = e.vert;
		visited[v] = true;
		W += e.distance;
		// cout << W << endl;
		for (int i = 0; i < n; i++){
			float len = M.access(i,v);
			if (dist[i] > len && !visited[i]){
				dist[i] = len;
				// prev[i] = v;
				H.decreasekey(i, len);
			}

		}
	}
	// cout << endl;
	// for (int i = 0; i < dist.size(); i++){
	// 	cout << dist[i] << endl;
	// }
	// cout << endl;
	// for (int i = 0; i < prev.size(); i++){
	// 	cout << prev[i]<<endl;
	// }
	return W;
}

float euclid_Prims_Longest_Edge(int n, int d){ //identical method, returns the longest edge for testing purposes
    // std::vector<vertex> prev;
    std::vector<float> dist;
    std::vector<bool> visited;
    // prev.reserve(n);
    dist.reserve(n);
    visited.reserve(n);
    
    float W = 0.0;
    float longestEdge = 0.0;
    matrix Ps = rand_points(n, d);
    
    // for (int i = 0; i<n; i++){
    // 	cout << "{";
    // 	for (int j = 0; j < d; j++){
    // 		cout << Ps[i][j];
    // 		if (j < d-1){
    // 			cout << ", ";
    // 		}
    // 	}
    // 	cout << "}," << endl;
    // }
    
    for (int i = 0; i < n; i++){
        dist.push_back(INFTY);
        // prev.push_back(-1);
        visited.push_back(false);
    }
    
    vertex s = 0;
    
    dist[s] = 0;
    // prev[s] = 0;
    
    MinHeap H(dist);
    
    while(!H.isempty()){
        Elt e = H.deletemin();
        // e.print();
        vertex v = e.vert;
        visited[v] = true;
        if (e.distance > longestEdge) {
            longestEdge = e.distance;
        }
        W += e.distance;
        // cout << W << endl;
        for (int i = 0; i < n; i++){
            float len = euclid_distance(Ps[i], Ps[v], d);
            if (dist[i] > len && !visited[i]){
                dist[i] = len;
                // prev[i] = v;
                H.decreasekey(i, len);
            }
            
        }
    }
    // cout << endl;
    // for (int i = 0; i < dist.size(); i++){
    // 	cout << dist[i] << endl;
    // }
    // cout << endl;
    // for (int i = 0; i < prev.size(); i++){
    // 	cout << prev[i]<<endl;
    // }
    return longestEdge;
}