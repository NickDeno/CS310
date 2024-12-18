#include "PlaylistCollection.h"
using namespace std;

PlaylistCollection::PlaylistCollection(){}


void PlaylistCollection::AddSong(const Song& song){
    if(globalSongs.HasSong(song.GetId())){
        cout << "Song ID " << song.GetId() << " already used for " << song.GetTitle() << " by " << song.GetArtist() << endl;
    } else {
        globalSongs.AddSong(song);
        cout << "new song " << song.GetId() <<  " by " << song.GetArtist() << " " << song.GetDuration() / 60 << ":" << song.GetDuration() % 60 << endl;
    }
}

void PlaylistCollection::AddPlaylist(int id, const string& name) {
    if (playlists.count(id) > 0){
        cout << "Playlist with id" << id << " already exists" << endl;
    } else {
        Playlist playlist;
        playlist.SetName(name);
        playlists[id] = playlist;
        cout << "New playlist " << id << " called " << name << endl;
    }
}

void PlaylistCollection::AddSongToPlaylist(int songId, int playlistId){
    if (!globalSongs.HasSong(songId)) {
        cout << "Song " << songId << " does not exist" << endl;
    } else if (playlists.find(playlistId) == playlists.end()) {
        cout << "Playlist " << playlistId << " does not exist" << endl;
    } else if(playlists[playlistId].HasSong(songId)){
        cout << "Song " << songId  << " is already in playlist " << playlistId << endl;
    } else {
        playlists[playlistId].AddSong(*globalSongs.FindSong(songId));
        cout << "Add song " << songId << " to playlist " << playlistId << endl;
    }
}

void PlaylistCollection::RemoveSong(int id){
    if (globalSongs.HasSong(id)) {
        Song* tempSong = globalSongs.FindSong(id);
        cout << "Song " << tempSong->GetId() << ", " << tempSong->GetTitle() << " by " << tempSong->GetArtist() << ", removed" << endl;
        globalSongs.RemoveSong(id);

        for (auto& playlist : playlists) {
            if (playlist.second.HasSong(id)) {
                playlist.second.RemoveSong(id);
            }
        }
    } else {
        cout << "Song " << id << " not found." << endl;
    }
}

void PlaylistCollection::RemovePlaylist(int id) {
    if (playlists.count(id)) {
        playlists.erase(id);
        cout << "Playlist " << id << " successfully deleted" << endl;
    } else {
        cout << "Playlist " << id << " does not exist" << endl;
    }
}

void PlaylistCollection::RemoveSongFromPlaylist(int songId,int playlistId){
    if (playlists.count(playlistId)) {
        if(playlists[playlistId].HasSong(songId)){
            playlists[playlistId].RemoveSong(songId);
            cout << "Song " << songId << " successfully dropped from playlist " << playlistId << endl;
        }else {
            cout << "Song " << songId << " is not in playlist " << playlistId << endl;
        } 
    } else {
        cout << "Playlist " << playlistId << " does not exist." << endl;
    }    
}

void PlaylistCollection::SeeSong(int id){
    if(globalSongs.HasSong(id)){
        Song* temp = globalSongs.FindSong(id);
        cout << "Song " << temp->GetId() << " " << temp->GetTitle() << " by " << temp->GetArtist() << endl;
    } else {
        cout << "Song " << id << " does not exist" << endl;
    } 
}

void PlaylistCollection::SeePlaylist(int id){
    auto playlist = playlists.find(id);
    if(playlist == playlists.end()){
        cout << "Playlist " << id << " does not exist" << endl;    
    } else {
        cout << "Songs in playlist" << id << ":" << endl;
        for (int i = 0; i < playlist->second.GetSize(); ++i) {
            const Song& song = playlist->second.GetSong(i);
            cout << "ID: " << song.GetId() << ", Title: " << song.GetTitle() << ", Artist: " << song.GetArtist() << ", Duration: " << song.GetDuration() << endl;
        }
    }
}

void PlaylistCollection::CopyPlaylist(int id, int newId, string newName){
    if(playlists.count(id)){
        Playlist copyPlaylist(playlists[id]);
        playlists[newId] = copyPlaylist;
        cout << "Playlist " << id << " successfully copied to playlist " << newId << " " << newName << endl;
    } else {
        cout << "Playlist " << id << " does not exist, and cannot be copied" << endl;
    }
}

void PlaylistCollection::RenamePlaylist(int id, string newName){
    if(playlists.count(id)){
        playlists[id].SetName(newName);
        cout << "Playlist " << id << " name successfully changed to " << newName << endl;
    } else {
        cout << "Playlist " << id << " does not exist, and cannot be renamed." << endl;    
    }
}