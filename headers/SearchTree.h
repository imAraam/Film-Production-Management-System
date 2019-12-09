//Part of the code inspired from https://gist.github.com/mycodeschool/44e1a9183ab0e931f729

#ifndef SEARCHTREE_H
#define SEARCHTREE_H

#include <iostream>

struct Node
{
	long double data; //As the binary search tree will be used to store and compare ticket sales which is of type long double
	Node* left;
	Node* right;
};

Node* getNewNode(long double data)
{
	Node* newNode = new Node();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}


Node* insert(Node* rootPtr, long double data)
{
	if (rootPtr == NULL)
	{
		rootPtr = getNewNode(data);
	}
	else if (data <= rootPtr->data)
	{
		rootPtr->left = insert(rootPtr->left, data);
	}
	else
	{
		rootPtr->right = insert(rootPtr->right, data);
	}
	return rootPtr;
}

bool search(Node* rootPtr, long double data)
{
	if (rootPtr == NULL)
	{
		return false;
	}
	else if (rootPtr->data == data)
	{
		return true;
	}
	else if (data <= rootPtr->data) return search(rootPtr->left, data);
	else return search(rootPtr->right, data);
}


void displayPreOrder(Node* rootPtr)
{
	if (rootPtr != NULL)
	{
		displayPreOrder(rootPtr->left); //L - P - R
		std::cout << rootPtr->data << " ";
		displayPreOrder(rootPtr->right);
	}
}

void makeDeletion(Node *&rootPtr) {

	Node *tempNodePtr; // temporary pointer to reattach left or right sub tree

	if (rootPtr == NULL)
	{
		std::cout << "Cannot delete empty node. \n";
	}
	else if (rootPtr->right == NULL)
	{
		tempNodePtr = rootPtr;
		rootPtr = rootPtr->left;
		delete tempNodePtr;
	}
	else if (rootPtr->left == NULL)
	{
		tempNodePtr = rootPtr;
		rootPtr = rootPtr->right;
		delete tempNodePtr;
	}
	else
	{
		tempNodePtr = rootPtr->right;
		while (tempNodePtr->left)
		{
			tempNodePtr = tempNodePtr->left;
		}
		tempNodePtr->left = rootPtr->left;
		tempNodePtr = rootPtr;

		rootPtr = rootPtr->right;
		delete tempNodePtr;
	}
}

void deleteNode(int num, Node *&rootPtr) {
	if (num < rootPtr->data) {
		deleteNode(num, rootPtr->left);
	}
	else if (num > rootPtr->data)
	{
		deleteNode(num, rootPtr->right);
	}
	else {
		makeDeletion(rootPtr);
	}
}


#endif