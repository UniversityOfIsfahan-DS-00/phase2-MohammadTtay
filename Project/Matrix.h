#include<iostream>

#include<QString>

#include<QFile>

#include<QTextStream>

#include<vector>

#include<linkList.h>

#ifndef MATRIX_H
#define MATRIX_H

using namespace std;

class Matrix {
  public:
    vector < linkList > matrix;
    QString Address;
    int rowNum;
    int colNum;

  Matrix() {//Read From CSV File With Constructor When We Start The Program
      cout << "Enter The Address Of The File That You Wanna Use: (Ex---> C:\\Users\\mohammmad\\Desktop\\M(7000,9000).csv\n";
      string temp;
      getline(cin, temp); //Getting Address Of CSV File
      this->Address = QString::fromStdString(temp);
      this->Address.replace('\\', '/');

      QFile file(this->Address);
      QTextStream in ( & file);


    if (!file.exists()) {

      cout << "\n\n\nPlease Enter The Address Of The File Correctly\n\n";

      exit(1);

    } else {//File Exists
      file.open(QIODevice::ReadOnly | QIODevice::Text);

      Node * tempNode;
      linkList * tempLN;
      QString tempString;
      QStringList tempSList;

      while (true) {
        tempString = in .readLine();
        if (tempString.isNull()) break;
        tempSList = tempString.split(',');
        this->colNum=tempSList.size();

        tempLN = new linkList;
        for (int x = 0; x < tempSList.size(); x++) {
          if (tempSList[x].toInt() != 0) {
            tempNode = new Node;

            tempNode -> coloumnIndex = x + 1;
            tempNode -> value = tempSList[x].toInt();

            tempLN -> addLast(tempNode);
          }
        }
        matrix.push_back( * tempLN);
      }
      file.close();
    }
    this->rowNum=matrix.size();
  }

  void Insert(int row, int col, int value) {
      Node* tempNode=new Node(value,col);

      linkList* tempLN=&matrix[row-1];

      if (tempLN->size == 0) {
        tempLN->addFirst(tempNode);
      }
      else {
        if (tempNode -> coloumnIndex < tempLN->head -> coloumnIndex) tempLN->addFirst(tempNode);
        else if (tempNode -> coloumnIndex > tempLN->tail -> coloumnIndex) tempLN->addLast(tempNode);
        else {
          Node * First = tempLN->head;
          Node * Second = tempLN->head;

          while (Second -> nextInRow != nullptr) {
            Second = First -> nextInRow;
            if (tempNode -> coloumnIndex < Second -> coloumnIndex) {
              First -> nextInRow = tempNode;
              tempNode -> nextInRow = Second;
              break;
            }
            First = Second;
          }

        }
      }

  }
  void Delete(int row, int col) {

    linkList * tempLN = & matrix[row - 1];

    if (tempLN -> size == 1) {
      Node * temp = tempLN -> head;
      tempLN -> head = nullptr;
      tempLN -> tail = nullptr;
      delete temp;
    }
    else {
      if (tempLN -> head -> coloumnIndex == col) {
        Node * temp = tempLN -> head;
        tempLN -> head = tempLN -> head -> nextInRow;
        delete temp;
      }
      else if (tempLN -> tail -> coloumnIndex == col) {
        Node * backTail = tempLN -> head;

        while (backTail -> nextInRow != tempLN -> tail) {
          backTail = backTail -> nextInRow;
        }
        Node * temp = tempLN -> tail;
        tempLN -> tail = backTail;
        delete temp;
      }
      else {
        Node * currentNode = tempLN -> head -> nextInRow;
        Node * backNode = tempLN -> head;

        while (currentNode != nullptr) {

          if (currentNode -> coloumnIndex == col) {
            backNode->nextInRow = currentNode -> nextInRow;
            delete currentNode;
            break;
          }
          backNode = currentNode;
          currentNode = currentNode -> nextInRow;
        }
      }

    }
    tempLN->size--;

    cout << "Deleted Successfully...\n\n";

  }
  void Search(int value) {

    for (auto & x: matrix) {
      Node * currentNode = x.head;

      while (currentNode != nullptr) {
        if (value == currentNode -> value) {
          cout << "Found...\n\n";
          return;
        }
        currentNode = currentNode -> nextInRow;
      }
    }
    cout << "Not Found...\n\n";
    return;
  }
  void update(int row, int col, int value) {

    linkList * tempLN = & matrix[row - 1];

    Node * currentNode = tempLN -> head;

    while (currentNode != nullptr) {
      if (currentNode -> coloumnIndex == col) {
        currentNode -> value = value;
        break;
      }
      currentNode = currentNode -> nextInRow;
    }
    cout << "The Value Updated Successfully...\n\n";

  }
  void print(bool type) {

    if (type == 0) {

      for (int i = 0; i < rowNum; i++) {
        for (int j = 0; j < colNum; j++) {
          cout << matrix[i][j] << "  ";
        }
        cout << endl;
      }

    } else {

      for (int i = 0; i < rowNum; i++) {
        Node * currentNode = matrix[i].head;
        while (currentNode != nullptr) {
          cout << i + 1 << " " << currentNode -> coloumnIndex << " " << currentNode -> value << endl;
          currentNode = currentNode -> nextInRow;
        }

      }

    }

  }

};

#endif // MATRIX_H
