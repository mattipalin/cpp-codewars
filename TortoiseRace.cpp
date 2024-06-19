#include <iostream>
#include <vector>
#include <math.h>

int printVector(std::vector<int> vec)
{
	std::cout << "(" << vec[0] << "," << vec[1] << "," << vec[2] << ")" << std::endl;
	return 0;
}

std::vector<int> race(int v1, int v2, int g)
{
	if (v1 >= v2)
		return {-1, -1, -1};
	else
	{
		float floatTime = float(g)/float(v2-v1);
		int hours = floor(floatTime);
		int mins = floor(60*(floatTime-hours));
		int secs = floor(60*60*(floatTime-hours) - 60*mins);
		return {hours, mins, secs};
	}
}


int main()
{
	printVector(race(720, 850, 70));
	printVector(race(80, 91, 37));
	return 0;
}


