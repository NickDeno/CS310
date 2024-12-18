#ifndef SONG_H
#define SONG_H
#include <string>
#include <iostream>
#include "Node.h"
using namespace std;

class Song {
public:
  Song(int id, string artist, int duration, string title);
  Song();
  ~Song();
  Song& operator=(Song& other);
  bool operator==(Song& other);
  bool operator>(Song& other);
  bool operator<(Song& other);
  void setId(int id);
  int getId() const;
  string getTitle() const;
  void Show();

  int id;
  string artist;
  int duration;
  string title;
  int listenTime;
  bool favorited;

  int heapIndex;
  Node* bstPointer;
  bool isRemoved;
};
#endif
