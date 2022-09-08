
#include "split.h"
#include <iostream>

void print(Node* l) {
  if (l == nullptr) {
    std::cout << std::endl;
    return;
  }
  std::cout << l->value << " ";
  print(l->next);
}

void free(Node* l) {
  if (l == nullptr) {
    return;
  }
  free(l->next);
  delete l;
}

int main() {
  Node* l = new Node(1, new Node(2, new Node(3, nullptr)));
  print(l);

  Node* odds = nullptr;
  Node* evens = nullptr;
  split(l, odds, evens);
  print(odds);
  print(evens);

  free(l); // optional because split already free l
  free(odds);
  free(evens);
}