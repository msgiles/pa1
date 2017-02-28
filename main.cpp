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
        float total = 0.0;
        
        for (int i = 0; i < numtrials; i++) {
            total += euclid_Prims(numpoints, dimension);
        }
        
        float average = total / numtrials;
        cout << average << " " << numpoints << " " << numtrials << " " << dimension << endl;
        
        return 1;
    } else if (argc == 3 && atoi(argv[1]) == 1) { //test mode for Prim's
        int mode = atoi(argv[1]);
        int numpoints = atoi(argv[2]);
        
        cout << matrix_Prims(numpoints) << endl;
        return 1;
    } else if (argc == 5 && atoi(argv[1]) == 2) { //trial mode to determine longest edge in MST (for k(n))
        int mode = atoi(argv[1]);
        int numpoints = atoi(argv[2]);
        int numtrials = atoi(argv[3]);
        int dimension = atoi(argv[4]);
        float max = 0.0;
        
        for (int i = 0; i < numtrials; i++) {
            float currentMax = euclid_Prims_Longest_Edge(numpoints, dimension);
            
            if (currentMax > max) {
                max = currentMax;
            }
            cout << currentMax << endl;
        }
        
        cout << "maximum: " << max << endl;
        
        return 1;
    } else if (argc == 4 && atoi(argv[1]) == 2) {
        int mode = atoi(argv[1]);
        int numpoints = atoi(argv[2]);
        int numtrials = atoi(argv[3]);
        float max = 0.0;
        
        for (int i = 0; i < numtrials; i++) {
            float currentMax = matrix_Prims_Longest_Edge(numpoints);
            
            if (currentMax > max) {
                max = currentMax;
            }
            cout << currentMax << endl;
        }
        
        cout << "maximum: " << max << endl;
        
        return 1;
    } else {
        return -1;
    }
}