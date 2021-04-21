1. LinkedBag340.cpp
	removeSecondNode340()
		Line21: when remove 2nd element, use smarter pointer
			Reason: 
				shared_ptr<Node<ItemType>> nodeToDeletePtr(headPtr);
				headPtr = secondPtr;

				In above code, headPtr is re-assigned with secondPtr, 
				so smart pointer nodeToDeletePtr which pointer header is no longer when this block is ended.



2. LinkedBag.cpp
	remove()
		Line 94: when remove element, use smarter pointer
			Reason: 
				shared_ptr<Node<ItemType>> nodeToDeletePtr(headPtr);
				headPtr = headPtr->getNext();

				In above code, headPtr is re-assigned with next pointer, 
				so smart pointer nodeToDeletePtr which pointer header is no longer when this block is ended.

	remove()
		Line 94: when LinkedBag is destryed
			Reason: 
				shared_ptr<Node<ItemType>> ptr(headPtr);
				
				In above code, when object is destroyed, headPtr is also destroyed, 
				so when headPtr is changed to smart pointer, it will release all connected memory
