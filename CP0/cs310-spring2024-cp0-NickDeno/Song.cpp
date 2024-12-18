#include "Song.h"

Song::Song(string title, unsigned int year, string artist_p) {
    songTitle = title;
    releaseYear = year;
    artist = artist_p;
}

Song::Song() {
    songTitle = "";
    releaseYear = 0;
    artist = "";
}

void Song::show() {
    cout << songTitle << " (" << releaseYear << "): " << artist << endl;
}