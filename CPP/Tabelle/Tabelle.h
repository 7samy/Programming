#pragma once
typedef int item_type;

struct Node {
  item_type data;
  Node *prev, *next;
};

class Tabelle {
  Node *head, *tail, *current;

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
  bool get_node(item_type &r);
  bool set_node(item_type &r);
};
