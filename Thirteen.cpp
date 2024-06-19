#include <iostream>
#include <string>
#include <vector>



int reduce(int n)
{	// Calculates the sum of (digit * coefficient)
	int c[6] = {1, 10, 9, 12, 3, 4};
	int l   = n;
	int d   = 0;
	int sum = 0;
	int i   = 0;
	while (l > 0)
	{
		d = l%10; 		// Extract last digit
		sum += d * c[i%6]; 	// Multiply d by the correct coefficient and add t to the sum
		l = (l-d)/10; 		// Calculate the new l
		i ++;
	}
	return sum;
}

class Thirteen
{
public:
	static long long thirt(long long n)
	{
		int newValue = n;
		int oldValue = 0;
		do
		{	
			oldValue = newValue;
			newValue = reduce(newValue);
		}
		while (newValue!=oldValue);
		
	}
};







int main()
{
	std::cout << reduce(1234567) << std::endl;
	std::cout << Thirteen::thirt(1234567) << std::endl;

	std::cout << Thirteen::thirt(8529) << std::endl;//, 79);
	std::cout << Thirteen::thirt(85299258) << std::endl;//, 31);
	std::cout << Thirteen::thirt(5634) << std::endl;//, 57);
	std::cout << Thirteen::thirt(1111111111) << std::endl;//, 71);
	std::cout << Thirteen::thirt(987654321) << std::endl;//, 30);
	return 0;
}
