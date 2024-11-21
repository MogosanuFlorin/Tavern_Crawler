#include "Game.h"
#include "Player.h"
#include "Node.h"
#include "NodeAction.h"
#include "Enemy.h"
#include <vector>
#include <iostream>

Game::Game()
{
	this->player = new Player();
	this->currentNode = getStartNode();
}

void Game::run()
{
	while (currentNode && player->getHp() > 0) {
		int choice = currentNode->printStory();

		// Perform the action associated with the node
		currentNode->callAction(player);

		// Move to the next node based on the player's choice
		currentNode = currentNode->getNextNode(choice);
	}

	if (player->getHp() <= 0) {
		std::cout << "You have perished. Game Over!\n";
	}
	else {
		std::cout << "Your adventure has ended. Thank you for playing!\n";
	}
}

Node* Game::getStartNode() {
	std::string story = "BARNES\n'It's a bastard of a dragon. Terrorizing us for weeks. Burning up the crops in the farmlands outside the village. Swooping down and roaring and sending us all running into our houses. We're one of the last independent villages, beyond the reach of the queen. This dragon is going to destroy us if someone doesn't stop it.'\n\nHe reaches into his pocket and digs around…\n\nBARNES\n'But... if you're not satisfied that the blasted thing deserves to die yet... I have something I think will help subdue your conscience..'\n\nHe finally clumsily digs a small burlap sack from his pocket. His shaking hand pitches it on to the table. Gold coins clatter out.\n\nBARNES\n'Ten pieces of gold. Go on. Take it. Just a taste\nYou get that now... and once you've killed the dragon... you get four hundred thousand pieces'\n\nYOU\n'Any other details I should know about?'\n\nBARNES\n'Very simple. Cut off the dragon's head and bring it to me to prove you really killed it. Bring it to me straight away at the <not understandable name> Tavern in the village. Don't stop off anywhere else in the village first. Once I've given you your gold, you leave town without a word to anyone.'\n\nAll those drinks are finally catching up with you. Everything spins. Barnes's voice sounds as if it were coming from very far away.\n\nYOU\n'Got it. Bring it to you in the, uh… tavern'\n\nBARNES'You'll find it down a little set of stairs in the rough part of town. Follow the back alleys, take a left, a right, keep going forward, then another right, another quick right, a left, then another left, until you see the sign with the owl insignia. Can't miss it! The place is a tad exclusive. You'll need the password to get in. It's <not understandable >. Got it? I'll be waiting for you there in a fortnight's time. Send word if you'll be delayed...'\n\nYou nod. The whole room is spinning now. Barnes bids you all adieu.\n\nYou retire in your room in the inn.";
	std::string option1 = "";
	std::string option2 = "";
	std::vector<std::string> options = {};
	std::vector<Node*> nextNodes = {nullptr};
	Node* finalDemoNode = new Node();
	finalDemoNode->setStory(story, options, nextNodes);
	finalDemoNode->setAction(new GetGoldAction(10));

	story = "A tall, thin man with a thick walrus moustache, wireframe spectacles, and a bowler hat ambles toward your table. He looks completely out of place in the Hub-And-Spoke Tavern at this hour.\n\nHe reaches your table and doesn't say anything. Just stands there and scrutinizes.\n\nYOU\n'Something you want?'\n\nMAN IN BOWLER HAT\n'I saw the way you handled those soldiers. They were Nagata Hatta, no? The queen's right hand, they call them. I've seen things turn ugly with them in the past. Usually ends with the other fellow dead. But you handled them. Very sly'\n\nYOU\n'I guess I got lucky'\n\nMAN IN BOWLER HAT\n'Didn't look like luck had anything to do with it. But if it did... well, let's just say, I have a business proposition for someone who has that kind of luck.'\n\nYOU\n'What sort of business?'\n\nMAN IN BOWLER HAT\n'Before I say any more... I like to know a little bit about the people I do business with. What's your name?'\n\nYOU\nGeralt'\n\nMAN IN BOWLER HAT\n'Well, Geralt, my name is Barnes. We've got a little problem in Akema. And we need someone to resolve it. Swiftly and discreetly.'\n\nYOU\n'What's the problem?'\n\nBARNES\n'Dragon'\n\nYOU\n'So what do you need me to do?'\n\nBARNES\n'Kill the dragon, obviously. It's made its nest in the caves of Akema's Peak, just to our south.'";
	option1 = "'This seems dangerous. Taking on a real live dragon?'";
	option2 = "'This seems cruel. What did the dragon ever do to anyone?'";
	options = { option1, option2 };
	nextNodes = { finalDemoNode, finalDemoNode };
	
	Node* introductionOfBarnes = new Node();
	introductionOfBarnes->setStory(story, options, nextNodes);

	story = "You sit down at your table, trying to catch your breath and nursing some nasty scrapes.";
	options = {};
	nextNodes = { introductionOfBarnes };
	Node* sitToTableCombat = new Node();
	sitToTableCombat->setStory(story, options, nextNodes);

	story = "You sit down at your table, happy to have avoided a nasty fight.";
	options = {};
	nextNodes = { introductionOfBarnes };
	Node* sitToTableHappy = new Node();
	sitToTableHappy->setStory(story, options, nextNodes);

	story = "You sit down at your table, annoyed you had to debase yourself to get out of the situation.";
	options = {};
	nextNodes = { introductionOfBarnes };
	Node* sitToTableDebase = new Node();
	sitToTableDebase->setStory(story, options, nextNodes);

	story = "You get in a fight with the soldier.";
	options = {};
	nextNodes = { sitToTableCombat };
	Node* punchHimInTheFace = new Node();
	punchHimInTheFace->setStory(story, options, nextNodes);
	Enemy* soldier = new Enemy(10, 2, 0);
	punchHimInTheFace->setAction(new CombatAction(soldier));

	story = "You lower yourself to the floor. The soldier sticks out his boot, leather and jagged steel, sneering. You taste the cracked old leather as you press your lips to it.\n\nSOLDIER\n'Your slight is forgiven.'";
	options = {};
	nextNodes = { sitToTableDebase };
	Node* getDownOnTheFloor = new Node();
	getDownOnTheFloor->setStory(story, options, nextNodes);

	story = "YOU\n'I am an emissary on a secret mission from the queen. Kill me at your peril.'\n\nThis is, of course, a bold-faced lie. But you say it with such conviction that the soldier scrunches up his face, uncertain.\n\nSOLDIER\n'What sort of secret mission?'\n\nYOU\n'If I told you, it wouldn't very well be a secret, would it?'\n\nThe soldier considers this and nods, impressed.\n\nSOLDIER\n'It is a rare honor to meet a member of the queen's left hand.'\n\nHe claps you on the shoulder.\n\nSOLDIER\n'By her grace.'\n\nYOU\n'In her, all things are possible.'\n\nThe soldier pounds his chest. He and the other two soldiers march away into the crowd, hollering for more ale.";
	options = {};
	nextNodes = { sitToTableHappy };
	Node* iAmAnEmissary = new Node();
	iAmAnEmissary->setStory(story, options, nextNodes);

	story = "YOU\n'I am sorry. I'd never think to insult a member of the queen's guard.'\n\nSOLDIER\n'That's a good start. But your penance must fit the slight. Grovel. Beg forgiveness. Get down on the floor and kiss my boots.'";
	option1 = "Get down on the floor and kiss his boots.";
	option2 = "Punch him in the face.";
	options = { option1, option2 };
	nextNodes = { getDownOnTheFloor, punchHimInTheFace };
	Node* iAmSorry = new Node();
	iAmSorry->setStory(story, options, nextNodes);

	story = "Now that you're getting a proper look at the guy... you realize he's a soldier. A soldier bearing the rust-red crest of the queen on his chest.\nYou've pissed off a soldier of the Nagata Hatta: the queen's right hand.\nYou smile and say:\n";
	option1 = "I am an emissary on a secret mission from the queen. Kill me at your peril.";
	option2 = "I am sorry. I'd never think to insult a member of the queen's guard.";
	options = { option1, option2 };
	nextNodes = { iAmAnEmissary, iAmSorry };
	Node* talkHimInCircles = new Node();
	talkHimInCircles->setStory(story, options, nextNodes);

	story = "A hush falls over the bar. Everyone is watching. He steps towards you... putting up his dukes. You're what he's been looking for all night: an excuse to get his knuckles bloody.\nWhat do you do?\n";
	option1 = "Talk him in circles";
	option2 = "Punch him in the face";
	options = { option1, option2 };
	nextNodes = { talkHimInCircles, punchHimInTheFace };
	Node* start = new Node();
	start->setStory(story, options, nextNodes);


	return start;
}
