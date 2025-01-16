#include <iostream>
#include "foldery.h"
#include <filesystem>
#include <string>

using namespace std;

namespace fs = std::filesystem;


int main()
{
    cout << "Podaj sciezke bazowa:" << endl;
    string initPath;
    getline(cin, initPath);
    folder myFolder(initPath);
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
            else if (command.find("help") != string::npos) {
                cout << "dir - wyswietl zawartosc folderu\n" << endl;
                cout << "cd <nazwa_folderu> - przejdz do folderu\n" << endl;
                cout << "cd .. - wroc do nadrzednego folderu\n" << endl;
                cout << "mkdir <nazwa_folderu> - utworz folder\n" << endl;
                cout << "rmdir <nazwa_folderu> - usun folder\n" << endl;
                cout << "rename <nazwa_folderu1> <nazwa_folderu2> - zmien nazwe folderu\n" << endl;
            }
            else if (command.find("copy") != string::npos) {
                
                string source = command.substr(command.find_first_of(" ") + 1, command.length());
                source = source.substr(0, source.find_first_of(" "));
                string dest = command.substr(command.find_last_of(" ") + 1, command.length());
                if (source == dest) cout << "Źródło musi być inne od ścieżki docelowej" << endl;
                else myFolder.copy(source, dest);
            }
        }
    }
    catch (const std::exception& err)
    {
        cout << err.what() << endl;
    }
}