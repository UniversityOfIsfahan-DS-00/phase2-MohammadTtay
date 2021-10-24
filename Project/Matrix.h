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

  Matrix() {//Read From CSV File With Constructor When We Start The Program
    cout << "Enter The Name Of The File That You Wanna Use: (Ex---> M(7000,9000).csv\n";
    string temp;
    getline(cin, temp); //Getting Name Of CSV File
    QString fileName = QString::fromStdString(temp);
    fileName = "../" + fileName;

    QFile file(fileName);
    QTextStream in ( & file);

    if (!file.exists()) {

      cout << "\n\n\nPlease Enter The Name Of File Correctly\n\n";

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

  }
  void Search(int value) {

  }
  void update(int row, int col, int value) {

  }
  void print(bool type) {

  }

};

#endif // MATRIX_H
