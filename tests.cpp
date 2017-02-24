#include <iostream>
#include "rand_graph.h"
// #include "set.h"
#include "heap.h"

int main(void){
	// matrix M = rand_mtrx(3);
	// cout << M[0][0] << endl;
	// for(int i = 0; i < 3; i++){
	// 	for(int j = 0; j < 3 - i; j++){
	// 		cout << M[i][j];
	// 	};
	// 	cout << endl;
	// };
	// Set u = MAKESET(3);
	// Set v = MAKESET(5);
	// Set *w = UNION(&u, &v);
	// return 0;

	Edge e1 = Edge::Edge(2, .45);
	Edge e2 = Edge::Edge(3, .23);
	Edge e3 = Edge::Edge(1, .85);

	Edge array[] = {e1, e2, e3};

	for (int i = 0; i < 3; i++){
		array[i].print();
	}

	MinHeap a;

	MinHeap	b(array, 3);

	// if (a.isempty()){
	// 	cout << "Empty!" << endl;
	// 	b.print();
	// }
	// else{
	// 	cout << "Uh oh" << endl;
	// 	b.print();
	// }

	for (int i = 0; i < 3; i++){
		Edge temp = b.deletemin();
		b.print();
	}

	matrix M = rand_matrix(4);
	cout << M[0][0] << endl;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4 - i; j++){
			cout << M[i][j];
		};
		cout << endl;
	};

    return 0;

}