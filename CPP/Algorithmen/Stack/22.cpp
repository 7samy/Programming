#include "Stack.h"
#include <string>

int eval_postfix(const std::string &expr) {
  Stack<int> s;

  for (char c : expr) {
    if (isdigit(c)) {
      int v = c - '0';
      s.push(v); // Zahl auf Stack
    } else {
      int b = s.pop(); // rechter Operand
      int a = s.pop(); // linker Operand
      int res;
      if (c == '+')
        res = a + b;
      else if (c == '-')
        res = a - b;
      else if (c == '*')
        res = a * b;
      else
        res = a / b;
      s.push(res); // Ergebnis zurück auf Stack
    }
  }
  return s.pop(); // letzter Wert = Ergebnis
}
