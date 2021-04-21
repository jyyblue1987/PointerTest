//	LinkedBag340.cpp
//	Created by: CSC340

/*
===>					<===
===>  PLEASE ADD CODE	<===
===>					<===
*/

#include "LinkedBag.h"

template<typename ItemType>
bool LinkedBag<ItemType>::removeSecondNode340()
{	
	if (itemCount < 2)
		return false;

	Node<ItemType>* secondPtr = headPtr->getNext();
	
	secondPtr->setItem(headPtr->getItem());
	shared_ptr<Node<ItemType>> nodeToDeletePtr(headPtr);

	headPtr = secondPtr;

	itemCount--;
	
	return true;
}

template<typename ItemType>
bool LinkedBag<ItemType>::addEnd340(const ItemType&newEntry)
{
	Node<ItemType>* nextNodePtr = new Node<ItemType>();
	nextNodePtr->setItem(newEntry);
	nextNodePtr->setNext(nullptr);

	if (isEmpty())
	{			
		headPtr = nextNodePtr;
	}
	else
	{
		Node<ItemType>* ptr = headPtr;
		
		// find last element
		while (ptr->getNext() != nullptr) {
			ptr = ptr->getNext();		
		}

		// set next ptr for last element
		ptr->setNext(nextNodePtr);
	}

	itemCount++;

	return true;
}


template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Iterative() const
{
	Node<ItemType>* ptr = headPtr;

	int count = 0;

	while (ptr != nullptr) {
		ptr = ptr->getNext();
		count++;
	}

	return count;
}

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Recursive() const
{
	return getCurrentSize340RecursiveHelper(headPtr);
}

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveNoHelper() const
{
	static Node<ItemType> *head_ptr = headPtr;

	if (head_ptr == nullptr)
		return 0;

	head_ptr = head_ptr->getNext();
	int result = 1 + getCurrentSize340RecursiveNoHelper();

	head_ptr = headPtr;

	return result;
}

template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340Recursive(const ItemType& anEntry) const
{
	return getFrequencyOf340RecursiveHelper(headPtr, anEntry);
}

template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveNoHelper(const ItemType& anEntry) const
{
	static Node<ItemType> *head_ptr1 = headPtr;

	if (head_ptr1 == nullptr)
		return 0;

	int count = 0;
	if (anEntry == head_ptr1->getItem())
		count = 1;

	head_ptr1 = head_ptr1->getNext();
	int result = count + getFrequencyOf340RecursiveNoHelper(anEntry);

	head_ptr1 = headPtr;

	return result;	
}

template<typename ItemType>
ItemType LinkedBag<ItemType>::removeRandom340()
{
	if (itemCount < 1)
		return ItemType();

	int index = rand() % itemCount;
	Node<ItemType> *ptr = headPtr;
	int count = 0;
	while (ptr != nullptr) {
		if (count == index)
			break;
		
		ptr = ptr->getNext();
		count++;
	}

	ItemType item = ptr->getItem();

	remove(item);

	return item;
}

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveHelper(Node<ItemType>* node) const // if needed
{
	if (node == nullptr)
		return 0;

	return 1 + getCurrentSize340RecursiveHelper(node->getNext());	
}

template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveHelper(Node<ItemType>* curPtr, const ItemType& anEntry) const // if needed
{
	if (curPtr == nullptr)
		return 0;

	int count = 0;
	if (anEntry == curPtr->getItem())
		count = 1;

	return count + getFrequencyOf340RecursiveHelper(curPtr->getNext(), anEntry);
}