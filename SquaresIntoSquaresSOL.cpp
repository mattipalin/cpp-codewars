#include <iostream>
#include <vector>


void printList(const std::vector<long long> &foo)
{
	std::cout << "[";
	for (long long el : foo) std::cout << el << "," ;
	std::cout << "]" << std::endl;
}

class Decomp
{
  public:
  static std::vector<long long> decompose(long long n);
  private:
  static bool Divide(std::vector<long long> &numbers, double remain, long long last);
};

std::vector<long long> Decomp::decompose(long long n)
{
  auto list = std::vector<long long>();
  if (Divide(list, n * n, n))
      return list;
  return std::vector<long long>() = {};
}

bool Decomp::Divide(std::vector<long long> &numbers, double remain, long long last)
{
	std::cout << "remain / last / numbers = " << remain << "/" << last << "/";
	printList(numbers);
    if (remain <= 0)
        return remain == 0;
    for (long long i = last - 1; i > 0; i--)
    {
	std::cout << "i=" << i << std::endl;
        if (Divide(numbers, remain - (i * i), i))
        {
		numbers.push_back(i);
		printList(numbers);
		return true;
        }
    }
	std::cout << "False ... " << std::endl;
    return false;
}

int main()
{
	Decomp::decompose(11);
	//Decomp::decompose(44);
	//Decomp::decompose(2);
	//Decomp::decompose(4);


	return 0;
}
