#include <iostream>
#include "foldery.h"
#include <fstream>
#include <filesystem>
namespace fs = std::filesystem;

folder::folder(std::string B_P)
    :BASE_PATH(B_P), current_path(B_P) {

}

std::string folder::getCurrentPath() {
    return this->current_path;
}

void folder::setCurrentPath(std::string currPath) {
    this->current_path = currPath;
}

void folder::openFolder(std::string command, std::string current_path) {
    for (auto& entry : fs::directory_iterator(current_path)) {
        fs::path path = entry.path();
        std::cout << path.filename() << std::endl;
    }
}

void folder::createFolder(std::string current_path, std::string folder_name) {
    fs::path newFolder = current_path + "\\" + folder_name;
    fs::create_directory(newFolder);
}

void folder::removeFolder(std::string current_path, std::string folder_name) {
    fs::path Folder = current_path + "\\" + folder_name;
    fs::remove(Folder);
}

void folder::renameFolder(std::string current_path, std::string folder_name, std::string change_name) {
    std::cout << current_path << std::endl;
    fs::rename(current_path +"\\"+ folder_name, current_path +"\\"+ change_name);
}

void folder::copy(std::string source, std::string dest) {
    std::cout << "startowa sciezka: " << this->getCurrentPath() + "/" + source << std::endl;
    std::cout << "koncowa sciezka: " << this->getCurrentPath() + "/" + dest << std::endl;

    std::ifstream sourceFile(this->getCurrentPath() + "/" + source, std::ios::binary);
    std::ofstream destFile(this->getCurrentPath() + "/" + dest, std::ios::binary);

    if (!(sourceFile.good() && destFile.good())) {
        std::cout << "Blad przy probie odczytu" << std::endl;
        return;
    }

    sourceFile.seekg(0, std::ios::end);
    int fsize = sourceFile.tellg();
    sourceFile.seekg(0);
    char* bufor = new char[fsize];

    sourceFile.read(bufor, fsize);
    destFile.write(bufor, fsize);

    delete[] bufor;
    sourceFile.close();
    destFile.close();
    std::cout << "Pomyslnie skopiowano plik" << std::endl;
}