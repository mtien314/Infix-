#pragma once
#include <iostream>
#include<string>
#include<vector>
using namespace std;

class Node
{
public:
	string Data;
	Node* pNext;
};



class Stack
{
private:
	Node* pHead;

public:
	Stack();
	bool IsEmpty();
	Node* CreateNode(string x);
	void Push(string x);
	string Pop();
	Node* GetHead();
	~Stack();
};



