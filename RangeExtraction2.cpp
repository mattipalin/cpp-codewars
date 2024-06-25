#include <string>
#include <vector>
#include <iostream>


std::string printVector(std::vector<int> v){
	std::string res{"{"};
	for(int el : v){res+=std::to_string(el)+",";}
	res+="}";
	//std::cout << res << std::endl;
	return res;
}

std::string range_extraction(std::vector<int> args) {
	std::vector<int> container = {};
	std::string res{};
	for(int el : args){
		// Flush container to res
		if(not(container.empty()) && el != container.back()+1) {
			if(container.size()>2){res+=std::to_string(container[0])+"-"+std::to_string(container.back())+",";}
			else{for(int c : container){res+=std::to_string(c)+",";}}
			container={};
			}
		// Adding to container
		if (container.empty() || el == container.back()+1){container.push_back(el);}
	}
	// Flush one last time
	if(container.size()>2){res+=std::to_string(container[0])+"-"+std::to_string(container.back())+",";}
	else{for(int c : container){res+=std::to_string(c)+",";}}
	if(res.length()){res.pop_back();} // remove last comma
	return res;
}

int main(){
	std::vector<int> t = {1,2,3,5,7,9,10,11,12,13,14,15,16,19,20,25,26,27,29,30,31,32,33};
	std::cout << range_extraction(t) << std::endl;
	return 0;
}
