#include "heap.h"
#include <assert.h>
#include <iostream>

using namespace std;

Edge::Edge(vertex v, float dist){
	vert = v;
	distance = dist;
}

float Edge::get_dist(){
	return distance;
}

void Edge::print(){
	std::cout << vert << ": " << distance;
	std::cout << endl;
}

MinHeap::MinHeap(Edge* array, int length){
	keys.reserve(length);
    for(int i = 0; i < length; ++i){
        keys.push_back(array[i]);
    }

    make_heap();
}

MinHeap::MinHeap(const std::vector<Edge>& vector) : keys(vector){
    make_heap();
}

MinHeap::MinHeap(){
}

void MinHeap::make_heap(){
    int length = keys.size();
    for(int i=length-1; i>=0; --i)
    {
        bubble_down(i);
    }
}

void MinHeap::insert(Edge item){
    cout << "Inserting ";
    item.print();
	int len = keys.size();
	keys[len] = item;
	MinHeap::bubble_up(keys.size() - 1);
	return;
}

Edge MinHeap::deletemin(){
	int len = keys.size();
	assert(len != 0);
   	Edge val = keys[0];
    keys[0] = keys[len-1];
   	keys.pop_back();
    bubble_down(0);
    cout << "Deleting ";
    val.print();
    return val;
}

void MinHeap::print(){
	int size = keys.size();
	for (int i = 0; i < size; i++){
		Edge current = keys[i];
		current.print();
	}
}

void MinHeap::bubble_down(int idx){
    int len = keys.size();
    int lChildIdx = 2*idx + 1;
    int rChildIdx = 2*idx + 2;

    if(lChildIdx >= len)
        return; //index is a leaf

    int minIdx = idx;

    if(keys[idx].get_dist() > keys[lChildIdx].get_dist()){
        minIdx = lChildIdx;
    }
    
    if((rChildIdx < len) && (keys[minIdx].get_dist() > keys[rChildIdx].get_dist())){
        minIdx = rChildIdx;
    }

    if(minIdx != idx){
        //need to swap
        Edge tmp = keys[idx];
        keys[idx] = keys[minIdx];
        keys[minIdx] = tmp;
        bubble_down(minIdx);
    }
}

void MinHeap::bubble_up(int idx){
    if(idx == 0)
        return;

    int parentIdx = (idx-1)/2;

    if(keys[parentIdx].get_dist() > keys[idx].get_dist()){
       	Edge tmp = keys[parentIdx];
        keys[parentIdx] = keys[idx];
        keys[idx] = tmp;
        bubble_up(parentIdx);
    }
}

bool MinHeap::isempty(){
    return keys.size() == 0;
}