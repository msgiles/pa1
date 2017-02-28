#include <cstdlib>
#include <math.h>
#include <ctime>
#include <iostream>
#include "rand_graph.h"

using namespace std;

// Generates half of a symmetric random matrix
void rand_matrix(int n, matrix &M){
	srand(time(NULL));
	M.resize(n);
    float maxEdgeLength = 1.0;  
	for(int i = 0; i < n; i++){
		M[i].resize(n-i);
		for(int j = 0; j < n - i; j++){
			float v = (float) (rand()) / (float) (RAND_MAX);
            
            if (v > maxEdgeLength) {
                M[i][j] = maxEdgeLength;
            } else {
                M[i][j] = v;
            }
		}
	}
}

// Returns random n-array of d-dimensional random points
matrix rand_points(int n, int d)
{
	srand(time(NULL));
	matrix A(n, std::vector<float>(d));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < d; j++){
			float v = (float) (rand()) / (float) (RAND_MAX);
			A[i][j] = v;
		};
	};
	return A;
}

// Finds the distance between two points
float euclid_distance(std::vector<float> p1, std::vector<float> p2, int d){
	float res = 0.0;
	for (int i = 0; i < d; i++){
		res += pow((p1[i] - p2[i]),2);
	}
	return sqrt(res);
}

// Initializes an adjacency matrix for the appropriate
// dimension, pruning if need be
AdjMatrix::AdjMatrix(int n, int d){
	if (d==0){
		cout << "0 dim" << endl;
        rand_matrix(n-1, data);		
	}else{
		cout << "euclidean" << endl;
		matrix Ps = rand_points(n, d);
		data.resize(n - 1);
	    float maxEdgeLength;
	    
	    if (d == 2) {
	        maxEdgeLength = (float)pow(n, -0.4) * 2.5;
	    } else if (d == 3) {
	        maxEdgeLength = (float)pow(n, -0.3) * 2.2;
	    } else if (d == 4) {
	        maxEdgeLength = (float)pow(n, -0.2) * 1.7;
	    } else {
	    	maxEdgeLength = INFTY;
	    }

		for(int i = 0; i < n-1; i++){
			data[i].resize(n - i - 1);
			for(int j = 0; j < n - i-1; j++){
	            float edgeDist = euclid_distance(Ps[i], Ps[j+i+1], d);
	            if (edgeDist > maxEdgeLength) {
	                data[i][j] = maxEdgeLength;
	            } else {
	                data[i][j] = edgeDist;
	            }
			}
		}
	}
}

// Matrix access
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

float Prims(int n, int d){
	// Initialize distance and prev pointer arrays
	std::vector<float> dist;
	std::vector<bool> visited;
	dist.reserve(n);
	visited.reserve(n);

	// Accumulates total weight
	float W = 0.0;

	for (int i = 0; i < n; i++){
		dist.push_back(INFTY);
		visited.push_back(false);
	}

	// Generate Adjacency Matrix
	AdjMatrix M(n, d);

	// Default start vertex
	vertex s = 0;
	dist[s] = 0;

	// Instantiate heap
	MinHeap H(dist);

	while(!H.isempty()){
		Elt e = H.deletemin();
		vertex v = e.vert;
		visited[v] = true;
		W += e.distance;
		// Examine all connections
		for (int i = 0; i < n; i++){
			float len = M.access(i,v);
			if (dist[i] > len && !visited[i]){
				dist[i] = len;
				H.decreasekey(i, len);
			}
		}
	}
	cout << W << endl;
	return W;
}

// float matrix_Prims(int n){  // Generates a random adjacency matrix and runs Prim's Algorithm on it
// 							// Start node is by default 0
// 	// std::vector<vertex> prev;
// 	std::vector<float> dist;
// 	std::vector<bool> visited;
// 	// prev.reserve(n);
// 	dist.reserve(n);
// 	visited.reserve(n);

// 	float W = 0.0;

// 	for (int i = 0; i < n; i++){
// 		dist.push_back(INFTY);
// 		// prev.push_back(-1);
// 		visited.push_back(false);
// 	}
// 	// cout << "Making Adjacency Matrix..." << endl;
// 	AdjMatrix M(n);
// 	// cout << "Adjacency Matrix Made!" << endl;

// 	// for(int i = 0; i < n; i++){
// 	// 	for(int j = 0; j < n; j++){
// 	// 		cout << M.access(i, j) << " ";
// 	// 	}
// 	// 	cout << endl;
// 	// }

// 	vertex s = 0;

// 	dist[s] = 0;
// 	// prev[s] = 0;

// 	// cout << "Making Heap" << endl;
// 	MinHeap H(dist);
// 	// cout << "Heap Made!" << endl;

// 	while(!H.isempty()){
// 		Elt e = H.deletemin();
// 		// e.print();
// 		vertex v = e.vert;
// 		visited[v] = true;
// 		W += e.distance;
// 		// cout << W << endl;
// 		for (int i = 0; i < n; i++){
// 			float len = M.access(i,v);
// 			if (dist[i] > len && !visited[i]){
// 				// cout << i << " -> " << len << endl;
// 				dist[i] = len;
// 				// prev[i] = v;
// 				H.decreasekey(i, len);
// 			}

// 		}
// 	}
// 	// cout << endl;
// 	// for (int i = 0; i < dist.size(); i++){
// 	// 		cout << dist[i] << endl;
// 	// 	}
// 	// 	cout << endl;
// 	// 	for (int i = 0; i < prev.size(); i++){
// 	// 		cout << prev[i]<<endl;
// 	// 	}
// 	return W;
// }

// float euclid_Prims(int n, int d){
// 	// std::vector<vertex> prev;
// 	// cout << "Making Vectors" << endl;
// 	std::vector<float> dist;
// 	std::vector<bool> visited;
// 	// prev.reserve(n);
// 	dist.reserve(n);
// 	visited.reserve(n);
// 	// cout << "Vector Construction Complete" << endl;
// 	float W = 0.0;
// 	// cout << "Making Matrix" << endl;
// 	AdjMatrix M(n, d);
// 	// cout << "Matrix Made" << endl;

// 	// for (int i = 0; i<n; i++){
// 	// 	cout << "{";
// 	// 	for (int j = 0; j < d; j++){
// 	// 		cout << Ps[i][j];
// 	// 		if (j < d-1){
// 	// 			cout << ", ";
// 	// 		}
// 	// 	}
// 	// 	cout << "}," << endl;
// 	// }

// 	for (int i = 0; i < n; i++){
// 		dist.push_back(INFTY);
// 		// prev.push_back(-1);
// 		visited.push_back(false);
// 	}

// 	vertex s = 0;

// 	dist[s] = 0;
// 	// prev[s] = 0;

// 	MinHeap H(dist);

// 	while(!H.isempty()){
// 		Elt e = H.deletemin();
// 		// e.print();
// 		vertex v = e.vert;
// 		visited[v] = true;
// 		W += e.distance;
// 		// cout << W << endl;
// 		for (int i = 0; i < n; i++){
// 			float len = M.access(i,v);
// 			if (dist[i] > len && !visited[i]){
// 				dist[i] = len;
// 				// prev[i] = v;
// 				H.decreasekey(i, len);
// 			}

// 		}
// 	}
// 	// cout << endl;
// 	// for (int i = 0; i < dist.size(); i++){
// 	// 	cout << dist[i] << endl;
// 	// }
// 	// cout << endl;
// 	// for (int i = 0; i < prev.size(); i++){
// 	// 	cout << prev[i]<<endl;
// 	// }
// 	return W;
// }

// float euclid_Prims_Longest_Edge(int n, int d){ //identical method, returns the longest edge for testing purposes
//     // std::vector<vertex> prev;
//     std::vector<float> dist;
//     std::vector<bool> visited;
//     // prev.reserve(n);
//     dist.reserve(n);
//     visited.reserve(n);
    
//     float W = 0.0;
//     float longestEdge = 0.0;
//     matrix Ps = rand_points(n, d);
    
//     // for (int i = 0; i<n; i++){
//     // 	cout << "{";
//     // 	for (int j = 0; j < d; j++){
//     // 		cout << Ps[i][j];
//     // 		if (j < d-1){
//     // 			cout << ", ";
//     // 		}
//     // 	}
//     // 	cout << "}," << endl;
//     // }
    
//     for (int i = 0; i < n; i++){
//         dist.push_back(INFTY);
//         // prev.push_back(-1);
//         visited.push_back(false);
//     }
    
//     vertex s = 0;
    
//     dist[s] = 0;
//     // prev[s] = 0;
    
//     MinHeap H(dist);
    
//     while(!H.isempty()){
//         Elt e = H.deletemin();
//         // e.print();
//         vertex v = e.vert;
//         visited[v] = true;
//         if (e.distance > longestEdge) {
//             longestEdge = e.distance;
//         }
//         W += e.distance;
//         // cout << W << endl;
//         for (int i = 0; i < n; i++){
//             float len = euclid_distance(Ps[i], Ps[v], d);
//             if (dist[i] > len && !visited[i]){
//                 dist[i] = len;
//                 // prev[i] = v;
//                 H.decreasekey(i, len);
//             }
            
//         }
//     }
//     // cout << endl;
//     // for (int i = 0; i < dist.size(); i++){
//     // 	cout << dist[i] << endl;
//     // }
//     // cout << endl;
//     // for (int i = 0; i < prev.size(); i++){
//     // 	cout << prev[i]<<endl;
//     // }
//     return longestEdge;
// }

// float matrix_Prims_Longest_Edge(int n){ //identical method, returns the longest edge for testing purposes
//     // std::vector<vertex> prev;
//     std::vector<float> dist;
//     std::vector<bool> visited;
//     // prev.reserve(n);
//     dist.reserve(n);
//     visited.reserve(n);
    
//     float W = 0.0;
//     float longestEdge = 0.0;
    
//     for (int i = 0; i < n; i++){
//         dist.push_back(INFTY);
//         // prev.push_back(-1);
//         visited.push_back(false);
//     }
//     //cout << "Making Adjacency Matrix..." << endl;
//     AdjMatrix M(n);
//     //cout << "Adjacency Matrix Made!" << endl;
    
//     // for(int i = 0; i < n; i++){
//     // 	for(int j = 0; j < n; j++){
//     // 		cout << M.access(i, j) << " ";
//     // 	}
//     // 	cout << endl;
//     // }
    
//     vertex s = 0;
    
//     dist[s] = 0;
//     // prev[s] = 0;
    
//     //cout << "Making Heap" << endl;
//     MinHeap H(dist);
//     //cout << "Heap Made!" << endl;
    
//     while(!H.isempty()){
//         Elt e = H.deletemin();
//         // e.print();
//         vertex v = e.vert;
//         visited[v] = true;
//         W += e.distance;
//         if (e.distance > longestEdge) {
//             longestEdge = e.distance;
//         }
//         // cout << W << endl;
//         for (int i = 0; i < n; i++){
//             float len = M.access(i,v);
//             if (dist[i] > len && !visited[i]){
//                 // cout << i << " -> " << len << endl;
//                 dist[i] = len;
//                 // prev[i] = v;
//                 H.decreasekey(i, len);
//             }
            
//         }
//     }
//     // cout << endl;
//     // for (int i = 0; i < dist.size(); i++){
//     // 		cout << dist[i] << endl;
//     // 	}
//     // 	cout << endl;
//     // 	for (int i = 0; i < prev.size(); i++){
//     // 		cout << prev[i]<<endl;
//     // 	}
//     return longestEdge;
// }