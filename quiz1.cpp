#include <iostream>
using namespace std;

struct node{
    int data;
    struct node* link;
};

struct node* addToEmpty(struct node* head, int data){
    head = (struct node*)malloc(sizeof(struct node));
    head->data = data;
    head->link = NULL;
    return head;
}

struct node* addAtEnd(struct node* head, int data){
    struct node *current = (struct node*)malloc(sizeof(struct node));
    current = head;

    while (current->link != NULL){
        current = current->link;
    }
    
    struct node *next = (struct node*)malloc(sizeof(struct node));
    current->link = next;
    next->data = data;
    next->link = NULL;

    return head;
}

void print(struct node* head){
    node *reader = head;
    while (reader){
        cout << reader->data << ", ";
        reader = reader->link;
    }
}


int main(){
    struct node *head = NULL;
    int value;
    cout<<"Enter an integer value to be added to the empty list: ";
    cin>>value;
    head = addToEmpty(head,value);
    cout<<"Enter an integer value to be added to the list: ";
    cin>>value;
    head = addAtEnd(head,value);
    cout<<"Enter an integer value to be added to the list: ";
    cin>>value;
    cout<<"The elements of the list are: ";
    head = addAtEnd(head,value);
    print(head);
    return 0;
}