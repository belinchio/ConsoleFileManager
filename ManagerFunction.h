#pragma once

#include "Logger.h"

#include <string>
#include <chrono>

// Function of removing file
void removeFile(const std::string& file) {
    if(!fs::exists(file)) {
        std::cerr << "File \"" << file << "\" doesn't exists." << std::endl;
        LOG_WARN("File doesn't exists");
        return;
    } else {
        fs::remove(file);
        std::cout << "File \"" << file << "\" successfully removed." << std::endl;
        LOG_INFO("File " + file + " removed");
    }
}

//Function of renaming file
void renameFile(const std::string& fileName, const std::string& newFileName) {
    if(!fs::exists(fileName)) {
        std::cerr << "File \"" << fileName << "\" doesn't exist." << std::endl;
        LOG_WARN("File doesn't exists");
        return;
    } else {
        fs::rename(fileName, newFileName);
        std::cout << "File \" " << fileName << "\" successfully rename to the \"" << newFileName << "\"." << std::endl;
        LOG_INFO("File " + fileName + " has been renamed to file " + newFileName);
    }
}

//Function of moving file
void moveFile(const std::string& sourceFilePath, const std::string& destinationFilePath) {
    if(!fs::exists(sourceFilePath)) {
        std::cerr << "File \"" << sourceFilePath << "\" doesn't exists." << std::endl;
        LOG_WARN("File doesn't exists");
        return;
    } else {
        fs::rename(sourceFilePath, destinationFilePath);
        if(fs::exists(destinationFilePath)) {
            std::cout << "File \"" << sourceFilePath << "\" succeefully moved." << std::endl;
            LOG_INFO("File " + sourceFilePath + " has been moved to " + destinationFilePath);
        } else {
            std::cerr << "Error of the moving file \"" << sourceFilePath << "\"." << std::endl;
            LOG_ERROR("Error of the moving file " + sourceFilePath);
            return;
        }
    }
}

//File copy function
void copyFile(const std::string& source, const std::string& destination) {
    if(!fs::exists(source)) {
        std::cerr << "File \"" << source << "\" doesn't exists." << std::endl;
        LOG_WARN("File doesn't exists");
        return;
    } else {
        fs::copy(source, destination);
        if(fs::exists(destination)) {
            std::cout << "File \"" << source << "\" successfully copied." << std::endl;
            LOG_INFO("File " + source + " has been copied to " + destination);
        } else {
            std::cerr << "Error of the copying file \"" << source << "\"." << stderr << std::endl;
            LOG_ERROR("Error of copied file " + source);
        }
    }
}

//Function of creating file
void createFile(const std::string& fileName) {
    if(fs::exists(fileName)) {
        std::cerr << "File \"" << fileName << "\" allready exists." << stderr << std::endl;
        LOG_ERROR("Attempt to create an existing file \"" + fileName + "\"");
        return;
    } else {
        std::ofstream file(fileName);
        if(!file) {
            std::cerr << "Failed to create a file." << stderr << std::endl;
            LOG_ERROR("Error of creating file " + fileName);
            return;
        } else {
            std::cout << "File \"" << fileName << "\" successfully created." << std::endl;
            LOG_INFO("File " + fileName + " succefully created");
        }
    }
}

//Function of checking exists the file
bool existsFile(const std::string& fileName) {
    if(fs::exists(fileName)) {
        std::cout << "File \"" + fileName + "\" is exists.\n";
        return true;
        LOG_INFO("Cheking the existence of the " + fileName + " file");
    } else {
        std::cout << "File \"" << fileName << "\" doesn't exists." << std::endl;
        return false;
        LOG_WARN("File " + fileName + " doesn't exists");
    }
}

//Function of getting info of the file
void infoFile(const std::string& fileName) {
    if(!fs::exists(fileName)) {
        std::cerr << "File \"" << fileName << "\" doesn't exists." << stderr << std::endl;
        LOG_WARN("Requesting info about a nonexistent file");
    } else {
        std::cout << "Info about \"" << fileName << "\":" << std::endl;
        std::cout << "Size of \"" << fileName << "\": " << fs::file_size(fileName) << " bayts;" << std::endl;
        fs::file_time_type lastModify = fs::last_write_time(fileName);
        std::cout << std::format("Last modified: {}\n", lastModify) << std::endl;
        LOG_INFO("Requesting info about " + fileName + " file");
    }
}