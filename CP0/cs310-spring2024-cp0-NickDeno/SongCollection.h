#include "Song.h"
class SongCollection{
    public:
        SongCollection();
        SongCollection(Song songParam);
        void show();
    private:
        int numSongs;
        Song song;
};