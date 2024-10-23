#include <iostream>
#include <string>
#include "loadStory.h"
#include "storyNode.h"

using namespace std;

int startCombat(int x)
{
	cout << "Combat has started" << endl;
	return 1;
}

storyNode* loadStory() {
	storyNode* talkHimInCircles = new storyNode("Now that you're getting a proper look at the guy... you realize he's a soldier. A soldier bearing the rust-red crest of the queen on his chest.\n\nYou've pissed off a soldier of the Nagata Hatta: the queen's right hand.\n\nYou smile and say:", "1: I am an emissary on a secret mission from the queen. Kill me at your peril.", "2: I am sorry. I'd never think to insult a member of the queen's guard.");
	storyNode* punchHimInTheFace = new storyNode("Combat starts", "", "");
	storyNode* start = new storyNode("A hush falls over the bar. Everyone is watching. He steps towards you... putting up his dukes. You're what he's been looking for all night: an excuse to get his knuckles bloody.", "1: Talk him in circles.", "2: Punch him in the face");
	start->setNextNodes(talkHimInCircles, punchHimInTheFace);

    return start;
}