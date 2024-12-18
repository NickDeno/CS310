#ifndef SONGDB_H
#define SONGDB_H

#include <iostream>
#include <vector>
#include "Song.h"
#include "Array.h"
#include "BST.h"
#include "Heap.h"
using namespace std;

class CommandManager{
    private:
        Array<Song> songs;
    public:
        CommandManager();
        bool addSong(Song &song);
		bool removeSong(string title);
		bool listenSong(string title, int listenTitme);
		void favoriteSong();
		void showListenTime(); 
};



#endif