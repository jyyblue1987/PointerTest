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
	return -1;
}

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Recursive() const
{
	return -1;
}

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveNoHelper() const
{
	return -1;
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
int LinkedBag<ItemType>::getCurrentSize340RecursiveHelper(Node<ItemType>*) const // if needed
{
	return -1;
}

template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveHelper(Node<ItemType>*, const ItemType&) const // if needed
{
	return -1;
}