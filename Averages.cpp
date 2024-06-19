#include <vector>
#include <iostream>

double calcAverage(const std::vector<int>& values){
	int s{ 0 };
	for (int entry : values) {s+=entry;}
	return static_cast<float>(s)/values.size();
}

int main()
{
        std::cout << calcAverage({2,5}) << std::endl;
        std::cout << calcAverage({5}) << std::endl;
        std::cout << calcAverage({4,2,1}) << std::endl;
        std::cout << calcAverage({3,2,5,1}) << std::endl;
        std::cout << calcAverage({3,2,3,5,1}) << std::endl;
        std::cout << calcAverage({3,4,2,4,5}) << std::endl;
	return 0;
}
