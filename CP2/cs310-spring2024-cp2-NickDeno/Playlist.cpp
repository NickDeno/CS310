#include "Playlist.h"
using namespace std;

Playlist::Playlist(){
    numSongs = 0;
    size = 0;
    songs = nullptr;
}

Playlist::Playlist(const Playlist& secPlaylist){
    name = secPlaylist.name;
    size = secPlaylist.size;
    numSongs = secPlaylist.numSongs;
    songs = new Song[size];
    for(int i = 0; i < numSongs; i++){
        songs[i] = secPlaylist.songs[i];
    }
}

Playlist& Playlist::operator=(const Playlist& secPlaylist){
    if (this != &secPlaylist) {
        name = secPlaylist.name;
        size = secPlaylist.size;
        numSongs = secPlaylist.numSongs; 
        delete[] songs;

        songs = new Song[size];
        for(int i = 0; i < numSongs; i++){
            songs[i] = secPlaylist.songs[i];
        }
    }
    return *this;
} 

Playlist::~Playlist(){
    delete[] songs;
}

void Playlist::AddSong(const Song& song){
    if(numSongs == size){
        int newSize = 0;
        if(size == 0) newSize = 1;
        else newSize = size * 2;

        Song* newSongs = new Song[newSize];
        for(int i = 0; i < numSongs; i++){
            newSongs[i] = songs[i];
        }

        delete[] songs;
        songs = newSongs;
        size = newSize;
    }
    int insertIndex = numSongs;
    for (int i = 0; i < numSongs; ++i) {
        if (songs[i].GetId() > song.GetId()) {
            insertIndex = i;
            break;
        }
    }
    
    for (int i = numSongs; i > insertIndex; --i) {
        songs[i] = songs[i - 1];
    }
    songs[insertIndex] = song;
    ++numSongs;
}

void Playlist::RemoveSong(int id) {
    for (int i = 0; i < numSongs; ++i) {
        if (songs[i].GetId() == id) {
            for (int j = i; j < numSongs - 1; ++j) {
                songs[j] = songs[j + 1];
            }
            --numSongs;
            return;
        }
    }
}

bool Playlist::HasSong(int id) const {
    for (int i = 0; i < numSongs; ++i) {
        if (songs[i].GetId() == id) {
            return true;
        }
    }
    return false;
};

Song* Playlist::FindSong(int id) {
    for(int i = 0; i < numSongs; ++i) {
        if (songs[i].GetId() == id) {
            return &songs[i];
        }
    }
    return nullptr;
};

void Playlist::Show() {
    cout << "Number of Songs: " << numSongs << endl;
    for(int i = 0; i < numSongs; i++){
        songs[i].Show();
    }
    
}

void Playlist::SetName(string name){
    this->name = name;
}

string Playlist::GetName() const{
    return name;
}

int Playlist::GetSize() const {
    return size;
}

Song Playlist::GetSong(int i) const {
    if (i < 0 || i > numSongs) {
        throw std::out_of_range("Index out of range");
    }
    return songs[i];
}

