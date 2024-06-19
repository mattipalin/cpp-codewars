#include <iostream>
#include <set>


int main()
{
	std::set<int> A {3,1,4,2,3,4,5};
	for (int el : A) {std::cout << el << ", ";}
	return 0;
}
