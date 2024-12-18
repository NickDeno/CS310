#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include "Song.h"
#include "PlaylistCollection.h"
using namespace std;

PlaylistCollection collection;

int main(int argc, char *argv[]){
    while(true){ 
        string input;	   
        vector <string> params; 
        cout << "Enter a Menu Option" << endl;
        cout << "Command 1: song <songid> <artist> <duration> <title>" << endl;
        cout << "Command 2: remove <songid>" << endl;
        cout << "Command 3: playlist <playlistid> <name>" << endl;
        cout << "Command 4: add <songid> <playlistid>" << endl;
        cout << "Command 5: drop <songid> <playlistid>" << endl;
        cout << "Command 6: seesong <songid>" << endl;
        cout << "Command 7: seeplaylist <playlistid>" << endl;
        cout << "Command 8: deleteplaylist <playlistid>" << endl;
        cout << "Command 9: copyplaylist <playlist id> <new playlist id> <new playlist name>" << endl;
        cout << "Command 10: renameplaylist <playlist id> <new playlist name>" << endl;
        cout << "Command 11: quit" << endl;
        
        getline(cin, input);
        if(input == "quit" || input.length() <= 0) break;
        stringstream inputStream(input);
        while(inputStream >> input){
            if(input.front() == '"') {
                string qoutedWord = input;
                if(input.back() != '"'){
                    while(inputStream >> input){
                        qoutedWord += " " + input;
                        if(input.back() == '"')
                            break;
                    }
                }
                qoutedWord = qoutedWord.substr(1, qoutedWord.size() - 2);
                params.push_back(qoutedWord);
            }else{
                params.push_back(input);
            }
        }

        if (params[0] == "song" && params.size() >= 5) {
            //If extra commands, display commands being ignored
            if(params.size() > 5){
                cout << "Ignoring commands: ";
                for (int i = 5; i < params.size(); ++i) {
                    cout << params[i] << " ";
                }
                cout << endl;
            }
            //Checks if songid is integer
            try {
                stoi(params[1]);
            } catch (const std::exception& e){
                cout << "Song id " << params[1] << " is not an integer" << endl;
                continue;
            }
            //Checks if song duration is integer
            try{ 
                stoi(params[3]);
            } catch (const std::exception& e){
                cout << "The duration of " << params[3] << " is not a valid number. Please try again" << endl;
                continue;
            }
            //Checks if song duration is valid (> 0)
            int duration = stoi(params[3]);
            if(duration < 0){
                 cout << "The duration entered is not a positive number. Please try again." << endl;
                 continue;    
            }
            
            int id = stoi(params[1]);
            string artist = params[2];
            string title = params[4];
            Song newSong(id, title, duration, artist);
            collection.AddSong(newSong);
        }
        else if (params[0] == "remove" && params.size() >= 2) {
            //Ignore extra parameters
            if(params.size() > 2){
                cout << "Ignoring commands: ";
                for (int i = 2; i < params.size(); ++i) {
                    cout << params[i] << " ";
                }
                cout << endl;
            }
            //Checks if songid is integer
            try {
                stoi(params[1]);
            } catch (const std::exception& e){
                cout << "Song id " << params[1] << " is not an integer" << endl;
                continue;
            }
            
            int id = stoi(params[1]);
            cout << "Removing song " << id << endl;
            collection.RemoveSong(id);
        }
        else if (params[0] == "playlist" && params.size() >= 3) {
            //Ignore extra parameters
            if(params.size() > 3){
                cout << "Ignoring commands: ";
                for (int i = 3; i < params.size(); ++i) {
                    cout << params[i] << " ";
                }
                cout << endl;
            }
            //Checks if songid is integer
            try {
                stoi(params[1]);
            } catch (const std::exception& e){
                cout << "Song id " << params[1] << " is not an integer" << endl;
                continue;
            }

            int id = stoi(params[1]);
            string name = params[2];
            collection.AddPlaylist(id, name);
        }
        else if (params[0] == "add" && params.size() >= 3) {
            //Ignore extra parameters
            if(params.size() > 3){
                cout << "Ignoring commands: ";
                for (int i = 3; i < params.size(); ++i) {
                    cout << params[i] << " ";
                }
                cout << endl;
            }
            //Check if songid is integer
            try {
                stoi(params[1]);
            } catch (const std::exception& e){
                cout << "Song id " << params[1] << " is not an integer" << endl;
                continue;
            }
            //Check if playlistid is integer
            try {
                stoi(params[2]);
            } catch (const std::exception& e){
                cout << "Playlist id " << params[1] << " is not an integer" << endl;
                continue;
            }
            int songid = stoi(params[1]);
            int playlistid = stoi(params[2]);
            collection.AddSongToPlaylist(songid, playlistid);
        }
        else  if (params[0] == "drop" && params.size() >= 3) {
            //Ignore extra parameters
            if(params.size() > 3){
                cout << "Ignoring commands: ";
                for (int i = 3; i < params.size(); ++i) {
                    cout << params[i] << " ";
                }
                cout << endl;
            }
            //Check if songid is integer
            try {
                stoi(params[1]);
            } catch (const std::exception& e){
                cout << "Song id " << params[1] << " is not an integer" << endl;
                continue;
            }
            //Check if playlistid is integer
            try {
                stoi(params[2]);
            } catch (const std::exception& e){
                cout << "Playlist id " << params[1] << " is not an integer" << endl;
                continue;
            }
            
            int songId = stoi(params[1]);
            int playlistId = stoi(params[2]);
            cout << "remove song " << params[1] << " from playlist " << params[2] << endl;
            collection.RemoveSongFromPlaylist(songId, playlistId);
        }
        else if (params[0] == "seesong" && params.size() >= 2) {
            //Ignore extra parameters
            if(params.size() > 3){
                cout << "Ignoring commands: ";
                for (int i = 3; i < params.size(); ++i) {
                    cout << params[i] << " ";
                }
                cout << endl;
            }
            //Check if songid is integer
            try {
                stoi(params[1]);
            } catch (const std::exception& e){
                cout << "Song id " << params[1] << " is not an integer" << endl;
                continue;
            }

            int id = stoi(params[1]);
            collection.SeeSong(id);
        }
        else if (params[0] ==  "seeplaylist" && params.size() >= 2) {
            //Ignore extra parameters
            if(params.size() > 3){
                cout << "Ignoring commands: ";
                for (int i = 3; i < params.size(); ++i) {
                    cout << params[i] << " ";
                }
                cout << endl;
            }
            //Check if songid is integer
            try {
                stoi(params[1]);
            } catch (const std::exception& e){
                cout << "Song id " << params[1] << " is not an integer" << endl;
                continue;
            }
            int id = stoi(params[1]);
            collection.SeePlaylist(id);
        }
        else if (params[0] ==  "deleteplaylist" && params.size() >= 2) {
            //Ignore extra parameters
            if(params.size() > 3){
                cout << "Ignoring commands: ";
                for (int i = 3; i < params.size(); ++i) {
                    cout << params[i] << " ";
                }
                cout << endl;
            }
            //Check if songid is integer
            try {
                stoi(params[1]);
            } catch (const std::exception& e){
                cout << "Song id " << params[1] << " is not an integer" << endl;
                continue;
            }
            int id = stoi(params[1]);
            collection.RemovePlaylist(id);   
        }
        else if (params[0] ==  "copyplaylist" && params.size() >= 4) {
            //Ignore extra parameters
            if(params.size() > 4){
                cout << "Ignoring commands: ";
                for (int i = 3; i < params.size(); ++i) {
                    cout << params[i] << " ";
                }
                cout << endl;
            }
            //Check if playlistid1 is integer
            try {
                stoi(params[1]);
            } catch (const std::exception& e){
                cout << "Song id " << params[1] << " is not an integer" << endl;
                continue;
            }
            //Check if playlistid2 is integer
            try {
                stoi(params[2]);
            } catch (const std::exception& e){
                cout << "Song id " << params[1] << " is not an integer" << endl;
                continue;
            }
            int id1 = stoi(params[1]);
            int id2 = stoi(params[2]);
            string newName = params[3];
            collection.CopyPlaylist(id1, id2, newName);
        }
        else if (params[0] ==  "renameplaylist" && params.size() >= 3) {
            //Ignore extra parameters
            if(params.size() > 3){
                cout << "Ignoring commands: ";
                for (int i = 3; i < params.size(); ++i) {
                    cout << params[i] << " ";
                }
                cout << endl;
            }
            //Check if playlistid is integer
            try {
                stoi(params[1]);
            } catch (const std::exception& e){
                cout << "Song id " << params[1] << " is not an integer" << endl;
                continue;
            }

            int id = stoi(params[1]);
            string newName = params[2];
            collection.RenamePlaylist(id, newName);
        }
        else {
            cout << "Command not recognized, please try again." << endl << endl;
        }
    }
}