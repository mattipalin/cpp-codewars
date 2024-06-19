#include <iostream>
#include <algorithm>

int powerMod(long long a, long long b, long long n)
{
	int r = 1;
	while (b>0)
	{
		if (b & 2== 1) r = r * a % n; // Odd number
		b /= 2;
		a = a * a % n;
	}
	return r;
}


bool is_prime(long long n)
{	// Checks if a number is prime
	if (n==1 || n==0) return false; 
	std::vector<int> primeList {2,3,5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73};
	
	// Phase 1: Check if number is in the list
	if (n >= 73 && std::find(primeList.begin(), primeList.end(), n) != primeList.end())
		return true;

	// Phase 2: Calculate the remainder with the numbers in primeList
	for (int divisor : primeList)
		if (n % divisor ==0) return false;


	// Phase 3: Fermat's primality test
	if (powerMod(3, n - 1 , n)!=1)
	{
		std::cout << std::endl;
		return false;
	}
	if (powerMod(5 , n - 1 , n)!=1) return false;
	if (powerMod(7 , n - 1 , n)!=1) return false;
	if (powerMod(11, n - 1 , n)!=1)	return false;
	if (powerMod(13 , n - 1 , n)!=1) return false;
	return true;
}

int nextPrime(long long n)
{
	int t = n + 1;
	while(!is_prime(t)) t+=1;
	return t;
}

class GapInPrimes
{
public:
    static std::pair <long long, long long> gap(int g, long long m, long long n);
};



std::pair<long long, long long> gap(long long g, long long m, long long n)
{
	long long l = nextPrime(m);
	long long u;
	while(l<n)
	{
		u = nextPrime(l);
		if (u -l == g) return {l, u};
		else l = u;
	}
	return {0, 0};
}


void printPair(std::pair<long long, long long> &foo)
{
	std::cout << "(" << std::get<0>(foo) << "," << std::get<1>(foo) << ")" << std::endl;
}

int main()
{
	std::pair<long long, long long> pair;
	pair = gap(2,100,110); printPair(pair); //{101, 103});
	pair = gap(4,100,110); printPair(pair);//{103, 107});
	pair = gap(6,100,110); printPair(pair);//{0, 0});
	pair = gap(8,300,400); printPair(pair);//{359, 367});
	pair = gap(10,300,400); printPair(pair);//{337, 347});
	pair = gap(6,30000,100000); printPair(pair);
	pair = gap(8,30000,100000);printPair(pair);
	pair = gap(11,30000,100000);printPair(pair);

	std::cout << std::endl;
	
	pair = gap(7,558080,608080); printPair(pair);
	pair = gap(6,583929,633929);printPair(pair);

	return 0;
}
