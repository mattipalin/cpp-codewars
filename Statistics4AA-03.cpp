#include <iostream>
#include <string>
#include <sstream>
#include <vector>


void printVector(std::vector<int> v)
{
	std::cout << "(";
	for (auto el : v) std::cout << el << "," ; 
	std::cout << ")" << std::endl;
}

std::string convertToHourNotation(int x) 
{
	if (x<0) return {0, 0, 0};
	int seconds = x % 60;
	int minutes = (x-seconds)/60 % 60;
	int hours = int(x/3600);

	std::stringstream outputString;
	if (hours<10) outputString << "0";
	outputString << hours << "|";
	if (minutes<10) outputString << "0";
	outputString << minutes << "|";
	if (seconds<10) outputString << "0";
	outputString << seconds;
	return outputString.str();
}

int mean(std::vector<int> &v)
{
	int sum = 0;
	for (auto el : v) sum += el;
	return int(sum/v.size());
}

int range(std::vector<int> &v)
{
	if (v.size()==0) return 0;
	int min = v[0];
	int max = v[0];
	for (auto el : v)
	{
		if (el<min) min = el;
		if (el>max) max = el;
	}
	return max-min;
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
	std::cout << "----- pivot =" << pivot << std::endl;
	// Check the size of the left set
	if (left.size()==1 && right.size()==1) return (k==0)? left[0] : right[0];
	if (left.size()>k) return findKMedian(left, k);
	if (left.size()<=k)return findKMedian(right, k - left.size() );
}

int findMedian(std::vector<int> f)
{	// A wrapper function for finding the real median
	int res = 0;
	if (f.size()%2==0) res = (findKMedian(f, f.size()/2) + findKMedian(f,f.size()/2-1))/2.0;
	else res = findKMedian(f,(f.size()-1)/2);
	return int(res);	
}


int interpretTwoDigits(const std::string &f)
{	
	std::cout << "interpret:" << f << std::endl;
	return std::stoi(f.c_str());
}

int interpretTimeEntry(const std::string &f)
{	// Input is in the form "xx|yy|zz" with possibly leading zeros or spaces

	std::stringstream ss(f);		// Convert to strinstream
	while (ss.peek()==' ') ss.ignore();	// Eliminate leading spaces

	std::string twoChars;			// Create a string buffer for the values
	std::string oneChar;
	while (ss.peek()!='|')			// Interpret hours
	{
		oneChar = ss.get();
		twoChars.append(oneChar);
	}
	int hours = std::stoi(twoChars.c_str());
	ss.ignore(); twoChars.clear();

	while (ss.peek()!='|')			// Interpret minutes
	{
		oneChar = ss.get();
		twoChars.append(oneChar);
	}
	int minutes = std::stoi(twoChars.c_str());
	ss.ignore(); twoChars.clear();

	while (ss.peek()!='|' && ss.peek()!=-1)	// Interpret seconds
	{
		oneChar = ss.get();
		twoChars.append(oneChar);
	}
	int seconds = std::stoi(twoChars.c_str());
	return 60*60*hours + 60*minutes + seconds; 	// Return the value in seconds
}

class Stat
{
public:
	static std::string stat(const std::string &strg);
};

static std::string stat(const std::string &strg)
	{
	std::stringstream ss(strg);	// Convert input string to stringstream
	std::vector<int> teamValues;

	std::string buffer;		// Buffer for an individual time entry
	std::string oneChar;		// a single character buffer
	while (ss)
	{
		// Read one time entry (h|min|sec)
		buffer.clear();
		oneChar.clear();
		while (ss && ss.peek()!=44 && ss.peek()!=-1)
		{
			//std::cout << "peek=" << ss.peek() << std::endl;
			oneChar=ss.get();
			buffer.append(oneChar);
		}
		teamValues.push_back(interpretTimeEntry(buffer));
		ss.ignore();
	}
	//printVector(teamValues);

	// Prepare the output
	std::stringstream outputString;
	outputString <<   "Range: " << convertToHourNotation(range(teamValues));
	outputString <<" Average: " << convertToHourNotation(mean(teamValues)  );
	outputString << " Median: " << convertToHourNotation(findMedian(teamValues));
	
	return outputString.str();
	}


int main()
{
	std::string a = "01|15|59, 1|47|16, 01|17|20, 1|32|34, 2|17|17";
	std::string b = "02|15|59, 2|47|16, 02|17|20, 2|32|34, 2|32|34, 2|17|17";	// Range: 00|31|17 Average: 02|27|10 Median: 02|24|57
	std::cout << stat(a) << std::endl;
	std::cout << stat(b) << std::endl;
	
	return 0;
}
