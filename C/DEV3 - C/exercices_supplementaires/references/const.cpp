#include <iostream>


int main() {
	int i = 33;
	int &ri = i;
	std::cout << ri << std::endl;
	i++;
	int x = 2;
	ri = x;
	std::cout << ri << std::endl;

}
