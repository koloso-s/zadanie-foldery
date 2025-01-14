#include <iostream>
#include "foldery.h"
#include <filesystem>
#include <string>

using namespace std;

namespace fs = std::filesystem;


int main()
{
    folder myFolder("C:\\Users\\werte\\Documents\\lol");
    try
    {
        while (true) {
            string command;
            cout << myFolder.getCurrentPath() << " Wpisz komende: ";
            getline(cin, command);
            if (command == "dir") {
                myFolder.openFolder(command, myFolder.getCurrentPath());
            }
            else if (command.find("cd") != string::npos) {
                string folder = command.substr(command.find_first_of(" ") + 1, command.length());
                if (folder == "..") {
                    myFolder.setCurrentPath(myFolder.getCurrentPath().substr(0, myFolder.getCurrentPath().find_last_of("\\")));
                    cout << myFolder.getCurrentPath() << endl;
                }
                else {
                    myFolder.setCurrentPath(myFolder.getCurrentPath() += "\\" + folder);
                }
            }
            else if (command.find("mkdir") != string::npos) {
                string folder = command.substr(command.find_first_of(" ") + 1, command.length());
                myFolder.createFolder(myFolder.getCurrentPath(), folder);
            }
            else if (command.find("rmdir") != string::npos) {
                string folder = command.substr(command.find_first_of(" ") + 1, command.length());
                myFolder.removeFolder(myFolder.getCurrentPath(), folder);
            }
            else if (command.find("rename") != string::npos) {
                string folder = command.substr(command.find_first_of(" ") + 1, command.length());
                folder = folder.substr(0, folder.find_first_of(" "));
                string renameName = command.substr(command.find_last_of(" ") + 1, command.length());
                myFolder.renameFolder(myFolder.getCurrentPath(), folder,renameName);
            }
        }
    }
    catch (const std::exception& err)
    {
        cout << err.what() << endl;
    }
}