#include "Stack.h"
#include <cctype>
#include <iostream>
#include <string>

int getPriority(char op) {
  if (op == '+' || op == '-')
    return 1;
  if (op == '*' || op == '/')
    return 2;
  return 0;
}

std::string infixToPostfix(const std::string &infix) {
  Stack<char> s;
  std::string postfix = "";

  for (char ch : infix) {
    if (std::isalnum(ch)) {
      postfix += ch;
    }

    else if (ch == '(') {
      s.push(ch);
    }

    else if (ch == ')') {
      while (!s.empty() && s.top() != '(') {
        postfix += s.pop();
      }
      if (!s.empty()) {
        s.pop();
      }
    }

    else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {

      while (!s.empty() && s.top() != '(' &&
             getPriority(s.top()) >= getPriority(ch)) {
        postfix += s.pop();
      }
      s.push(ch);
    }
  }

  while (!s.empty()) {
    postfix += s.pop();
  }

  return postfix;
}

int main() {
  std::string input = "a+b*c";
  std::string result = infixToPostfix(input);

  std::cout << "Infix:  " << input << std::endl;
  std::cout << "Postfix: " << result << std::endl;

  input = "(a+b)*c";
  result = infixToPostfix(input);
  std::cout << "\nInfix:  " << input << std::endl;
  std::cout << "Postfix: " << result << std::endl;

  return 0;
}
