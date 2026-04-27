#include "Stack.h"
#include <iostream>

int main() {
  Stack<int> s;

  s.push(10);
  s.push(20);
  s.push(30);

  std::cout << "Top: " << s.top() << std::endl;       // 30
  std::cout << "Length: " << s.length() << std::endl; // 3

  std::cout << "Pop: " << s.pop() << std::endl; // 30
  std::cout << "Pop: " << s.pop() << std::endl; // 20

  std::cout << "Empty: " << s.empty() << std::endl;   // false
  std::cout << "Length: " << s.length() << std::endl; // 1

  return 0;
}
