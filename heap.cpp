#include "heap.h"
#include <assert.h>
#include <iostream>

using namespace std;

Elt::Elt(vertex v, float dist){
	vert = v;
	distance = dist;
}

float Elt::get_dist(){
	return distance;
}

void Elt::print(){
	std::cout << vert << ": " << distance;
	std::cout << endl;
}

MinHeap::MinHeap(Elt* array, int length){
	keys.reserve(length);
    map.reserve(length);
    for(int i = 0; i < length; ++i){
        keys.push_back(array[i]);
        map.push_back(-1);
    }
    for(int i = 0; i < length; ++i){
        Elt e = keys[i];
        map[e.vert] = i;
    }
    make_heap();
}

MinHeap::MinHeap(std::vector<float> dists){
    int len = dists.size();
    keys.reserve(len);
    map.reserve(len);
    for (int i = 0; i < len; ++i){
        Elt e(i, dists.at(i));
        keys.push_back(e);
        map.push_back(i);
    }
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

void MinHeap::insert(Elt item){
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
    return val;
}

void MinHeap::decreasekey(vertex v, float val){
    int dest = map[v];
    assert(v < map.size());
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
        vertex pVert = tmp.vert;
        vertex cVert = keys[minIdx].vert;
        map[cVert] = idx;
        map[pVert] = minIdx;
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
        vertex pVert = tmp.vert;
        vertex cVert = keys[idx].vert;
        map[cVert] = parentIdx;
        map[pVert] = idx;
        keys[parentIdx] = keys[idx];
        keys[idx] = tmp;
        bubble_up(parentIdx);
    }
}

bool MinHeap::isempty(){
    return keys.size() == 0;
}