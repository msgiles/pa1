#include <iostream>
#include "rand_graph.h"
// #include "set.h"
// #include "heap.h"

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

	Elt e1 = Elt::Elt(2, .45);
	Elt e2 = Elt::Elt(3, .23);
	Elt e3 = Elt::Elt(1, .85);

	Elt array[] = {e1, e2, e3};

	std::vector<float> vec;

	vec.push_back(.85);
	vec.push_back(.23);
	vec.push_back(.45);
	// MinHeap a;

	MinHeap a(array, 3);

	a.print();

	MinHeap	b(vec);

	// b.print();

	// b.decreasekey(1, .15);

	// b.print();

	// for (int i = 0; i < 3; i++){
	// 	Elt temp = b.deletemin();
	// 	b.print();
	// }

	// matrix_Prims(5);

	// matrix M = rand_matrix(4);
	// cout << M[0][0] << endl;
	// for(int i = 0; i < 4; i++){
	// 	for(int j = 0; j < 4 - i; j++){
	// 		cout << M[i][j];
	// 	};
	// 	cout << endl;
	// };

    return 0;

}