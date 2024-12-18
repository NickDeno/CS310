#include "CommandManager.h"
#include "BST.h"
#include "Heap.h"
BST songBST;
Heap listenTimeHeap;
//Efficiency Requirements:
//listen must work in O(log N) time where N is the number of songs <- CommandManager::listenSong()
//favorite must work in O(log N) time <- CommandManager::favoriteSong()
//remove must work in O(log N) time <- CommandManager::removeSong()
//song and show_listen_time should all work in O(N) time <- CommandManager::addSong() and CommanderManager::showListenTime()

CommandManager::CommandManager() {}
bool CommandManager::addSong(Song& song){ 	
    //Checks if id is already in use by another song (no duplicate ids aloud). O(N)
	for (int i = 0; i < songs.size(); i++) {
		if (songs.at(i).getId() == song.getId()){
            cout << "song id " << song.getId() << " already used for " << songs.at(i).title << " by " << songs.at(i).artist << endl;
            return false;
        }
	}

    //Inserts song into song-id-orderd-list in correct ordered position,
    //i.e all songs before it have smaller id, and all songs after it have
    //greater id. Then finds the index it was inserted at, and stores in index. O(N)
	int index = songs.insert(song);

    //Inserts song into BST. When song is inserted, we also pass the index of where
    //the song is located in song-id-ordered-list. The "arrayIndex" field of the newly inserted
    //song node is set to this index. O(log(n))
    songs.at(index).bstPointer = songBST.insert(song.title, index);

    //Vice versa, the pointer that points to the location
    //of the song node in the BST is set to the songs "bstPointer" field, essentially linking
    //the song in the song-id-ordered-list and the BST together. O(log(n))
	songBST.search(song.title)->arrayIndex = index;

    //Inserts song into heap using heaps insertNode function, which adds song to end of heap,
    //then percolates up based on listen time. O(log(n))
    songs.at(index).heapIndex = listenTimeHeap.insertNode(&songs.at(index));

    cout << "new song " << song.getId() << " " << song.title << " by " << song.artist << " " << song.duration / 60 << ":" << song.duration % 60 << endl;
	return true; 

    //Overall time complexity of function = O(N)
}

bool CommandManager::removeSong(string title){
    //Finds song to remove by first searching for song node in BST. O(log(n))
    Node* songNode = songBST.search(title);
    if(songNode != nullptr) {
        //Uses array index stored in node to find song in 
        //song-ordered-id-list. O(1)
        Song* removeSong = &songs.at(songNode->arrayIndex);

        //Removes song from heap using heap index
        //stored in song object. Have to chck if still in heap
        //because if song to be removed is favorited, it was already
        //removed from the heap when it was favorited. O(log(n))
        if(removeSong->heapIndex != -1){
            listenTimeHeap.deleteNode(removeSong->heapIndex);
            removeSong->heapIndex = -1;    
        }

        //Removes song from BST. O(log(n))
        songBST.remove(removeSong->title);
        removeSong->bstPointer = nullptr;

        //"Removes" song from song-id-ordered list by setting its 
        //"isRemoved" field to true, and setting its id = -1,
        //so its old id can be used in the future. O(1)
        removeSong->isRemoved = true;
        removeSong->setId(-1);

        if(removeSong->favorited){
            cout << "Removed " << title << " from your favorites" << endl;
        } else {
            cout << "Removed " << title << " from your songs" << endl;
        }
        return true;
    }
    cout << "song " << title << " was not found" << endl;
    return false;

    //Overall time complexity of function = O(log(n))
}

bool CommandManager::listenSong(string title, int listenTime){
    //Finds song to listen by first searching for song node in BST. O(log(n))
    Node* songNode = songBST.search(title);
    if (songNode == nullptr) {
        cout << "Song with title " << title << " does not exist" << endl;
        return false;

    //If song is already favorited, we do not update listen time
    } else if(songs.at(songNode->arrayIndex).favorited){
 		cout << title << " is already a favorite." << endl;
		return false;
	}
	
    //Using songNode, we can get the index of the song we want to lsiten to
    //by accessing its arrayIndex field, and getting the song in the array at
    //that index. O(1)
    Song* song = &songs.at(songNode->arrayIndex);

    //Update the heap node that contains the songs listen time with new listen time. 
    //This is accomplished using heapIndex store in song. O(log(n)) 
    int newListenTime = song->listenTime + listenTime;
    song->heapIndex = listenTimeHeap.updateNode(song->heapIndex, newListenTime);
    cout << "Listened to " << song->title << " for " << song->listenTime << " seconds" << endl;
    return true;    

    //Overall time complexity of function = O(log(n))
}

void CommandManager::favoriteSong(){
    //Extracts/removes max song from heap, which is song with most listen time,
    //this is the song that gets favorited. O(log(n))	
	Song* favoritedSong = listenTimeHeap.extractMax();
    if(favoritedSong == nullptr){
        cout << "No song to favorite" << endl;
        return;
    }

    //Sets favorited field of song to true to indicate is a favorited song, and sets heapIndex field
    //to -1, since after song is favorited its removed from the heap, so we discard its old index. However
    //if we directly set these fields in the song pointer that was extracetd from heap, we wont see these
    //changes reflected in the song-id-ordered-list. To accomplish this in O(log(n)) time, we
    //can use the BST as an inbetween, by taking the favorited songs title, searching for it in the bst O(log(n)), 
    //then taking the arrayIndex field in the BST node, and getting the actual song in song-id-ordered-list with arrayIndex O(1) ,
    //then updating the favorited and heapIndex field there. O(log(n)
    // favoritedSong->favorited = true;
    // favoritedSong->heapIndex = -1;
    Song* songArrayPtr = &songs.at(songBST.search(favoritedSong->title)->arrayIndex);
    songArrayPtr->favorited = true;
    songArrayPtr->heapIndex = -1;
	cout << "Song " << favoritedSong->title << " added to list of favorites (Listend for " << favoritedSong->listenTime << " seconds)" << endl;

    //Overall time compexity of function = O(log(n))
}

void CommandManager::showListenTime(){
    //Loops through song-id-ordered-list, and displays all songs and listen time
    //O(n)
	for(int i = 0; i < songs.size(); i ++){
		if(!songs.at(i).isRemoved){
		    cout<< songs.at(i).getId()<< " " << songs.at(i).title << " has been listened to for " << songs.at(i).listenTime << " seconds " << endl;
		}
    }

    //Overall time complexity of function = O(n)
}


