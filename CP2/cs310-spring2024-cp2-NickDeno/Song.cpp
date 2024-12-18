#include "Song.h"

Song::Song(int id, string title, int duration, string artist) {
    this->id = id;
    this->title = title;
    this->duration = duration;
    this->artist = artist;
}

Song::Song() {
    id = 0;
    title = "Unknown";
    duration = 0;
    artist = "Unknown";
}

Song::Song(const Song& secSong) {
    id = secSong.id;
    title = secSong.title;
    duration = secSong.duration;
    artist = secSong.artist;
}

Song& Song::operator=(const Song& secSong) {
    if (this != &secSong) {
        id = secSong.id;
        title = secSong.title;
        duration = secSong.duration;
        artist = secSong.artist;
    }
    return *this;
}

Song::~Song() {

}

void Song::SetId(int id){
    this->id = id;
}
      
void Song::SetTitle(std::string title){
    this->title = title;
}
      
void Song::SetDuration(int duration){
    this->duration = duration;
}
      
void Song::SetArtist(std::string artist){
    this->artist = artist;
}

int Song::GetId() const {
    return id;
}

string Song::GetTitle() const {
    return title;
}

int Song::GetDuration() const {
    return duration;
}

string Song::GetArtist() const {
    return artist;
}

void Song::Show() {
    cout << "ID: " << id << endl;
    cout << "Title: " << title << endl;
    cout << "Duration: " << duration << " seconds" << endl;
    cout << "Artist: " << artist << endl;
}