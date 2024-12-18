#include "Song.h"

Song::~Song(){
    delete bstPointer; 
}

Song::Song(int id, string artist, int duration, string title){
    this->id = id;
    this->artist = artist;
    this->duration = duration;
    this->title = title;
    this->heapIndex = -1;
    this->listenTime = 0;
    this->favorited = false;
    this->bstPointer = nullptr;
    this->isRemoved = false;
}

Song::Song() {
    id = 0;
    title = "Unknown";
    duration = 0;
    artist = "Unknown";
    heapIndex = -1;
    listenTime = 0;
    favorited = false;
    bstPointer = nullptr;
    isRemoved = false;
}

Song& Song::operator=(Song& other) {
    if (this != &other) { 
        id = other.id;
        title = other.title;
        duration = other.duration;
        artist = other.artist;
        heapIndex = other.heapIndex;
        listenTime = other.listenTime;
        favorited = other.favorited;
        bstPointer = other.bstPointer;
        isRemoved = other.isRemoved;
    }
    return *this;
}

bool Song::operator>(Song& other){
    return id > other.id;
}

bool Song::operator<(Song& other){
    return id < other.id;
}

bool Song::operator==(Song& other){
    if(id == other.id &&
        title == other.title &&
        duration == other.duration &&
        artist == other.artist &&
        heapIndex == other.heapIndex && 
        listenTime == other.listenTime &&
        favorited == other.favorited &&
        bstPointer == other.bstPointer &&
        isRemoved == other.isRemoved) {
            return true;
        }
    return false;
}

void Song::setId(int id){
    this->id = id;
}

int Song::getId() const {
    return id; 
};

string Song::getTitle() const {
    return title;
}

void Song::Show() {
    cout << "ID: " << id << endl;
    cout << "Title: " << title << endl;
    cout << "Duration: " << duration << " seconds" << endl;
    cout << "Artist: " << artist << endl;
    cout << "Favorited: " << favorited << endl;
    cout << "Listen Time: " << listenTime << " seconds" << endl;
}