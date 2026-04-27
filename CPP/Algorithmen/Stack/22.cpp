#include "Stack.h"
#include <cctype>
#include <iostream>
#include <stdexcept>
#include <string>

double applyOperator(double a, double b, char op) {
  switch (op) {
  case '+':
    return a + b;
  case '-':
    return a - b;
  case '*':
    return a * b;
  case '/':
    if (b == 0)
      throw std::runtime_error("Division durch Null!");
    return a / b;
  default:
    throw std::runtime_error("Unbekannter Operator");
  }
}

double evaluatePostfix(const std::string &postfix) {
  Stack<double> s;

  for (char ch : postfix) {

    if (std::isdigit(ch)) {
      s.push(static_cast<double>(ch - '0')); // '3' -> 3.0
    }

    else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
      if (s.length() < 2) {
        throw std::runtime_error("Ungültiger Ausdruck: Zu wenige Operanden");
      }

      double b = s.pop();
      double a = s.pop();

      double result = applyOperator(a, b, ch);
      s.push(result);
    }

    else if (std::isspace(ch)) {
      continue;
    } else {
      throw std::runtime_error("Ungültiges Zeichen im Ausdruck");
    }
  }

  if (s.length() != 1) {
    throw std::runtime_error("Ungültiger Ausdruck: Zu viele Operanden übrig");
  }

  return s.pop();
}

int main() {
  try {
    std::string expr1 = "48*8+42/+";
    std::string expr2 = "34+2*";
    std::cout << "Ausdruck: " << expr2 << std::endl;
    std::cout << "Ergebnis: " << evaluatePostfix(expr2) << std::endl;

    std::string expr3 = "152*/";
    std::cout << "\nAusdruck: " << expr3 << std::endl;
    std::cout << "Ergebnis: " << evaluatePostfix(expr3) << std::endl;

  } catch (const std::exception &e) {
    std::cerr << "Fehler: " << e.what() << std::endl;
  }

  return 0;
}
