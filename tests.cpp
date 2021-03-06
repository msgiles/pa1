#include <iostream>
#include "rand_graph.h"
// #include "set.h"
// #include "heap.h"

int main(void){

	// Elt e1 = Elt::Elt(2, .45);
	// Elt e2 = Elt::Elt(3, .23);
	// Elt e3 = Elt::Elt(1, .85);

	// Elt array[] = {e1, e2, e3};



	std::vector<float> vec;

	for (int i = 0; i < 20; i++){
		float v = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		vec.push_back(v);
		cout << v << endl;
	}

	MinHeap	b(vec);

	cout << endl;

	b.print();

	cout << endl;

	MinHeap c = b;

	for (int i = 0; i < 20; i++){
		Elt e = c.deletemin();
		e.print();
		cout << endl;
	}

	Elt e = b.deletemin();

	cout << e.distance << endl;

	b.decreasekey(13, e.distance);

	for (int i = 0; i < 19; i++){
		Elt e = b.deletemin();
		e.print();
		cout << endl;
	}

	// b.print();

	// b.decreasekey(1, .15);

	// b.print();

	// for (int i = 0; i < 3; i++){
	// 	Elt temp = b.deletemin();
	// 	b.print();
	// }
	// cout << euclid_Prims(131072) << endl;
	// cout << euclid_Prims(5, 2) << endl;
	// matrix Ps = rand_points(5,2);

	AdjMatrix M(4, 0);

	// rand_matrix(4, M);
	// cout << M[0][0] << endl;
	// for(int i = 0; i < 4; i++){
	// 	for(int j = 0; j < 4 - i; j++){
	// 		cout << M[i][j] << " ";
	// 	};
	// 	cout << endl;
	// };

	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			cout << M.access(i,j) << " ";
		};
	cout << endl;
	};

    return 0;

}