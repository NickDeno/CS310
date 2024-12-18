#pragma once
#include <iostream>
#include <stdlib.h>
using namespace std;

class Song {
   public:
      Song(int id, string title, int duration, string artist);
      Song();
      Song(const Song& other); 
      Song& operator=(const Song& other);
      ~Song();
      
      void SetId(int id);
      void SetTitle(string title);
      void SetDuration(int duration);
      void SetArtist(string artist);

      int GetId() const;
      string GetTitle() const;
      int GetDuration() const;
      string GetArtist() const;

      void Show();

   private:
      int id;
      string title;
      int duration;
      string artist;
};