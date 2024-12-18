#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

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
        cout << "Command 8: quit" << endl;

        getline(cin, input);
        if(input == "quit" || input.length() <= 0) break;

        stringstream inputStream(input);
        string param;
        while(inputStream >> param) {
            params.push_back(param);
        }
        if (params[0] == "song" && params.size() >= 5) {
            try{
                int duration = stoi(params[3]);
                if(duration >= 0){
                    int minutes = duration / 60;
                    int seconds = duration % 60;
                    cout << "new song " << params[4] <<  " by " << params[2] << " " << minutes << ":" << seconds << endl << endl;
                } else {
                    cout << "The duration entered is not a positive number. Please try again." << endl << endl;
                }
            } catch(const std::exception& e){
                cout << "The duration entered is not a valid number. Please try again" << endl << endl;
            }      
        }
        else if (params[0] == "remove" && params.size() >= 2) {
            cout << "removing song " << params[1] << endl << endl;
        }
        else if (params[0] == "playlist" && params.size() >= 3) {
            cout << "new playlist " << params[1] << " called " << params[2] << endl << endl;
        }
        else if (params[0] == "add" && params.size() >= 3) {
            cout << "add song " << params[1] << " to playlist " << params[2] << endl << endl;
        }
        else  if (params[0] == "drop" && params.size() >= 3) {
            cout << "remove song " << params[1] << " from playlist " << params[2] << endl << endl;
        }
        else if (params[0] == "seesong" && params.size() >= 2) {
            cout << "song " << params[1] << endl << endl;
        }
        else if (params[0] ==  "seeplaylist" && params.size() >= 2) {
            cout << "Songs in playlist " << params[1] << endl << endl;
        }
        else {
            cout << "Command not recognized, please try again." << endl << endl;
        }
    }
}