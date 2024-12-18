#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <vector>
#include "CommandManager.h"
using namespace std;

bool isNumber(const string &s) {
	if (isspace(s[0]) || isalpha(s[0]))
		return false;
	char *p;
	strtod(s.c_str(), &p);
	return (*p == 0);
}

int main(int argc, char *argv[]) {
	CommandManager commandManager;
	while(true){ 
        string input;	   
        vector <string> commands; 
        cout << "Enter [\"song <songid> <artist> <duration> <title>\"" << endl
			 << "       \"remove <title>\"" << endl
			 << "       \"listen <title> <seconds>\"" << endl
			 << "       \"favorite\"" << endl
			 << "       \"show_listen_time\"" << endl
			 << "       \"quit\"]" << endl;
		cout << ": ";
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
                commands.push_back(qoutedWord);
            }else{
                commands.push_back(input);
            }
        }
		
		bool isInvalid = true;
		// Add Song
		// Command: song 1 "Michael Jackson" 1000 "Smooth Criminal"
		if (!commands[0].compare("song") && (commands.size() > 3)) {
			isInvalid = false;
			if (isNumber(commands[1])) {
				if (isNumber(commands[3])) {
					Song* song = new Song(stoi(commands[1]), commands[2], stoi(commands[3]), commands[4]);
					commandManager.addSong(*song);
				} else {
					cout << "Error: arg3: " << commands[3] << " is not a valid duration" << endl;
				}
			} else {
				cout << "Error: arg1: " << commands[1] << " is not a valid songid" << endl;
			}
			
		}

		// Remove Songs
		// Command: remove "Diamonds on the Souls of Her Shoes"
		if (!commands[0].compare("remove") && (commands.size() > 1)) {
			isInvalid = false;
			commandManager.removeSong(commands[1]);
		}

		// Listen
		// Command: listen "Diamonds on the Souls of her Shoes" 1000
		if (!commands[0].compare("listen") && (commands.size() > 2)) {
			isInvalid = false;
			if (isNumber(commands[2])) {
				commandManager.listenSong(commands[1], stoi(commands[2]));
			} else {
				cout << "Error: arg2: " << commands[2] << " is not a valid listening time" << endl;
			}
		}

		// Favorite
		if (!commands[0].compare("favorite") && (commands.size() > 0)) {
			isInvalid = false;
			commandManager.favoriteSong();
		}

		// Show Listen Time
		if (!commands[0].compare("show_listen_time") && (commands.size() > 0)) {
			isInvalid = false;
			commandManager.showListenTime();
		}

		// Not Recognized Commands
		if (isInvalid)
			cout << "Command not recognized, please try again." << endl;
	}
}
