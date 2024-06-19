#include <iostream>
#include<string>

void countLetterOccurances(const std::string& s, int (&list)[25])
{	// Saves the number of letter occurrances to the list
	int length = s.length();
	for (int i=0; i<length; i++) list[int(s[i]) - 97]++;
}

bool scramble(const std::string& s1, const std::string& s2){
  // Calculates the letter occurances of each string and compares them
	int firstWordOccurances[25] {0};
	int secondWordOccurances[25] {0};
	countLetterOccurances(s1, firstWordOccurances);
	countLetterOccurances(s2, secondWordOccurances);
	for (int i=0; i<25; i++)
		if (firstWordOccurances[i] < secondWordOccurances[i]) return false;
	return true;
}

int main()
{
	std::cout << scramble("rkqodlw", "world") << std::endl;
	std::cout << scramble("cedewaraaossoqqyt", "codewars") << std::endl;
	std::cout << scramble("katas", "steak") << std::endl;
	std::cout << scramble("scriptjavx", "javascript") << std::endl;
	std::cout << scramble("scriptingjava", "javascript") << std::endl;
	return 0;
}
