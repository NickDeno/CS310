#pragma once
#include <iostream>
#include <stdlib.h>
using namespace std;

class Song {
   public:
      Song(string title, unsigned int year, string artist_p);
      Song();
      void show();

   private:
      string songTitle = "";
      unsigned int releaseYear = 0;
      string artist = "";
};