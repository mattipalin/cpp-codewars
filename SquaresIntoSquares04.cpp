#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

void printList(const std::vector<long long> &foo)
{
	std::cout << "[";
	for (long long el : foo) std::cout << el << "," ;
	std::cout << "]" << std::endl;
}

long long calculateNextTry(const std::vector<long long> &list, long long &lastTry, const long long goal, const long long squaredSum)
{
	if (list.empty()) return goal - 1 ;
	long long max = sqrt(goal*goal - squaredSum); // Find the largest square that still fits
	return std::min(std::min(goal+1, max+1), lastTry--)-1;
}

class Decomp
{
public:
	static std::vector<long long> decompose(long long n)
	{
	long long squaredSum 	= (n-1)*(n-1);
	long long lastTry	= n-1;
	long long addedNumber	= 0;
	long long remaining	= n;
	std::vector<long long> l= {n-1}; 

	do
	{
		if (remaining < 0 || l.front()<2) return {};
		if (l.back()==1)
		{
			l.pop_back();
			l.back()--;
			lastTry = l.back();

			squaredSum = 0;
			for (long long el : l) squaredSum += el*el;
			remaining = n*n - squaredSum;
		}

		if (l.back()!=1)
		{
			// Let's add a number to the end of the list ...
		
			addedNumber = calculateNextTry(l, lastTry, n,squaredSum);
			l.push_back(addedNumber); lastTry = addedNumber;

			squaredSum = 0;
			for (long long el : l) squaredSum += el*el;
			remaining = n*n - squaredSum;

		}
		printList(l);
		std::cin.ignore();
	} while (remaining != 0);
	std::reverse(l.begin(),l.end());
	return l;
	}
};

int main()
{
	//Decomp::decompose(50);
	//Decomp::decompose(44);
	//Decomp::decompose(2);
	Decomp::decompose(4);


	return 0;
}
