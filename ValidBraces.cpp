#include <iostream>
#include <string>

bool valid_braces(std::string braces) 
{	// Approach: remove the pairs "()", "{}" and "[]" iteratively
	std::string aux = braces;
	std::string searchables[3] = {"()", "{}", "[]"};
	std::string old;

	do
	{
		old = aux;
		for (std::string p : searchables)
		{
			std::size_t found= aux.find(p);
			if (found != std::string::npos) aux.erase(found,2);
		}
	}
	while (old!=aux);

	std::cout << aux << std::endl;
	return aux.empty();	// Managed to remove all parentheses?
}

int main()
{

	if(valid_braces("([(])")) std::cout << "True." << std::endl;
	if(valid_braces("(){}{{)[])")) std::cout << "True." << std::endl;
	return 0;
}
