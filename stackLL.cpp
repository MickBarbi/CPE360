#include <iostream>
#include <string>
using namespace std;

char placeholder;


struct Student{
    string name;
    int id;
};

struct Node{
    Student student;
    struct Node* next;
} *top = NULL;


bool isEmpty(){
    if (top == NULL){
        return 1;
    }
    return 0;
}

void push(string name, int id){
    struct Node* newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL){
        cout << "Memory allocation failed" << endl;
        exit(1);
    }
    newNode->student.name = name;
    newNode->student.id = id;
    newNode->next = top;

    top = newNode;
}

Student pop(){
    struct Node* temp;
    temp = top;
    if (isEmpty()){
        cout << "Stack underflow" << endl;
        exit(1);
    }
    Student pupil = temp->student;
    top = top->next;
    free(temp);
    temp = NULL;
    return pupil;
}

Student peek(){
    if(isEmpty()){
        cout << "Stack underflow" << endl;
        exit(1);
    }
    return top->student;
}

void print(){
    struct Node* temp;
    temp = top;
    if(isEmpty()){
        cout << "Stack underflow" << endl;
        exit(1);
    }
    cout << "The students on the stack are:" << endl;
    int counter = 1;
    while(temp != NULL){
        cout << counter << ". " << temp->student.name << " (ID: " << temp->student.id << ")" << endl;
        temp = temp->next;
    }
}

int main(){
    bool running = true;
    int choice, id;
    string name;
    Student popOutput, peekOutput;
    while(running){
        system("cls");
        cout << "Welcome to your contact list. What would you like to do?" << endl;
        cout << "1) Push\n2) Pop\n3) Print Top Element\n4) Print All the Elements\n5) Quit" << endl;
        cin >> choice;

        switch (choice){
            case 1:
                system("cls");
                cout << "Enter student name: ";
                cin >> name;
                cout << "Enter student id: ";
                cin >> id;
                push(name, id);
                cout << "Return to menu?(y)" << endl;
                cin >> placeholder;
                break;
            case 2:
                system("cls");
                popOutput = pop();
                cout << "Removed Student: " << popOutput.name << " (ID: " << popOutput.id << ")" << endl;
                cout << "Return to menu?(y)" << endl;
                cin >> placeholder;
                break;
            case 3:
                peekOutput = peek();
                cout << "The topmost student is: " << peekOutput.name << " (ID: " << popOutput.id << ")" << endl;
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