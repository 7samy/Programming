#include "Tabelle.h"
#include <iostream>

int main() {
  Tabelle tab;

  tab.append(10);
  tab.append(20);
  tab.append(30);
  tab.first();
  int val;
  tab.get_node(val);
  std::cout << "first: " << val << std::endl; // 10

  tab.next();
  tab.get_node(val);
  std::cout << "second: " << val << std::endl; // 20

  tab.insert(15); // vor dem aktuellen (20) einfügen
  tab.first();
  while (tab.get_node(val)) {
    std::cout << val << " ";
    if (!tab.next())
      break;
  }
  std::cout << std::endl; // Erwartet: 10 15 20 30

  tab.delete_node(); // löscht current (war nach insert 15)
  tab.first();
  while (tab.get_node(val)) {
    std::cout << val << " ";
    if (!tab.next())
      break;
  }
  std::cout << std::endl; // Erwartet: 10 20 30

  return 0;
}
