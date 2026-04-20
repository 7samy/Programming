#include <iostream>


int main(){

  int a {42};
  std::cout << a << std::endl;
  int &b {a};
  const int &c {a};
  

  a = 1;
  b = 2;



  std::cout << a << std::endl;
  std::cout << c << std::endl;

}
