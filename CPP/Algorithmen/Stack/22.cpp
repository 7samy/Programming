#include "Stack.h"
#include <cctype>
#include <iostream>
#include <stdexcept> // Für Exceptions falls nötig
#include <string>

// Hilfsfunktion: Führe eine Operation aus
double applyOperator(double a, double b, char op) {
  switch (op) {
  case '+':
    return a + b;
  case '-':
    return a - b; // Wichtig: a - b (nicht b - a!)
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

// Hauptfunktion: Postfix Auswertung
double evaluatePostfix(const std::string &postfix) {
  Stack<double> s; // Stack für Zahlen

  for (char ch : postfix) {
    // 1. Wenn es eine Ziffer ist (oder Teil einer Zahl)
    // Hinweis: Dieser einfache Code geht von einstelligen Zahlen aus (0-9)
    // Für mehrstellige Zahlen müsste man den String parsen (z.B. mit
    // Leerzeichen trennen)
    if (std::isdigit(ch)) {
      s.push(static_cast<double>(ch - '0')); // '3' -> 3.0
    }
    // 2. Wenn es ein Operator ist
    else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
      if (s.length() < 2) {
        throw std::runtime_error("Ungültiger Ausdruck: Zu wenige Operanden");
      }

      double b = s.pop(); // Zweiter Operand (oben)
      double a = s.pop(); // Erster Operand (darunter)

      double result = applyOperator(a, b, ch);
      s.push(result);
    }
    // Leerzeichen ignorieren
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

// Test in main.cpp
int main() {
  try {
    // Beispiel 1: a b * b + a c / +  (aus Aufgabe 23a, aber als Zahlen)
    // Angenommen a=4, b=8, c=2
    // Infix: 4 * 8 + 8 + 4 / 2
    // Postfix: 4 8 * 8 + 4 2 / +

    std::string expr1 = "48*8+42/+";
    // Achtung: Dieser Code unterstützt nur einstellige Zahlen ohne
    // Trennzeichen. Für "4 8 * ..." mit Leerzeichen müsste man den Parser
    // anpassen. Machen wir es einfacher mit einstelligen Zahlen:

    std::string expr2 = "34+2*"; // (3+4)*2 = 14
    std::cout << "Ausdruck: " << expr2 << std::endl;
    std::cout << "Ergebnis: " << evaluatePostfix(expr2) << std::endl;

    std::string expr3 = "152*/"; // 15 / 2 = 7.5
    std::cout << "\nAusdruck: " << expr3 << std::endl;
    std::cout << "Ergebnis: " << evaluatePostfix(expr3) << std::endl;

  } catch (const std::exception &e) {
    std::cerr << "Fehler: " << e.what() << std::endl;
  }

  return 0;
}
