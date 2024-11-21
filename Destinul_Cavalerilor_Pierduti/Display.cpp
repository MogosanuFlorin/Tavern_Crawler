#include "Display.h"
#include <iostream>
#include <cstdlib>
#ifdef _WIN32
#include <conio.h>
#else
#include <unistd.h>
#endif

void Display::clear() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

void Display::waitForKeyPress() {
#ifdef _WIN32
	std::cout << "Press any key to continue...\n";
	_getch();
#else
	std::cout << "Press any key to continue...\n";
	system("read -n 1 -s -p \"\"");
#endif
}