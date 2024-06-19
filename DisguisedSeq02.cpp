#include <iostream>
#include <string>

long long comb(int n, int k)
{
	if (n<0 || k<0) return 0;
	if (k>n) return 1;
	long long y = 1;
	long long a = 1;
	for (int i = n ; i>(n-k) ; i--) y*= i;
	for (int i = 1; i<=k; i++) a*=i;
	return y/a;
}

long long powerOfFour(int n, int k)
{
	long long res = 1;
	for(int i=0; i<n-k; i++) res*=4;
	return res;
}


class Disguised2
{
public:
    static long long v1(int n, int p)
	{
		long long sum = 0;
		long long t  = 0;
		for (int k = 0; k<=n; k++)
		{
			sum += (1-2*(k%2))*powerOfFour(n,k)*comb(2*n-k,k); 
		}
		return sum*p;
		//return (1+2*n)*p;		// My guess! 
	}

    static long long u1(int n, int p)
	{
		long long sum = 0;
		long long t  = 0;
		for (int k = 0; k<=n; k++)
		{
			sum += (1-2*(k%2))*powerOfFour(n,k)*comb(2*n-k+1,k); 
		}
		return sum*p;
		// return (1+n)*p
	}
};



int main()
{
	std::cout << Disguised2::u1(1,12)/12 << std::endl;
	std::cout << Disguised2::u1(1,13)/13 << std::endl;
	std::cout << Disguised2::u1(1,14)/14 << std::endl;
	std::cout << Disguised2::u1(2,12)/12 << std::endl;
	std::cout << Disguised2::u1(2,13)/13 << std::endl;
	std::cout << Disguised2::u1(2,14)/14 << std::endl;
	//std::cout << Disguised2::v1(2,138) << std::endl;

	return 0;
}
