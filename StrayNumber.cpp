#include <iostream>
#include <vector>

int stray(std::vector<int> numbers) 
{
	// Take a sliding window of size 3 and compare the three terms.
	// The starting index of the window is i.
	for (int i=0; i<numbers.size()-2; i++)
	{
	if      (numbers[i]  !=numbers[i+1])	return numbers[i]  +numbers[i+1]-numbers[i+2];
	else if (numbers[i+1]!=numbers[i+2])	return numbers[i+2]+numbers[i+1]-numbers[i];
	}
}


int main()
{
	std::cout << stray({1, 1, 2}) << std::endl;
	std::cout << stray({2, 2, 0}) << std::endl;
	std::cout << stray({5, 4, 4, 4, 4}) << std::endl;
	std::cout << stray({4, 5, 5, 5, 5}) << std::endl;
	std::cout << stray({0, 0, 0, 4, 0, 0, 0}) << std::endl;
	return 0;
}
