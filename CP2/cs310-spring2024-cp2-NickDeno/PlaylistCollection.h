#include "Song.h"
#include <map>
#include "Playlist.h"
#include "Song.h"
using namespace std;

class PlaylistCollection {
    public:
        PlaylistCollection(); 
        void AddSong(const Song& song); 
        void AddPlaylist(int id, const string& name); 
        void AddSongToPlaylist(int songId, int playlistId);

        void RemoveSong(int id); 
        void RemovePlaylist(int id);
        void RemoveSongFromPlaylist(int songId,int playlistId);

        void SeeSong(int id);
        void SeePlaylist(int id);
        void CopyPlaylist(int id, int newId, string newName);
        void RenamePlaylist(int id, string newName);
    private:
        Playlist globalSongs; 
        //Keeps track of created playlists, the key
        map<int, Playlist> playlists; 
};