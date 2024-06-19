#include <iostream>
#include <vector>

bool binarySearch(int x, const std::vector<int> &list)
{	// Finds an element in an ordered list by binary search
	int min=0;
	int max=list.size();
	int testindex;
	int obtainedValue;

	while (true)
	{	
		testindex = (max+min)/2;
		obtainedValue = list[testindex];
		if (obtainedValue == x) return true;
		if (max-min==1) return false;
		if (obtainedValue < x) {min = testindex; continue;}
		if (obtainedValue > x) max = testindex;
		else return false;
	}
	return false;
}


class DoubleLinear
{
public:
	static int dblLinear(int n)
	{
		if (n==0) return 1;
		// Idea: create a list of length n
		// Start with 1 and then iterate through integers until length is n
		std::vector<int> mem; mem.push_back(1);
		int i = 1;
		while (mem.size()<=n)
		{
			// check if (i-1)/2 or (i-1)/3 are in mem
			if (( i%2==1 && binarySearch((i-1)/2, mem)) || ( i%3==1 && binarySearch((i-1)/3, mem)))
				// if found, add i to the end of mem
				mem.push_back(i);
			i++;
		}
		return mem.back();
	}
};


int main()
{
	for (int i = 0; i < 2000 ; i++)
		std::cout << DoubleLinear::dblLinear(32768) << std::endl;
	return 0;
}
