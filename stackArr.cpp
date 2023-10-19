#include <iostream>
using namespace std;

char placeholder;

int top = -1;
int MAX = 5;
int stack[5];


bool isEmpty(){
    if (top == -1){
        return 1;
    }
    return 0;
}

bool isFull(){
    if (top == MAX - 1){
        return 1;
    }
    return 0;
}

void push(int data){
    if (top == MAX-1){
        cout << "Stack overflow" << endl;
        return;
    }
    top = top + 1;
    stack[top] = data;
}

int pop(){
    int value;
    if(top == -1){
        cout << "Stack underflow" << endl;
        exit(1);
    }
    value = stack[top];
    top = top-1;
    return value;
}

int peek(){
    if (isEmpty()){
        cout << "Stack underflow" << endl;
        exit(1);
    }
    return stack[top];
}

void print(){
    int i;
    if (top == -1){
        cout << "Stack underflow" << endl;
        return;
    }
    for (i = top; i >= 0; i--){
        cout << stack[i] << ", ";
    }
    cout << endl;
}

int main(){
    bool running = true;
    int choice, add, popOutput, peekOutput;
    while(running){
        system("cls");
        cout << "Welcome to your contact list. What would you like to do?" << endl;
        cout << "1) Push\n2) Pop\n3) Print Top Element\n4) Print All the Elements\n5) Quit" << endl;
        cin >> choice;

        switch (choice){
            case 1:
                system("cls");
                cout << "What integer would you like to add to the stack?" << endl;
                cin >> add;
                push(add);
                cout << "Return to menu?(y)" << endl;
                cin >> placeholder;
                break;
            case 2:
                system("cls");
                popOutput = pop();
                cout << "Popped: " << popOutput << endl;
                cout << "Return to menu?(y)" << endl;
                cin >> placeholder;
                break;
            case 3:
                peekOutput = peek();
                cout << "Top element: " << peekOutput << endl;
                cout << "Return to menu?(y)" << endl;
                cin >> placeholder;
                break;
            case 4:
                print();
                cout << "Return to menu?(y)" << endl;
                cin >> placeholder;
                break;
            case 5:
                running = false;
                break;
        }
    }
    return 1;
}