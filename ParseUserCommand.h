#pragma once

#include "ManagerFunction.h"

//Function of parsing user commands

void parseCommand(const std::string& command) {
    std::istringstream iss(command);
    std::string action;

    if (!(iss >> action)) {
        std::cout << "The command could not be read." << std::endl;
    }

    std::string file1, file2;

    if (action == "create") {
        if (!(iss >> file1)) {
            std::cout << "The file for creation is not specified." << std::endl;
            return;
        } else createFile(file1);
    } else if (action == "remove") {
        if (!(iss >> file1)) {
            std::cout << "The file to remove is not specified." << std::endl;
            return;
        } else removeFile(file1);
    } else if (action == "rename") {
        if (!(iss >> file1 >> file2)) {
            std::cout << "The fie to rename is not specified." << std::endl;
            return;
        } else renameFile(file1, file2);
    } else if (action == "move") {
        if(!(iss >> file1 >> file2)) {
            std::cout << "The file to move is not specified." << std::endl;
            return;
        } else moveFile(file1, file2);
    } else if (action == "copy") {
        if (!(iss >> file1 >> file2)) {
            std::cout << "The file to copy is not specified." << std::endl;
            return;
        } else copyFile(file1, file2);
    } else if (action == "exists") {
        if (!(iss >> file1)) {
            std::cout << "No file specified." << std::endl;
            return;
        } else existsFile(file1);
    } else if (action == "info") {
        if (!(iss >> file1)) {
            std::cout << "The file to getting info is not specified." << std::endl;
            return;
        } else infoFile(file1);
    } else {
        std::cout << "Unknown command: " << action << std::endl;
    }
}