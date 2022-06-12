/*
 * Author: Nikolas George
 * Purpose: Project 1
 */

#pragma once

 //User Libraries

#include <iostream>
#include <string>

struct Node
{
	Node* left;
	Node* right;
	std::string val;
};

class StringTree
{
	Node* root = nullptr;
	int size = 0;
public:
	std::string randomString();
	void addString(std::string s);
};
