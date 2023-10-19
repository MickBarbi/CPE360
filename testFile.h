#include <iostream>
#include <string>
using namespace std;

class Node{
    public:
        string called;
        int year;
        Node* next;

        Node(string name, int grade){
            called = name;
            year = grade;
            next = nullptr;
        }
};

class LinkedList{
    private:
        Node* head;
        Node* tail;

    public:
        LinkedList(){
            head = nullptr;
            tail = nullptr;
        }

        void Append(Node* newNode){
            if(head == nullptr){
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }

        void Preppend(Node* newNode){
            if(head == nullptr){
                head = newNode;
                tail = newNode;
            } else {
                newNode->next = head;
                head = newNode;
            }
        }

        void InsertAfter(Node* currentNode, Node* newNode){
            if(head == nullptr){
                head = newNode;
                tail = newNode;
            } else if(currentNode == tail){
                tail->next = newNode;
                tail = newNode;
            } else {
                newNode->next = currentNode->next;
                currentNode->next = newNode;
            }
        }

        void RosterSpot(Node* newNode){
            if(head == nullptr){
                head = newNode;
                tail = newNode;
                return;
            }
            Node* leftNode = head;
            Node* rightNode = leftNode->next;
            if(newNode->year > leftNode->year){
                Preppend(newNode);
                return;
            }
            while(rightNode){
                if((newNode->year <= leftNode->year) && (newNode->year >= rightNode->year)){
                    InsertAfter(leftNode, newNode);
                    return;
                }
                leftNode = rightNode;
                rightNode = leftNode->next;
            }
            Append(newNode);
        }

        void PrintList(){
            Node* node = head;
            if (node) {
                // Head node is not preceded by separator
                cout << node->called;
                node = node->next;
            }
            while (node) {
                cout << ", " << node->called;
                node = node->next;
            }
            cout << endl;
        }
};