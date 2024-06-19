#include <iostream>
#include <vector>
#include <cassert>

std::string tickets(const std::vector<int> peopleInLine){
	int twenty = 0; int fifty= 0;	// Count the 25 and 50 dollar bills
	for (int bill : peopleInLine){
		// Case by case ...
		switch (bill){
			case 25:{ twenty++;	break;}
			case 50:{ fifty++; twenty--; break;}
			case 100:{
			// Two cases -- try to give back 50+25
			if (fifty>0){fifty--; twenty--;}
			else {twenty-=3;}
			break;
				}
		};
		if (twenty<0) return "NO";
	}
	return "YES";
}


int main()
{
	std::cout << tickets({25, 25, 50}) << std::endl;			// YES
	std::cout << tickets({25, 100}) << std::endl;				// NO
	std::cout << tickets({25, 25, 50, 50, 100}) << std::endl;		// NO
	std::cout << tickets({25,50,25,50,50,50,50,25,50,25,100,100,50,100,100,100,25,25,25,25,100,}) << std::endl;	// YES
	return 0;
}
