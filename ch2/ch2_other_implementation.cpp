// Chapter 2 - Linked Lists

#include <iostream>

class Linked {
private:
  struct Node {
    int   data;
    Node* next;
    Node(int data, Node* next)
        :data(data), next(next) {};
  };

  Node* head;

public:
  Linked() :head(nullptr) {}
  ~Linked() {
    Node *tmp;
    for (;head;head = tmp) {
      tmp = head->next;
      delete head;
    }
  }
  void appendToTail(int);
  void print();
  void deleteNode(int);
};

void Linked::appendToTail(int d) {
  if (head == nullptr) {
    head = new Node(d, nullptr);
  } else {
    Node* n = head;
    while (n->next) {
      n = n->next;
    }
    n->next = new Node(d, nullptr);
  }
}

void Linked::deleteNode(int d) {
  if (head == nullptr) return;
  Node* tmp = head;
  if (tmp->data == d) {
    head = tmp->next; /* moved head */
    delete tmp;       /* deallocated the removed node */
    return;
  }
  while (tmp->next) {
    if (tmp->next->data == d) {
      delete tmp->next; /* deallocated the removed node */
      tmp->next = tmp->next->next;
      return;
    }
    tmp = tmp->next;
  }
}

void Linked::print() {
  Node* tmp = head;
  while (tmp) {
    std::cout << tmp->data << " ";
    tmp = tmp->next;
  }
  std::cout << std::endl;
}

int main() {
  Linked list;
  list.appendToTail(1);
  list.appendToTail(2);
  list.appendToTail(3);
  list.print();
  list.deleteNode(2);
  list.print();
  list.deleteNode(1);
  list.print();

  return 0;
}
