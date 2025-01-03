#include <iostream>
#include "SimpleVector.h"

int main() {
	SimpleVector<int> testV;
	cout << "SimpleVector testV - size: " << testV.size() << " / capacity: " << testV.capacity() << endl;

	SimpleVector<float> v(3);
	cout << "\nSimpleVector v - size: " << v.size() << " / capacity: " << v.capacity() << endl;
	v.pop_back(); /***array is empty***/
	v.push_back(5);		// [5]
	v.sortData(); /***not enough data in array***/
	v.push_back(9);		// [5, 9]
	v.push_back(6.5);	// [5, 9, 6.5]
	v.push_back(8); /***array is full --> resize(capacity + 5) --> adds 8 at the end***/
						// [5, 9, 6.5 8]
	v.pop_back();		// [5, 9, 6.5]
	v.push_back(1);		// [5, 9, 6.5, 1]

	// printing v
	cout << "v = [";
	for (int i = 0; i < v.size()-1; i++)
		cout << v.at(i) << ", ";
	cout << v.at(v.size() - 1) << "]\n" ;

	SimpleVector<float> v2(v);	// [5, 9, 6.5, 1]
	cout << "\nSimpleVector v2(copy of v) - size: " << v2.size() << " / capacity : " << v2.capacity() << endl;
	v2.sortData();				// [1, 5, 6.5, 9]
	v2.push_back(1.5);			// [1, 5, 6.5, 9, 1.5]
	int test = v2.at(7); /***Index is out of range***/
	
	// printing v2
	cout << "v2 = [";
	for (int i = 0; i < v2.size()-1; i++)
		cout << v2.at(i) << ", ";
	cout << v2.at(v2.size() - 1) << "]\n\n";
	
	return 0;
}