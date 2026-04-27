#ifndef STACK_H
#define STACK_H

#include <cstdlib>
#include <iostream>

template <class item_type> class Stack {
  struct node {
    item_type item;
    node *next;
  };

private:
  node *tail;
  int anz_items;

public:
  Stack() {
    tail = nullptr;
    anz_items = 0;
  }

  ~Stack() {
    while (!empty()) {
      pop();
    }
  }

  void push(const item_type &r) {
    node *neu = new node;
    neu->item = r;
    neu->next = tail;
    tail = neu;
    anz_items++;
  }

  item_type pop() {
    if (empty()) {
      std::cerr << "Fehler: Stack ist leer!" << std::endl;
      return item_type();
    }
    node *temp = tail;
    item_type result = temp->item;
    tail = tail->next;
    delete temp;
    anz_items--;
    return result;
  }

  item_type top() {
    if (empty()) {
      std::cerr << "Fehler: Stack ist leer!" << std::endl;
      return item_type();
    }
    return tail->item;
  }

  int length() { return anz_items; }

  bool empty() { return (anz_items == 0); }
};

#endif
