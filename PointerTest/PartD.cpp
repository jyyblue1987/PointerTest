#include "Include.h"

void displayBag(const unique_ptr<LinkedBag<int>>&);


int main() {

	cout << "----- LINKED BAG 340 C++-----" << endl << endl;

	unique_ptr<LinkedBag<int>> bag{ make_unique <LinkedBag<int>>() };

	int n = 10;
	for (int i = 0; i < 10; i++)
		bag->add(rand() % 1000);

	cout << "Original List" << endl << endl;
	displayBag(bag);

	bag->selectionSort();

	cout << "Sorted List" << endl << endl;
	displayBag(bag);

}

// Display the current contents in the bag
void displayBag(const unique_ptr<LinkedBag<int>>& bag) {
	cout << "\n !Display bag: ";
	auto bagItems = make_unique<vector<int>>(bag->toVector());

	vector<int>::const_iterator cItr;
	for (cItr = bagItems->begin(); cItr != bagItems->end(); cItr++) {
		cout << *cItr << " ";
	}

	cout << "\n  -----------> " << bagItems->size() << " item(s) total";
	cout << endl;
}