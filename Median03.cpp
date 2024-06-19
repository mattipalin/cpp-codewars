#include <iostream>
#include <string>
#include <vector>


std::string vectorToString(std::vector<int> v)
{
	std::string out;
	out.append("(");
	for (auto el : v)
	{
		out.append(std::to_string(el)); out.append(",");
	}
	out.append(")");
	return out;
}


int findKMedian(std::vector<int> S, int k)
{	// We want to find the k:th smallest value
	if (S.size()==1) return S[0];
	if (k>=S.size()) return -1 ; // k exceeded the size of S ?!
	std::vector<int> left;
	std::vector<int> right;
	int pivotIndex = 0;	
	int pivot;

	do
	{	if (pivotIndex>S.size()) return S[0]; // All elements are the same in S
		left.clear(); right.clear();
		pivot = S[pivotIndex];
		for (auto el : S)	// Split the set to left and right
		{	if (el<pivot) left.push_back(el);
			if (el>=pivot) right.push_back(el);
		}
	pivotIndex++;
	} while (left.size()==0);
	
	// Check the size of the left set
	if (left.size()==1 && right.size()==1) return (k==0)? left[0] : right[0];
	if (left.size()>k) return findKMedian(left, k);
	if (left.size()<=k)return findKMedian(right, k - left.size() );
}

int findMedian(std::vector<int> f)
{	// A wrapper function for finding the real median
	double res = 0;
	if (f.size()%2==0) res = (findKMedian(f, f.size()/2) + findKMedian(f,f.size()/2+1))/2.0;
	else res = findKMedian(f,(f.size()-1)/2);
	return int(res);	
}


int main()
{
	std::vector<int> l = {28,67,84,23,12,50,84,44,13,53,37,43,83};
	std::cout << "Set = " << vectorToString(l) << std::endl;
	
	std::cout << findMedian(l) << std::endl;



	//std::cout << "Set = " << vectorToString(l) << std::endl;
	//std::cout << findMedian(l, 7) << std::endl;
	return 0;
}
