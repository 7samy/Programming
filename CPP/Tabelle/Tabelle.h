#ifndef TABELLE_H
#define TABELLE_H

#include <cstddef> // <-- das fehlende Include für size_t

typedef int item_type;

struct Node {
  item_type data;
  Node *prev;
  Node *next;
  Node(const item_type &d = item_type(), Node *p = nullptr, Node *n = nullptr);
};

class Tabelle {
private:
  Node *head;
  Node *tail;
  Node *current;
  size_t count;

public:
  Tabelle();
  ~Tabelle();

  bool insert(item_type r);
  bool append(item_type r);
  bool first();
  bool last();
  bool next();
  bool previous();
  bool delete_node();
  bool get_node(item_type &r) const;
  bool set_node(const item_type &r);
};

#endif
