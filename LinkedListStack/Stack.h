#pragma once

class Stack
{
private:
	struct Node {
		int data;
		Node* pNext = nullptr;
	};
	Node* pHead = nullptr;
	Node* pCurrent = nullptr;
	Node* pTemp = nullptr;
	int size = 0;
	
public:
	void Push( int val );
	int Pop();
	int Size() const;
	bool Empty() const;
};