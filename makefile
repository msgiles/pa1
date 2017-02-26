CC = g++
CFLAGS = 
RM = -rm -f

tests: rand_graph.o heap.o
	$(CC) $(CFLAGS) rand_graph.o heap.o tests.cpp -o tests

rand_graph.o: heap.o rand_graph.cpp rand_graph.h
	$(CC) $(CFLAGS) rand_graph.cpp heap.o -o rand_graph.o

heap.o: heap.cpp heap.h
	$(CC) $(CFLAGS) heap.cpp -o heap.o

clean:
	$(RM) tests *.o

randmst:
	$(CC) heap.cpp rand_graph.cpp main.cpp -o randmst