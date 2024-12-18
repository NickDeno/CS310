#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]){
    while(true){ 
        string input;	   
        vector <string> params; 
        cout << "Enter a Menu Option" << endl;
        cout << "Command 1: song <songid> <song-artist> <song-duration> <song-title>" << endl;
        cout << "Command 2: remove <song-title>" << endl;
        cout << "Command 3: listen <song-title> <seconds>" << endl;
        cout << "Command 4: favorite" << endl;
        cout << "Command 5: show_listen_time" << endl;
        cout << "Command 6: quit" << endl;
        
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
            int id = stoi(params[1]);
            string artist = params[2];
            string title = params[4];

        } else if (params[0] == "remove" && params.size() >= 2) {
            //Ignore extra parameters
            if(params.size() > 2){
                cout << "Ignoring commands: ";
                for (int i = 2; i < params.size(); ++i) {
                    cout << params[i] << " ";
                }
                cout << endl;
            }
            string title = params[1];
            cout << "Removed " << title << " from your songs" << endl;

        } else if (params[0] == "listen" && params.size() >= 3) {
            //Ignore extra parameters
            if(params.size() > 3){
                cout << "Ignoring commands: ";
                for (int i = 3; i < params.size(); ++i) {
                    cout << params[i] << " ";
                }
                cout << endl;
            }
            //Checks if listen seconds is integer
            try {
                stoi(params[2]);
            } catch (const std::exception& e){
                cout << "The seconds entered is not a positive number. Please try again." << endl;
                continue;
            }

            string title = params[1];
            int seconds = stoi(params[2]);
            cout << "Listened to " << title << " for " << seconds << " seconds." << endl;  

        } else if (params[0] == "favorite"){
        
        } else if (params[0] == "show_listen_time"){

        } else {
            cout << "Command not recognized, please try again." << endl << endl;
        }
    }
}