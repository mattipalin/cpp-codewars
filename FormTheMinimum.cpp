#include <vector>
#include <algorithm>
#include <iostream>

using namespace std; 

void print(vector<int> dummyVector)
{
	std::cout << "[";
	for (int el : dummyVector) {std::cout << el << ", ";}
	std::cout << "]";
}

unsigned long long minValue (vector <int> values)
{
	// First we eliminate any duplicates
	vector<int> filteredValues;
	for (int el : values)
		{ // Add non-duplicates to filteredValues
		if (std::find(std::begin(filteredValues), std::end(filteredValues), el)==filteredValues.end()) {filteredValues.push_back(el);}
		}
	// Then we inverse sort filteredValues
	std::sort(filteredValues.begin(), filteredValues.end());

	// Form the final number
	unsigned long long res{ 0 };
	for (int entry : filteredValues) {res*=10; res+=entry;}
	return res; 
}

int main()
{
	std:cout << minValue({1,3,1,7,2,5,7,2,1,3}) << std::endl;
	return 0;
}
