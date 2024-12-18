#include "SongCollection.h"
using namespace std;

SongCollection::SongCollection(){
    numSongs = 0;
}

SongCollection::SongCollection(Song songParam){
    numSongs = 1;
    song = songParam;
}

void SongCollection::show() {
    cout << "Number of Songs: " << numSongs << endl;
    song.show();
    
}

