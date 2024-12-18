#ifndef HEAP_H
#define HEAP_H
#include<iostream>
#include "Array.h"
#include "Song.h"

using namespace std;
class Heap{
    private:
        Array<Song*> arr;     
    public:
        Song* extractMax();   
        int perlocateDown(int index);
        int perlocateUp(int index); 
        int insertNode(Song* song);
        void deleteNode(int index);
        int updateNode(int index, int listenTime);      
};
#endif