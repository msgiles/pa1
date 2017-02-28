#include "heap.h"
#include <assert.h>
#include <iostream>

using namespace std;

int HEAP_SIZE = 0;

Elt::Elt(vertex v, float dist){
	vert = v;
	distance = dist;
}

Elt::Elt(){
    vert = -1;
    distance = INFTY;
}

float Elt::get_dist(){
	return distance;
}

void Elt::print(){
	std::cout << vert << ": " << distance;
	std::cout << endl;
}

MinHeap::MinHeap(Elt* array, int length){
	keys.resize(length);
    map.resize(length);
    for(int i = 0; i < length; ++i){
        keys[i] = array[i];
        map[i] = -1;
    }
    for(int i = 0; i < length; ++i){
        Elt e = keys[i];
        map[e.vert] = i;
    }
    make_heap();
}

MinHeap::MinHeap(std::vector<float> dists){
    // cout << "Loading Arrays..." << endl;
    int len = dists.size();
    HEAP_SIZE = len;
    cout << HEAP_SIZE;
    keys.resize(len);
    map.resize(len);
    for (int i = 0; i < len; ++i){
        Elt e(i, dists.at(i));
        keys[i] = e;
        map[i] =i;
    }
    // cout << "Arrays Loaded!" << endl;
    make_heap();
}

MinHeap::MinHeap(){
}

void MinHeap::make_heap(){
    //cout << "Making Heap" << endl;
    int length = keys.size();
    for(int i=length-1; i>=0; --i)
    {
        bubble_down(i);
    }
}

void MinHeap::insert(Elt item){
    HEAP_SIZE ++;
	int len = keys.size();
	keys[len] = item;
    map[item.vert] = len;
	MinHeap::bubble_up(keys.size() - 1);
	return;
}

Elt MinHeap::deletemin(){
	int len = keys.size();
	assert(len != 0);
   	Elt val = keys[0];
    keys[0] = keys[len-1];
   	keys.pop_back();
    bubble_down(0);
    --HEAP_SIZE;
    if (HEAP_SIZE % 1000 == 0){
        cout << HEAP_SIZE << endl;
        cout << val.distance << endl;
    }
    return val;
}

void MinHeap::decreasekey(vertex v, float val){
    int dest = map[v];
    assert(v < map.size());
    cout << keys[dest].vert << ": " << keys[dest].distance << "-> " << v << ": " << val << endl;
    if (dest != -1){
        keys[dest].distance = val;
        bubble_up(dest);
        return;
    }
    else{
        return;
    }
}

void MinHeap::print(){
	int size = keys.size();
	for (int i = 0; i < size; i++){
		Elt current = keys[i];
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
        Elt tmp = keys[idx];
        map[keys[minIdx].vert] = idx;
        map[tmp.vert] = minIdx; 
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
       	Elt tmp = keys[parentIdx];
        map[keys[parentIdx].vert] = idx;
        map[tmp.vert] = parentIdx;
        keys[parentIdx] = keys[idx];
        keys[idx] = tmp;
        bubble_up(parentIdx);
    }
}

bool MinHeap::isempty(){
    return keys.size() == 0;
}