#include "Stack.h"
#include <string>

int precedence(char c) {
  if (c == '+' || c == '-')
    return 1;
  if (c == '*' || c == '/')
    return 2;
  return 0;
}

std::string infix_to_postfix(const std::string &expr) {
  Stack<char> s;
  std::string result;

  for (char c : expr) {
    if (isalnum(c)) {
      result += c; // Operand direkt ausgeben
    } else if (c == '(') {
      s.push(c); // Klammer auf Stack
    } else if (c == ')') {
      while (!s.empty() && s.top() != '(') // alles bis '(' ausgeben
        result += s.pop();
      s.pop(); // '(' wegwerfen
    } else {   // Operator
      while (!s.empty() && precedence(s.top()) >= precedence(c))
        result += s.pop(); // höhere Priorität zuerst raus
      s.push(c);
    }
  }
  while (!s.empty())
    result += s.pop(); // Rest ausgeben
  return result;
}
