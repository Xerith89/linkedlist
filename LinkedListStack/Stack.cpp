#include "Stack.h"

void Stack::Push(int val)
{
	pCurrent = new Node; //create a new node in the list and point Pcurrent to it
	pCurrent->data = val; //set the new node data to the value passed into the function
	size++; //increase the size of the list
	if (pHead == nullptr) //if our head pointer is null it means we don't have a head yet
	{
		pHead = pCurrent; //set the head to the current as it is the first node
		pTemp = pCurrent; //also set the ptemp to the current and first node
	}
	pTemp->pNext = pCurrent; //set the link from the old node to the new node
	pTemp = pCurrent; //move our temp pointer to the current node
	pCurrent->pNext = nullptr; //last node next pointer set to null
}

int Stack::Pop()
{
	if (Size() > 1) // if the size is bigger than 1 node
	{
		--size;
		const int returnval = pCurrent->data; //return what it is in the data of our current node
		pOldTop = pCurrent;
		pTemp = pHead; //set our temp pointer back to the start of the list
		for (int i = 0; i < Size(); i++) //loop through the size of the list
		{
			if (pTemp->pNext != pCurrent) //each iteration we check if the next node to the one ptemp is in, is equal to the node of pCurrent
			{
				pTemp = pTemp->pNext; //if not then set pTemp to that node - we should then be at the node before the current
			}
		}
		pCurrent = pTemp; //set the current node to temp which should be the end
		delete pOldTop;
		pOldTop = nullptr;
		return returnval;
	}
	else if (Size() == 1)
	{
		--size;
		pOldTop = pHead;
		const int returnval = pHead->data;
		delete pOldTop;
		return returnval;
	}
	else
		return -1;
}

int Stack::Size() const
{
	return size;
}

bool Stack::Empty() const
{
	return (size == 0);
}

void Stack::Delete()
{
	if (Size() > 1)
	{
		for (int i = 0; i < Size(); i++)
		{
			if (pCurrent->pNext != pOldTop)
			{
				pCurrent = pCurrent->pNext;
				delete pOldTop;
				--size;
				pOldTop = pCurrent;
			}
		}
		while (Size() > 2)
		{
			Delete();
		}
	}
	else if (Size() == 1)
	{
		--size;
		delete pHead;
	}
	else if (Size() == 2)
	{
		--size;
		delete pCurrent;
	}
	else
		return;
}
