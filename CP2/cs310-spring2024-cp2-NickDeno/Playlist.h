#include "Song.h"
using namespace std;

class Playlist{
    public:
        Playlist();
        Playlist(const Playlist& other);
        Playlist& operator=(const Playlist& other);
        ~Playlist();

        void AddSong(const Song& song);
        void RemoveSong(int id);
        bool HasSong(int id) const;
        Song* FindSong(int id);
        Song GetSong(int i) const;

        void SetName(string name);
        string GetName() const;
        int GetSize() const;
        void Show();
    private:
        string name;
        int numSongs;
        int size;
        Song* songs;
};