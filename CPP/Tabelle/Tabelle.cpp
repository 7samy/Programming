#include "Tabelle.h"

Tabelle::Tabelle() : head(nullptr), tail(nullptr), current(nullptr) {}

Tabelle::~Tabelle() {
  while (head) {
    Node *tmp = head->next;
    delete head;
    head = tmp;
  }
}

bool Tabelle::first() {
  if (!head)
    return false;
  current = head;
  return true;
}
bool Tabelle::last() {
  if (!tail)
    return false;
  current = tail;
  return true;
}
bool Tabelle::next() {
  if (!current || !current->next)
    return false;
  current = current->next;
  return true;
}
bool Tabelle::previous() {
  if (!current || !current->prev)
    return false;
  current = current->prev;
  return true;
}

bool Tabelle::get_node(item_type &r) {
  if (!current)
    return false;
  r = current->data;
  return true;
}
bool Tabelle::set_node(item_type &r) {
  if (!current)
    return false;
  current->data = r;
  return true;
}

bool Tabelle::append(item_type r) {
  Node *n = new Node{r, tail, nullptr};
  if (tail)
    tail->next = n;
  else
    head = n;
  tail = current = n;
  return true;
}

bool Tabelle::insert(item_type r) {
  if (!current)
    return false;
  Node *n = new Node{r, current->prev, current};
  if (current->prev)
    current->prev->next = n;
  else
    head = n;
  current->prev = n;
  current = n;
  return true;
}

bool Tabelle::delete_node() {
  if (!current)
    return false;
  Node *tmp = current;
  if (current->prev)
    current->prev->next = current->next;
  else
    head = current->next;
  if (current->next)
    current->next->prev = current->prev;
  else
    tail = current->prev;
  current = tmp->next ? tmp->next : tmp->prev;
  delete tmp;
  return true;
}
