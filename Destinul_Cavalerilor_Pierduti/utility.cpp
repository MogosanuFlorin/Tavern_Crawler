#include <iostream>
#include <cstdlib>
#include <ctime>

#ifdef _WIN32
#include <conio.h>
#else
#include <unistd.h>
#endif


void clear() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

void waitForKeyPress() {
#ifdef _WIN32
	std::cout << "Press any key to continue...\n";
	_getch();
#else
	std::cout << "Press any key to continue...\n";
	system("read -n 1 -s -p \"\"");
#endif
}

int random() {
 srand(static_cast<unsigned int>(time(0))); //seed random number generator
	return 1 + (rand() % 3);
}