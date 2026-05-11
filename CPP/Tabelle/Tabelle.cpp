#include "Tabelle.h"

// Node Konstruktor
Node::Node(const item_type &d, Node *p, Node *n) : data(d), prev(p), next(n) {}

// ---------- Tabelle ----------

Tabelle::Tabelle() : head(nullptr), tail(nullptr), current(nullptr), count(0) {}

Tabelle::~Tabelle() {
  Node *tmp = head;
  while (tmp) {
    Node *next = tmp->next;
    delete tmp;
    tmp = next;
  }
}

bool Tabelle::first() {
  if (count == 0)
    return false;
  current = head;
  return true;
}

bool Tabelle::last() {
  if (count == 0)
    return false;
  current = tail;
  return true;
}

bool Tabelle::next() {
  if (current == nullptr || current->next == nullptr)
    return false;
  current = current->next;
  return true;
}

bool Tabelle::previous() {
  if (current == nullptr || current->prev == nullptr)
    return false;
  current = current->prev;
  return true;
}

bool Tabelle::append(item_type r) {
  Node *newNode = new Node(r);
  if (count == 0) {
    head = tail = current = newNode;
  } else {
    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
  }
  ++count;
  return true;
}

bool Tabelle::insert(item_type r) {
  // Einfügen nur möglich, wenn current existiert
  if (current == nullptr)
    return false;

  Node *newNode = new Node(r);

  if (current == head) {
    // Einfügen vor dem ersten Element
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
  } else {
    // Einfügen in der Mitte oder vor tail
    newNode->prev = current->prev;
    newNode->next = current;
    current->prev->next = newNode;
    current->prev = newNode;
  }
  current = newNode;
  ++count;
  return true;
}

bool Tabelle::delete_node() {
  if (current == nullptr || count == 0)
    return false;

  Node *toDelete = current;

  if (count == 1) {
    head = tail = current = nullptr;
  } else if (current == head) {
    head = head->next;
    head->prev = nullptr;
    current = head;
  } else if (current == tail) {
    tail = tail->prev;
    tail->next = nullptr;
    current = tail;
  } else {
    current->prev->next = current->next;
    current->next->prev = current->prev;
    current = current->next;
  }

  delete toDelete;
  --count;
  return true;
}

bool Tabelle::get_node(item_type &r) const {
  if (current == nullptr)
    return false;
  r = current->data;
  return true;
}

bool Tabelle::set_node(const item_type &r) {
  if (current == nullptr)
    return false;
  current->data = r;
  return true;
}
