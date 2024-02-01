#pragma once

#include "ManagerFunction.h"

#include <cassert>

// Unit test

void test_create() {
    {
        std::string file = "test.txt";
        createFile(file);
        assert(fs::exists(file));
        std::cout << "Test the \"createFile()\" function --> OK" << std::endl;
    }
}

void test_exists_valid() {
    {
        std::string file = "test.txt";
        std::ofstream outfile(file);
        outfile.close();

        assert(fs::exists(file));

        std::cout << "Test the \"existsFile()\" function whis an existing file --> OK" << std::endl;
    }
}

void test_exists_invalid() {
    {
        std::string file = "invalid.txt";

        assert(!existsFile(file));

        std::cout << "Test the \"existsFile()\" function whis an unexisting file --> OK" << std::endl;
    }
}

void test_remove() {
    {
        std::string file = "test.txt";
        std::ofstream outfile(file);
        outfile.close();

        removeFile(file);

        assert(!fs::exists(file));
        std::cout << "Test the \"removeFile()\" function whis an existing file--> OK" << std::endl;
    }
}

void test_move() {
    {
        std::string file1 = "test1.txt";
        std::string file2 = "test2.txt";
        std::ofstream outfile(file1);
        outfile << "This is test file";
        outfile.close();

        moveFile(file1, file2);

        std::ifstream infile(file2);
        std::string conteins((std::istreambuf_iterator<char>(infile)), std::istreambuf_iterator<char>());

        assert(conteins == "This is test file");
        infile.close();

        removeFile(file2);
        std::cout << "Test the \"moveFile()\" function --> OK" << std::endl;
    }
}

void test_copy() {
    {
        std::string file1 = "test1.txt";
        std::string file2 = "test2.txt";
        std::ofstream outfile(file1);
        outfile << "This is test file";
        outfile.close();

        copyFile(file1, file2);

        std::ifstream infile(file2);
        std::string conteins((std::istreambuf_iterator<char>(infile)), (std::istreambuf_iterator<char>()));

        assert(conteins == "This is test file");

        infile.close();
        removeFile(file1);
        removeFile(file2);

        std::cout << "Test the \"copyFile()\" function --> OK" << std::endl;
    }
}

// Function of running tests

void test_functions() {
    test_create();
    test_exists_valid();
    test_exists_invalid();
    test_remove();
    test_move();
    test_copy();
}
