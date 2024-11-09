#include <iostream>
#include "loadStory.h"
#include "Node.h"
#include "utility.h"
using namespace std;
int main()
{
	int choice;
	cout << "TavernCrawler DEMO" << endl;
	cout << "Press '1' to start the game" << endl;
	cin >> choice;
	if (choice == 1)
	{
		cout << "The game starts" << endl;
	}
	else
	{
		return 0;
	}
	clear();
	string s = "It's last call at The Hub-And-Spoke Tavern. A dwarf crawls up on a barstool and calls for one more round of ale. In the corner, a game of darts goes very wrong. Someone, somewhere, sings loudly off-key. Someone somewhere else screams at him to shut the hell up. The last of the desperate lovers shrug and pair off: ''I suppose you'll have to do...''\n\nAs for you? You are very drunk.\n\nThe barroom cants back and forth around you. The stench of pipe weed fills up your nostrils. You stumble through the crowd... and slam right into a soldier. He's clad in tarnished silver armor and the rust-red crest of the queen. His beer goes spilling all over him. He glares at you, lip curling into a sneer.";
	cout << s << endl;
	waitForKeyPress();
	Node* currentNode = new Node();
	currentNode = loadStory();
	while (currentNode) {
		clear();
		if (currentNode->getFunctionID() == 0) {
			int choice;
			choice = currentNode->printStory();
			if (choice == 1) {
				currentNode = currentNode->getNextNode(1);
			}
			else {
				currentNode = currentNode->getNextNode(2);
			}
		}
		else {
			currentNode->callFunction();
			currentNode = currentNode->getNextNode(1);
		}
	}
	return 0;
}


