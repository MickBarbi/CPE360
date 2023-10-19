//James Barbi
//I pledge my Honor that I have abided by the Stevens Honor System


#include <iostream>
using namespace std;

int top = 0, bottom = 0;
char printer;

void insertSpace(int spaceNumber){
    for (int j = 0; j < spaceNumber; j++){
        cout << ' ';
    }
}

void printTrapezoid(int head, int base, char writer){
    int height = ((base - head) / 2) + 1;
    int newBase = base;
    int numOfSpaces;

    for (int i = 0; i < height; i++){
        numOfSpaces = (base - head) / 2;
        insertSpace(numOfSpaces);
        for(int j = 0; j < head; j++){
            cout << writer;
        }
        insertSpace(numOfSpaces);
        cout << endl;
        head = head + 2;
    }
}

int main(){
    system("cls");
    while(top < 1 || top > 15 || (top%2 == 0)){
        cout << "Enter an odd integer for the top of the trapezoid between 1 and 15: ";
        cin >> top;
    }
    while(bottom < 1 || bottom > 17 || bottom < top || (bottom%2 == 0)){
        cout << "\nEnter an odd integer for the base of the trapezoid between 3 and 17 and larger than the value for the top: ";
        cin >> bottom;
    }
    cout << "\nEnter a character to be used to use to print the trapezoid: ";
    cin >> printer;
    system("cls");
    printTrapezoid(top, bottom, printer);
    cout << "Hit enter to start again";
    cin;
}