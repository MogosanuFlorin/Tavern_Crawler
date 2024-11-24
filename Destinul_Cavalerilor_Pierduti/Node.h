#pragma once
#include <string>
#include <vector>

class NodeAction;
class Player;

class Node
{
public:
	Node();
	~Node();
	void setStory(std::string story, std::vector<std::string> options, std::vector<Node*> nextNodes);
	void setAction(NodeAction *action);
	void callAction(Player *player);
	int printStory() const;
	Node* getNextNode(int id);
private:
	std::string story;
	std::vector<std::string> options;
	std::vector<Node*> nextNodes;
	NodeAction* action;
};

