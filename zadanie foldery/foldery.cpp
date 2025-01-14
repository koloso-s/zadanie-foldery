#include <iostream>
#include "foldery.h"
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