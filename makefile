tests: heap.o 
	g++ -Wall heap.o tests.cpp -o tests

heap.o: heap.cpp heap.h
	g++ -Wall -c heap.cpp

# clean:
#     \rm *.o