#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime> // temp
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



	int viataPlayer = 100;
	int viataInamic = 100;
	string s = "";
	s += "Your HP: " + to_string(viataPlayer) + "												Enemy HP: " + to_string(viataInamic);
	cout << s << endl << endl;
	s = "Choose your attack:\n1. Rock\n2. Paper\n3. Scissors\nChoose an option: ";
	cout << s;
	int choice;
	cin >> choice;

	srand(static_cast<unsigned int>(time(0))); //seed random number generator
	for (int i = 0; i < 10; i++)
	{
		int enemyChoice = rand() % 3 + 1;
		cout << enemyChoice << endl;
	}

	

	/*storyNode* currentNode = new storyNode();
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
	}*/
	return 0;
}


