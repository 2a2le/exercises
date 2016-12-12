// Chapter 2 - Linked Lists

#include <iostream>

struct Node {
  int data;
  Node* next = nullptr;
  Node() :data(0) {};
  Node(int data) :data(data) {};

  void appendToTail(int d) {
    Node* end = new Node(d);
    Node* n = this;
    while (n->next != nullptr) {
      n = n->next;
    }
    n->next = end;
  };

  void print() {
    Node* n = this;
    while (n != nullptr) {
      std::cout << n->data << " ";
      n = n->next;
    }
    std::cout << std::endl;
  };
};

Node* deleteNode(Node* head, int d) {
  Node* n = head;

  if (n->data == d) {
    head = head->next; /* moved head */
    delete n;
    return head;
  }

  while (n->next != nullptr) {
    if (n->next->data == d) {
      Node* tmp = n->next; 
      n->next = n->next->next;
      delete tmp; /* deallocated the removed node */
      return head; /* head didn't change */
    }
    n = n->next;
  }
  return head;
}

/*
2.1
Write code to remove duplicates from an unsorted linked list.
FOLLOW UP
How would you solve this problem if a temporary buffer is not allowed?
*/
void deleteDuplicates(Node* head) {
  Node* n1 = head;

  while (n1->next != nullptr) {
    Node* n2 = n1;
    while (n2->next != nullptr) {
      if (n2->next->data == n1->data) {
        Node* tmp = n2->next;
        n2->next = n2->next->next;
        delete tmp;
      }
      if (n2->next != nullptr) {
        n2 = n2->next;
      }
    }
    if (n1->next != nullptr) {
      n1 = n1->next;
    }
  }
}

/*
2.2
Implement an algorithm to find the kth to last element of a singly linked list.
*/
Node* findElement(Node* head, int k) {
  Node* n = head;
  Node* nk = head;
  for (int i=0; i<k; i++) {
    if (n->next == nullptr) {
      return nullptr;
    }
    n = n->next;
  }
  while (n->next != nullptr) {
    n = n->next;
    nk = nk->next;
  }
  return nk;
}

/*
2.3
Implement an algorithm to delete a node in the middle of a singly linked list,
given only access to that node.
EXAMPLE
Input: the node c from the linked list a - > b - > c - > d - >e
Result: nothing is returned, but the new linked list looks like a- >b- >d->e
*/
void deleteElem(Node* n) {
  Node* tmp = n->next;
  n->next = tmp->next;
  n->data = tmp->data;
  delete tmp;
}

/*
2.4
Write code to partition a linked list around a value x, such that all nodes less than
x come before all nodes greater than or equal to x.
*/
Node* partition(Node* n, int x) {
  Node* tmp = nullptr;
  return tmp;
}

int main() {
  Node* n = new Node();
  n->appendToTail(1);
  n->print();
  n->appendToTail(2);
  n->appendToTail(3);
  n->print();
  n = deleteNode(n, 0);
  n->print();
  n = deleteNode(n, 1);
  n->print();
  
  // 2.1
  n->appendToTail(2);
  n->appendToTail(3);
  n->appendToTail(3);
  n->appendToTail(3);
  n->appendToTail(2);
  n->print();
  deleteDuplicates(n);
  n->print();
  
  //2.2
  n->appendToTail(6);
  n->appendToTail(5);
  n->appendToTail(4);
  n->appendToTail(3);
  n->appendToTail(2);
  n->appendToTail(1);
  n->print();
  std::cout << findElement(n, 4)->data << std::endl; 
  std::cout << findElement(n, 0)->data << std::endl; 
  std::cout << findElement(n, 1)->data << std::endl; 

  //2.3
  Node* el = n;
  el = el->next->next;
  n->print();
  std::cout << el->data << std::endl;
  deleteElem(el);
  n->print();
  

  return 0;
}
