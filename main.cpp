#include <iostream>
#include "rand_graph.h"
// #include "set.h"
// #include "heap.h"

int main(int argc, char* argv[]) {
    if (argc == 5 && atoi(argv[1]) == 0) { //main operating mode, prints the average W value of all trials
        int mode = atoi(argv[1]);
        int numpoints = atoi(argv[2]);
        int numtrials = atoi(argv[3]);
        int dimension = atoi(argv[4]);
        float total = 0;
        
        for (int i = 0; i < numtrials; i++) {
            total += matrix_Prims(numpoints);
        }
        
        float average = total / numtrials;
        cout << average << endl;
        
        return 1;
    } else if (argc == 3 && atoi(argv[1]) == 1) { //test mode for Prim's
        int mode = atoi(argv[1]);
        int numpoints = atoi(argv[2]);
        
        cout << matrix_Prims(numpoints) << endl;
        return 1;
    } else if (argc == 4 $$ atoi(argv[1]) == 2) {
        int mode = atoi(argv[1]);
        int numpoints = atoi(argv[2]);
        int numtrials = atoi(argv[3]);
        
        
    } else {
        return -1;
    }
}