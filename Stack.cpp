#include<iostream>
#include "Stack.h"
using namespace std;


Stack::Stack()
{
	pHead = NULL;
}

bool Stack::IsEmpty()
{
	if (pHead == NULL) {
		return true;
	}
	return false;

}

Node* Stack::CreateNode(string x)
{
	Node* p = new Node();
	p->Data = x;
	p->pNext = NULL;
	return p;
}

void Stack::Push(string x)
{
	Node* p = CreateNode(x);
	if (IsEmpty())
	{
		pHead = p;
	}
	else
	{
		p->pNext = pHead;
		pHead = p;
	}
}

string Stack::Pop()
{
    string x;
	if (!IsEmpty())
	{
		Node* p = pHead;
		x = p->Data;
		pHead = p->pNext;
		delete p;
	}
	else {
		x = " ";
	}
	return x;
}


Node* Stack::GetHead()
{
	return pHead;
}

Stack::~Stack()
{
	while (!IsEmpty())
	{
		Node* p = pHead;
		pHead = p->pNext;
		delete p;
	}
}

