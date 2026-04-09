#include <iostream>

void test(int& a){
		a = 11;
		std::cout << &a << std::endl;
}

int main(){

		int x = 5;
		test(x);
		std::cout << &x << std::endl;
		std::cout << x << std::endl;
}
