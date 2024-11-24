#include <iostream>
#include <string>
#include "Node.h"
#include "Display.h"
#include "Player.h"
#include "NodeAction.h"
using namespace std;

Node::Node()
{
	this->story = "";
	this->options = {};
	this->nextNodes = {};
	this->action = nullptr;
}

Node::~Node()
{
	delete this->action;
}

void Node::setStory(std::string story, std::vector<std::string> options, std::vector<Node*> nextNodes) 
{
	this->story = story;
	this->options = options;
	this->nextNodes = nextNodes;
}

void Node::setAction(NodeAction* action) {
	delete this->action;
	this->action = action;
}

void Node::callAction(Player* player) {
	if (this->action) {
		this->action->execute(this, player);
	}
}

int Node::printStory() const
{
	Display::clear();
	cout << this->story << endl;
	int count = 1;
	if (this->options.size() != 0)
		for (auto option : this->options)
		{
			cout<< count++ << ". " << option << endl;
		}
	if (this->options.size()!=0)
	{
		int choice;
		cout << endl << "Choice: ";
		cin >> choice;
		return choice;
	}
	Display::waitForKeyPress();
	return 1;
}

Node* Node::getNextNode(int id)
{
	if (id < 1 || id >= nextNodes.size()+1) {
		return nullptr;
	}
	return nextNodes[id-1];
}
