#ifndef LINKLIST_H
#define LINKLIST_H

class Node {
  public:
    int value;
  int coloumnIndex;
  Node * nextInRow;

  Node() {
    nextInRow = nullptr;
  }
  Node(int value, int coloumnIndex) {
    this -> value = value;
    this -> coloumnIndex = coloumnIndex;
     nextInRow = nullptr;
  }
};

class linkList {
  public:
    Node * head;
  Node * tail;
  int size;

  linkList() {
    this -> head = nullptr;
    this -> tail = nullptr;
    this -> size = 0;
  }

  void addFirst(Node * temp) {
    temp -> nextInRow = head;
    head = temp;
    if (size == 0) {
      tail = head;
    }
    this -> size++;
  }
  void addLast(Node * temp) {

    if (size == 0) {
      head = temp;
      temp -> nextInRow = nullptr;
    } else {
      tail -> nextInRow = temp;
    }
    tail = temp;

    this -> size++;
  }

};

#endif // LINKLIST_H
