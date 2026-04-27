#ifndef STACK_H
#define STACK_H

#include <cstdlib>  // Für exit() falls nötig, oder einfach std::cerr
#include <iostream> // Für std::cerr

template <class item_type> class Stack {
  struct node {
    item_type item;
    node *next;
  };

private:
  node *tail;
  int anz_items;

public:
  // Konstruktor
  Stack() {
    tail = nullptr;
    anz_items = 0;
  }

  // Destruktor
  ~Stack() {
    while (!empty()) {
      pop();
    }
  }

  // push: Element oben drauf
  void push(const item_type &r) {
    node *neu = new node;
    neu->item = r;
    neu->next = tail;
    tail = neu;
    anz_items++;
  }

  // pop: Element oben runter
  item_type pop() {
    if (empty()) {
      std::cerr << "Fehler: Stack ist leer!" << std::endl;
      return item_type(); // Gibt einen Standardwert zurück (z.B. 0 bei int)
    }
    node *temp = tail;
    item_type result = temp->item;
    tail = tail->next;
    delete temp;
    anz_items--;
    return result;
  }

  // top: Nur ansehen
  item_type top() {
    if (empty()) {
      std::cerr << "Fehler: Stack ist leer!" << std::endl;
      return item_type();
    }
    return tail->item;
  }

  int length() { return anz_items; }

  bool empty() { return (anz_items == 0); }
}; // <-- Das Semikolon hier ist WICHTIG!

#endif
