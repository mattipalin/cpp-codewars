#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void printList(const std::vector<int> &foo)
{
	std::cout << "[";
	for (int el : foo) std::cout << el << "," ;
	std::cout << "]" << std::endl;
}

bool isPrimeSieve(const int n, const std::vector<int> &primeList)
{
	for (int p : primeList) if (n%p==0) return false;
	return true;
}

bool listIsOnes(const std::vector<int> &lst)
{	// Check if every element of lst is ==1
	for (int el : lst) if (abs(el) != 1) return false;
	return true;
}

class SumOfDivided
{
public:
	static std::string sumOfDivided(std::vector<int> &lst)
	{
		std::vector<std::vector<int>> res; 
		int lstSize = lst.size();
		std::vector<int> aux = lst; 	// A copy of lst, used in determining when to stop
		bool c;
		int sum;
		int prime = 2;
		std::vector<int> primeSieveList;
		while (!listIsOnes(aux))
		{
		primeSieveList.push_back(prime);
		sum 	= 0;
		c 	= false;
		// Check if one or any of the elements in lst are divisible by prime

		for (int i=0; i<lstSize; i++) if (lst[i]%prime ==0) 
		{sum += lst[i]; c = true; 
		while (aux[i]%prime == 0) aux[i] /= prime;
		}

		if (c) 	res.push_back({prime,sum});

		// Then find the next prime
		while (!isPrimeSieve(prime,primeSieveList)) prime++;
		}
		
	// Format the output
	std::string resString = "";

	for (std::vector<int> pair : res)
	{
		resString += "(";
		resString += std::to_string(pair[0]) + " ";
		resString += std::to_string(pair[1]) + ")";
	}

	return resString;
	}
};


int main()
{
	std::vector<int> l = {12,15};
	std::vector<int> k = {38,6,95,17,11};
	
	std::vector<int> l0 = {12,15};
	std::vector<int> l1 = {15,21,24,30,45};
	std::vector<int> l2 = {107,158,204,100,118,123,126,110,116,100};
	std::vector<int> l3 = {};
	std::vector<int> l4 = {-29804,-4209,-28265,-72769,-31744};

	//Expected: equal to (2 -61548)(3 -4209)(5 -28265)(23 -4209)(31 -31744)(53 -72769)(61 -4209)(1373 -72769)(5653 -28265)(7451 -29804)
	//Actual:


	std::cout << SumOfDivided::sumOfDivided(l4) << std::endl;
	return 0;
}
