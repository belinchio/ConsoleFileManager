#include "ManagerFunction.h"
#include "ParseUserCommand.h"
#include "UnitTests.h"
#include "Help.h"
#include "ClearScreen.h"

int main(int argc, char const *argv[])
{
    std::string cmd;
    while(true) {
        LOG_INFO("Launching the manager");
        helpMsg();
        std::cout << "Enter the command " << std::endl << "-> ";
        getline(std::cin, cmd);
        if (cmd == "exit") {
            LOG_INFO("Exiting the manager");
            break;
        } else if (cmd == "help"){
            LOG_INFO("Request for the help function");
            printHelpInfo();
        } else if (cmd == "cls") {
            LOG_INFO("Clearing the screen");
            clearScreen();
        } else if (cmd == "test") {
            LOG_INFO("Running unit tests");
            test_functions();
        } else {
            LOG_INFO("Starting the parsing commands");
            parseCommand(cmd);
        }
    }
    return 0;
}
