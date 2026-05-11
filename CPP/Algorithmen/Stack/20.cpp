// Stack.h
template <class item_type> class Stack {
  struct node {
    item_type item;
    node *next;
  };
  node *tail;
  int anz_items;

public:
  Stack() : tail(nullptr), anz_items(0) {}

  ~Stack() {
    while (tail) {
      node *tmp = tail->next;
      delete tail;
      tail = tmp;
    }
  }

  void push(item_type &r) {
    node *n = new node{r, tail};
    tail = n;
    anz_items++;
  }

  item_type pop() {
    node *tmp = tail;
    item_type val = tail->item;
    tail = tail->next;
    delete tmp;
    anz_items--;
    return val;
  }

  item_type top() { return tail->item; }
  int length() { return anz_items; }
  bool empty() { return tail == nullptr; }
};
