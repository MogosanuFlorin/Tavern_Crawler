#include <iostream>
#include <string>
#include <cstdlib>
#include "storyNode.h"
#include "loadStory.h"
using namespace std;



void clearConsole() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}


int main()
{
	/*int choice;
	cout << "Destinul Cavalerilor Pierduti" << endl;
	cout << "Apasa '1' pentru a incepe jocul" << endl;
	cin >> choice;
	if (choice == 1)
	{
		cout << "Incepe jocul" << endl;
	}
	else
	{
		return 0;
	}*/


	storyNode* currentNode = new storyNode();
	currentNode = loadStory();
	while (currentNode) {
		clearConsole();
		cout << currentNode->story << endl;
		cout << currentNode->option1 << endl;
		cout << currentNode->option2 << endl;
		int choice;
		cout << "Choose an option: ";
		cin >> choice;
		if (choice == 1)
		{
			currentNode = currentNode->nextNode1;
		}
		else if (choice == 2)
		{
			currentNode = currentNode->nextNode2;
		}
		else
		{
			cout << "Invalid choice" << endl;
		}
	}
	return 0;
}


