#include <iostream>       // std::cout
#include <queue>          // std::priority_queue
#include <vector>         // std::vector
#include <functional>     // std::greater
 
int main() {
	
	int myints[] = {10, 60, 50, 20};
 
	std::priority_queue<int> intPQueue1(myints, myints+4);
	std::priority_queue<int, std::vector<int>, std::greater<int> > intPQueue2(myints,myints+4);
 
	std::cout << "less than: " << std::endl;
	while (!intPQueue1.empty()) {
		int pvalue = intPQueue1.top();
		std::cout << pvalue << " ";
		intPQueue1.pop(); 
	}
	std::cout << std::endl;
 
	std::cout << "bigger than: " << std::endl;
	while (!intPQueue2.empty()) {
		int pvalue = intPQueue2.top();
		std::cout << pvalue << " ";
		intPQueue2.pop(); 
	}
	std::cout << std::endl;
 
	return 0;
}