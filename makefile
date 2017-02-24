CC = g++
CFLAGS = 
RM = -rm -f

tests: rand_graph.cpp heap.cpp
	$(CC) $(CFLAGS) rand_graph.cpp heap.cpp tests.cpp -o tests

# rand_graph.o: heap.o rand_graph.cpp rand_graph.h
# 	$(CC) $(CFLAGS) rand_graph.cpp heap.o -o rand_graph.o

# heap.o: heap.cpp heap.h
# 	$(CC) $(CFLAGS) heap.cpp -o heap.o

clean:
	$(RM) tests *.o

