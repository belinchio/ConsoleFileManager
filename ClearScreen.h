#pragma once

#include <cstdlib>

void clearScreen() {
#if defined (_WIN32) || defined (_WIN64)
    system("cls");
#else
    system("clear");
#endif
}
