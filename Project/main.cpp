#include <iostream>

#include<conio.h>

#include<Matrix.h>

using namespace std;

void Insert(Matrix * );
void Delete(Matrix * );
void Search(Matrix * );
void Update(Matrix * );
void Print(Matrix * );
void Save(Matrix * );

int main() {

    Matrix matrix;

    while (true) {
        system("cls");
        int firstPage;

        cout << ":::[ Compressed Matrix ]:::\n\n" <<
            "<1> Insert\n\n" <<
            "<2> Delete\n\n" <<
            "<3> Search\n\n" <<
            "<4> Update\n\n" <<
            "<5> Print\n\n" <<
            "<6> Save\n\n" <<
            "Please Enter A Number: ";
        cin >> firstPage;

        switch (firstPage) {
        case 1:
            Insert( & matrix);
            break;
        case 2:
            Delete( & matrix);
            break;
        case 3:
            Search( & matrix);
            break;
        case 4:
            Update( & matrix);
            break;
        case 5:
            Print( & matrix);
            break;
        case 6:
            Save( & matrix);
            break;
        case 7:
            exit(0);
            break;
        default:
            cout << "Please Enter A Valid Number";
            cout << "\n\nPress Any Key to Continue...";
            getch();
            system("cls");
            continue;
        }

    }

    return 0;
}

void Insert(Matrix * matrix) {
    system("cls");
    cout << "::[ Inserting Menu ]::\n\n";

    int row, col, value;

    cout << "Enter The Row Number:";
    cin >> row;
    cout << "Enter The Coloumn Number:";
    cin >> col;
    cout << "Enter The Value:";
    cin >> value;

    matrix -> Insert(row, col, value);

    cout << "This Value Has Inserted Successfully\n\n\n\nPress Any Key to Go Back...";
    getch();
    return;
}
void Delete(Matrix * matrix) {
    system("cls");
    cout << "::[ Deleting Menu ]::\n\n";

    int row, col;

    cout << "Enter The Row Number:";
    cin >> row;
    cout << "Enter The Coloumn Number:";
    cin >> col;

    matrix -> Delete(row, col);

    cout << "This Value Has Deleted Successfully\n\n\n\nPress Any Key to Go Back...";
    getch();
    return;

}
void Search(Matrix * matrix) {
    system("cls");
    cout << "::[ Searching Menu ]::\n\n";

    int value;

    cout << "Enter The Value:";
    cin >> value;

    matrix -> Search(value);

    cout << "\n\n\n\nPress Any Key to Go Back...";
    getch();
    return;
}
void Update(Matrix * matrix) {
    system("cls");
    cout << "::[ Updating Menu ]::\n\n";

    int row, col, value;

    cout << "Enter The Row Number:";
    cin >> row;
    cout << "Enter The Coloumn Number:";
    cin >> col;
    cout << "Enter The Value:";
    cin >> value;

    matrix -> update(row, col, value);

    cout << "This Element Has Updated Successfully\n\n\n\nPress Any Key to Go Back...";
    getch();
    return;
}
void Print(Matrix * matrix) {
    system("cls");
    cout << "::[ Printing Menu ]::\n\n";
    int printMode;

    cout << "<1> Complete matrix\n" <<
        "<2> Compressed\n" <<
        "<3> Back\n" <<
        "Please Enter A Number: ";
    cin >> printMode;
    cout << "\n\n";

    switch (printMode) {

    case 1:
        matrix -> print(0);
        break;
    case 2:
        matrix -> print(1);
        break;
    case 3:
        return;
    default:
        cout << "Please Enter A Valid Number";
        cout << "\n\nPress Any Key to Continue...";
        getch();
        Print(matrix);
        break;
    }
    cout << "\n\n\nPress Any Key to Go Back...";
    getch();
    return;
}
void Save(Matrix * matrix) {
    system("cls");
    cout << "::[ Saving Menu ]::\n\n";
    int saveMode;

    cout << "<1> Complete matrix\n" <<
        "<2> Compressed\n" <<
        "<3> Back\n" <<
        "Please Enter A Number: ";
    cin >> saveMode;
    cout << "\n\n";

    switch (saveMode) {

    case 1:
        matrix -> save_file(0);
        break;
    case 2:
        matrix -> save_file(1);
        break;
    case 3:
        return;
    default:
        cout << "Please Enter A Valid Number";
        cout << "\n\nPress Any Key to Continue...";
        getch();
        Save(matrix);
        break;
    }
    matrix -> save_file(1);

    cout << "This CSV File Has Saved Successfully\n\n\n\nPress Any Key to Go Back...";
    getch();
    return;
}
