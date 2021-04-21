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

	Node<ItemType>* ptr = headPtr;
	Node<ItemType>* secondPtr = headPtr->getNext();
	
	secondPtr->setItem(headPtr->getItem());
	Node<ItemType>* nodeToDeletePtr = headPtr;

	headPtr = secondPtr;

	nodeToDeletePtr->setNext(nullptr);
	delete nodeToDeletePtr;
	nodeToDeletePtr = nullptr;

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
int LinkedBag<ItemType>::getFrequencyOf340Recursive(const ItemType&) const
{
	return -1;
}

template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveNoHelper(const ItemType&) const
{
	return -1;
}

template<typename ItemType>
ItemType LinkedBag<ItemType>::removeRandom340()
{
	return ItemType();
}

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveHelper(Node<ItemType>* node) const // if needed
{
	if (node == nullptr)
		return 0;

	return 1 + getCurrentSize340RecursiveHelper(node->getNext());	
}

template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveHelper(Node<ItemType>*, const ItemType&) const // if needed
{
	return -1;
}