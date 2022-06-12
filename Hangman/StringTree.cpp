/*
 * Author: Nikolas George
 * Purpose: Project 1
 */

 //User Libraries

#include <iostream>
#include "StringTree.h"

using namespace std;

void randomStringRecursive(Node* root, int target, int& current, string& output)
{
	current++;

	if (current == target)
	{
		output = root->val;
	}
	if (root->left)
	{
		randomStringRecursive(root->left, target, current, output);
	}
	if (root->right)
	{
		randomStringRecursive(root->right, target, current, output);
	}
}

string StringTree::randomString()
{
	if (size == 0)
	{
		return "";
	}

	int current = -1;
	string output = "";
	randomStringRecursive(root, rand() % size, current, output);
	return output;
}

Node* addStringRecursive(string s, Node* root)
{
	if (root == nullptr)
	{
		root = new Node();

		root->left = nullptr;
		root->right = nullptr;
		root->val = s;
	}
	else if (root->val < s)
	{
		root->left = addStringRecursive(s, root->left);
	}
	else
	{
		root->right = addStringRecursive(s, root->right);
	}

	return root;
}

void StringTree::addString(string s)
{
	size++;
	root = addStringRecursive(s, root);
}