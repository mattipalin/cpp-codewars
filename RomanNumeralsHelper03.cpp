#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

void printList(const std::vector<int> &foo)
{
	std::cout << "[";
	for (int el : foo) std::cout << el << "," ;
	std::cout << "]" << std::endl;
}



class RomanNumerals
{
public:
	static std::string toRoman(int n)
	{
		// Let's assume that the largest input is 3999.
		const std::string c1 = "IVXLCDM";
		const std::string c2 = "MMMDCCCLXXXVIII";
		std::string res = " ";
		// Let's put the number in 'slots'
		std::vector<int> slots = {(n/1000)%10, (n/100)%10, (n/10)%10, n%10};
		std::string appended;
		for (int i = 0; i<=3 ; i++)
		{
			appended = "";
			if (slots[i]<4)				{appended = c2.substr(4*i ,slots[i]);}
			else if (slots[i]==4)			{appended = c1.substr(6-2*i, 2);}
			else if (slots[i]>=5 && slots[i]<=8)	{appended = c2.substr(4*i-1,slots[i]-4);}
			else if (slots[i] == 9)
			{
				appended = c1[6-2*i]; res.append(appended);
				appended = c1[8-2*i];
			}
			res.append(appended);
		}
		return res;
	}

	static int fromRoman(const std::string &foo)
	{
		std::cout << "Received string =" << foo << std::endl;
		int res = 0;
		int b   = 0;
		// First, transform foo into stringstream
		std::stringstream s(foo);

		// Detect how many M's in the beginning
		while (s.peek()=='M') {s.ignore();res += 1000;}

		// Now we have the thousands correctly.
		// Next, detect the hundreds. This is a bit trickier ...
		std::string tens = "CXI";
		std::string fives= "DLV";
		int m		 = 1000;
		for (int i = 0; i<3; i++)
		{
			std::cout << "i = " << i << std::endl;
			m /= 10;
			// If the next character is D, add immediately 500
			if (s.peek()==fives[i])
			{
			s.ignore(); res += 5*m;
			while (s.peek()==tens[i]) {s.ignore(); res+=m;}
			}

			else if (s.peek()==tens[i]) 
			{
			std::cout << "I found the letter " << tens[i] << std::endl;
			while (s.peek()==tens[i]) {b += m; s.ignore();}
			// If there is a D after the C's, we calculate the following ...
			if (s.peek()==fives[i]) {res += 5*m - b;}
			else {res += b;}
			b = 0;
			}
		}
		std::cout << "res =" << res << std::endl;
		return res;
	}
};


int main()
{
	std::cout << std::setw(15) << 1987 << "->" << RomanNumerals::fromRoman("MCMLXXXVII") << std::endl;

	return 0;
}
