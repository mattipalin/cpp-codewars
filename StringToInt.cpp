#include <iostream>
#include <string>
#include <sstream>
#include <vector>

int stringToInt(std::string &f)
{
	return std::stoi(f);
}


int main()
{
	std::string t;

	t = "001"; std::cout << stringToInt(t) + 2 << std::endl;
	t = "008"; std::cout << stringToInt(t) + 2 << std::endl;
	t = "016"; std::cout << stringToInt(t) + 2 << std::endl;


	return 0;
}
