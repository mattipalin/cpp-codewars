#include <string>
#include <iostream>
#include <map>


int main()
{
	std::map<char, char> dnamap= { {'A','T'}, {'C','G'}, {'T', 'A'}, {'G','C'}};
	std::string jees = "TAATTA";
	std::cout << dnamap[jees[0]] << std::endl;


	std::cout << dnamap['A'] << std::endl;
	std::cout << dnamap['T'] << std::endl;
	std::cout << dnamap['C'] << std::endl;
	std::cout << dnamap['G'] << std::endl;
	return 0;
}
