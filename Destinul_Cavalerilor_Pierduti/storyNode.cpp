#include <iostream>
#include <string>
#include "storyNode.h"
using namespace std;

storyNode::storyNode() {
	this->story = "";
	this->option1 = "";
	this->option2 = "";
	this->nextNode1 = NULL;
	this->nextNode2 = NULL;
}

storyNode::storyNode(string story, string option1, string option2) {
	this->story = story;
	this->option1 = option1;
	this->option2 = option2;
	this->nextNode1 = NULL;
	this->nextNode2 = NULL;
}

void storyNode::setNextNodes(storyNode* node1, storyNode* node2) {
	this->nextNode1 = node1;
	this->nextNode2 = node2;
}


