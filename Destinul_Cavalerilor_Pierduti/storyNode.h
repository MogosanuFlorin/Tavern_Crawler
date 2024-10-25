#pragma once
#include <string>
using namespace std;
class storyNode
{
public:
	storyNode();
	storyNode(string story, string option1, string option2);
	void setNextNodes(storyNode* node1, storyNode* node2);
	string story;
	string option1;
	string option2;
	storyNode* nextNode1;
	storyNode* nextNode2;
};