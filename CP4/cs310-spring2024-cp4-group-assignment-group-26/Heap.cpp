#include "Heap.h"

Song* Heap::extractMax(){
    if (arr.size() == 0) {
         return nullptr;
    }
    Song* maxSong = arr.at(0); 
    // Replace the root of the heap with the last element
    arr.at(0) = arr.at(arr.size()-1);
    arr.at(0)->heapIndex = 0;
    
    // Remove the last element
    arr.remove(arr.size()-1); 
    if (arr.size() != 0) {
        arr.at(0)->heapIndex = 0;
        perlocateDown(0);
    }
   return maxSong;
}

int Heap::perlocateDown(int nodeIndex) {
    //Calculate left child index, if index is out of bounds, 
    //=> no children, return the current index
    int childIndex = 2 * nodeIndex + 1;
    if(childIndex > arr.size()){
        return nodeIndex;
    }

   int listenTime = arr.at(nodeIndex)->listenTime;
   int maxListenTime = listenTime;
   int maxListenTimeIndex = -1;
   //Find index of child with the max listen time
   for (int i = 0; i < 2 && i + childIndex < arr.size(); i++) {
        if (arr.at(i + childIndex)->listenTime > maxListenTime) {
            maxListenTime = arr.at(i + childIndex)->listenTime;
            maxListenTimeIndex = i + childIndex;
        }
   }

    //Max listen time found is > current nodes listen time,
    //=> node is in correct position, return index
    if (maxListenTime == listenTime) {
        return nodeIndex;
    //Max listen time found is < current nodes listen time,
    //=> swap current node with child that has max listne time
    } else {  
        Song* temp = arr.at(nodeIndex);
        arr.at(nodeIndex) = arr.at(maxListenTimeIndex);
        arr.at(maxListenTimeIndex) = temp;
        arr.at(nodeIndex)->heapIndex = nodeIndex;
        arr.at(maxListenTimeIndex)->heapIndex = maxListenTimeIndex;
        nodeIndex = perlocateDown(childIndex);
        return nodeIndex;
   }
}

int Heap::perlocateUp(int nodeIndex) {
    //If current nodes listen time <= parents listen time, or
    //if current node is root, return current index
    int parentIndex = (nodeIndex - 1) / 2;
    if (arr.at(nodeIndex)->listenTime <= arr.at(parentIndex)->listenTime || nodeIndex <= 0)
        return nodeIndex;
    //Current nodes listen time > parent listen time, => swap
    else {
        Song* temp = arr.at(nodeIndex);
        arr.at(nodeIndex) = arr.at(parentIndex);
        arr.at(parentIndex) = temp;
        arr.at(nodeIndex)->heapIndex = nodeIndex;
        nodeIndex = perlocateUp(parentIndex);
    }
    return nodeIndex;
}

int Heap::insertNode(Song* song){
    //Inserts new node to end of heap, then percolates node up to 
    //ensure new nodes listen time is greater then parents listen time
    arr.insert(song);
    return perlocateUp(arr.size()-1);
}

void Heap::deleteNode(int index){
    //Replace node to be deleted with last element in heap, then
    //remove the last element in array
    arr.at(index) = arr.at(arr.size()-1);
    arr.remove(arr.size()-1);
    //If heap is empty after deletion, return. Else percolateDown
    //to preserve max heap
    if(arr.size()== 0){
        return;
    }
    perlocateDown(index);
    return;
}

int Heap::updateNode(int index, int newListenTime) {
    if (index < 0 || index >= arr.size()){
        return index;
    }
    //Check if new listen time is > current listen time, if so
    //=> update listen time and percolate up to preserve max heap
    if (arr.at(index)->listenTime < newListenTime) {
        arr.at(index)->listenTime = newListenTime;
        return perlocateUp(index);
    }
    //Check if new listen time is < current listen time, if so
    //=> update listen time and percolate down to preserve max heap
    if (arr.at(index)->listenTime > newListenTime) {
        arr.at(index)->listenTime = newListenTime;
        return perlocateDown(index);
    }
    return index;
}


