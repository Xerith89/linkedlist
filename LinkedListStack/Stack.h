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
	Node* pOldTop = nullptr;
	int size = 0;
	
public:
	Stack() = default;

	Stack(const Stack& src)
	{
		*this = src;
	}

	Stack& operator=(const Stack& src)
	{
		if (!src.Empty())
			{
				pCurrent = new Node(*src.pCurrent);
				pHead = new Node(*src.pHead);
				size = src.size;
				pTemp = new Node(*src.pTemp);
			}
		return *this;
	}

	~Stack()
	{
		pOldTop = pCurrent;
		pCurrent = pHead;
		Delete();
	}

	void Push( int val );
	int Pop();
	int Size() const;
	bool Empty() const;
	void Delete();
};