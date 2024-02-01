#pragma once

#include <iostream>

void helpMsg() {
    std::cout << "To get help, enter \"help\"\t";
    std::cout << "To clear the screen, enter \"cls\"\t";
    std::cout << "To exit, enter \"exit\"\t";
    std::cout << "To stsrt test, enter \"test\"" << std::endl;
}

void printHelpInfo() {
    std::cout << "remove - To delete a file" << std::endl;
    std::cout << "parametrs: remove ${fileName} (example: remove ./test.txt)\n" << std::endl;

    std::cout << "create - To create a file" << std::endl;
    std::cout << "parametrs: create ${fileName} (example: create ./test.txt)\n" << std::endl;

    std::cout << "exists - To check the existence of the file"<< std::endl;
    std::cout << "parametrs: exists ${fileName} (example: exists ./test.txt)\n" << std::endl;

    std::cout << "info - To get info about file" << std::endl;
    std::cout << "parametrs: info ${fileName} (example: info ./test.txt)\n" << std::endl;

    std::cout << "copy - To copy a file" << std::endl;
    std::cout << "parametrs: copy ${fileName1} ${fileName2} (example: copy ./test.txt /tmp/text.txt)\n" << std::endl;

    std::cout << "move - To move a file" << std::endl;
    std::cout << "parametrs: move ${fileName1} ${fileName2} (example: move ./test.txt /tmp/text.txt)\n" << std::endl;

    std::cout << "rename - To rename a file" << std::endl;
    std::cout << "parametrs: rename ${fileName} ${new_fileName} (example: rename ./test.txt ./new_test.txt)\n" << std::endl;
}
