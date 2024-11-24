#include "Game.h"
#include "Player.h"
#include "Node.h"
#include "NodeAction.h"
#include "Enemy.h"
#include "Display.h"
#include <vector>
#include <iostream>
#include <unordered_map>
#include <fstream>
#include <sstream>

Game::Game()
{
	this->player = new Player();
	this->currentNode = getStartNode();
}

void Game::run()
{
	while (currentNode && player->getHp() > 0) {
		int choice = currentNode->printStory();

		currentNode->callAction(player);

		currentNode = currentNode->getNextNode(choice);
	}

	Display::clear();
	if (player->getHp() <= 0) {
		std::cout << "You have perished. Game Over!\n";
	}
	else {
		std::cout << "Your adventure has ended. Thank you for playing!\n";
	}
}

Node* Game::getStartNode()
{
    std::ifstream file("story.txt");
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << "story.txt" << std::endl;
        return nullptr;
    }
    std::cout << "File opened" << std::endl;
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string nodeName, leftChildName, rightChildName, actionName;
        std::vector<std::string> options;
        std::string option;

        if (!(iss >> nodeName >> leftChildName >> rightChildName >> actionName)) {
            continue;
        }

        std::string story;
        std::string storyLine;
        while (std::getline(file, storyLine) && storyLine != "end") {
            story += storyLine + "\n";
        }

        while (std::getline(file, option) && !option.empty()) {
            options.push_back(option);
        }

        Node* node = nullptr;
        if (nodes.find(nodeName) == nodes.end()) {
            node = new Node();
            nodes[nodeName] = node;
        }
        else {
            node = nodes[nodeName];
        }

        if (!leftChildName.empty() && nodes.find(leftChildName) == nodes.end() && leftChildName != "null") {
            nodes[leftChildName] = new Node();
        }
        if (!rightChildName.empty() && nodes.find(rightChildName) == nodes.end() && rightChildName != "null") {
            nodes[rightChildName] = new Node();
        }

        node->setStory(story, options, {
            leftChildName == "null" ? nullptr : nodes[leftChildName],
            rightChildName == "null" ? nullptr : nodes[rightChildName]
            });

        if (!actionName.empty() && actionName != "null") {
			if (actionName == "GetGoldAction") {
				node->setAction(new GetGoldAction(10));
			}
			else if (actionName == "CombatAction") {
				Enemy* soldier = new Enemy(10, 2, 0);
				node->setAction(new CombatAction(soldier));
			}
        }

       /* std::cout << "Created node: " << nodeName << std::endl;
        std::cout << "Story: " << story << std::endl;
        std::cout << "Options: ";
        for (const auto& opt : options) {
            std::cout << opt << " ";
        }
        std::cout << std::endl;
        std::cout << "Left Child: " << leftChildName << ", Right Child: " << rightChildName << std::endl;
        Display::waitForKeyPress();*/
    }

    file.close();
    return nodes.empty() ? nullptr : nodes.begin()->second;
}

