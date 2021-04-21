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
	Node<ItemType>* ptr = headPtr;
	Node<ItemType>* secondPtr = nullptr;
	int count = 0;

	while (ptr != nullptr) {
		if (count == 1)
		{
			secondPtr = ptr;
			break;
		}
		ptr = ptr->getNext();
		count++;
	}

	bool canRemoveItem = !isEmpty() && (secondPtr != nullptr);

	if (canRemoveItem) {
		secondPtr->setItem(headPtr->getItem());
		Node<ItemType>* nodeToDeletePtr = headPtr;
		headPtr = headPtr->getNext();

		nodeToDeletePtr->setNext(nullptr);
		delete nodeToDeletePtr;
		nodeToDeletePtr = nullptr;

		itemCount--;
	}

	return canRemoveItem;
}

template<typename ItemType>
bool LinkedBag<ItemType>::addEnd340(const ItemType&)
{
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