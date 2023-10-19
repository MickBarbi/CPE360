#include <iostream>
using namespace std;

string placeholder;

struct Contact{
    int data;
    char firstName[50];
    char lastName[50];
    char phoneNumber[15];
    char email[100];
    struct Contact* next;
};


struct Contact* createAndAddContact(struct Contact* head){
    char fName[50];
    char lName[50];
    char pNumber[15];
    char mail[100];

    cout << "Enter First Name: ";
    cin >> fName;
    cout << endl << "Enter Last Name: ";
    cin >> lName;
    cout << endl << "Enter Phone Number: ";
    cin >> pNumber;
    cout << endl << "Enter Email Address: ";
    cin >> mail;
    cout << endl << "Contact added successfully." << endl;

    struct Contact *newContact = (struct Contact*)malloc(sizeof(struct Contact));
    for (int i = 0; i < 50; i++){
        newContact->firstName[i] = fName[i];
    }
    for (int i = 0; i < 50; i++){
        newContact->lastName[i] = lName[i];
    }
    for (int i = 0; i < 15; i++){
        newContact->phoneNumber[i] = pNumber[i];
    }
    for (int i = 0; i < 100; i++){
        newContact->email[i] = mail[i];
    }
    newContact->next = NULL;

    if (head == NULL){
        head = newContact;
    } else {
        struct Contact *curr = head;
        while (curr->next != NULL){
            curr = curr->next;
        }
        curr->next = newContact;
    }
    return head;
}


void displayContacts(struct Contact* head){
    if (head == NULL){
        cout << "Contact list is empty. Return?(y)" << endl;
        cin >> placeholder;
        return;
    }
    struct Contact *reader;
    reader = head;
    int i = 0;
    while (reader != NULL){
        i++;
        cout << "Contact " << i << ":" << endl;
        cout << "\tName: " << reader->firstName << " " << reader->lastName << endl;
        cout << "\tPhone Number: " << reader->phoneNumber << endl;
        cout << "\tEmail: " << reader->email << endl;
        reader = reader->next;
    }
    free(reader);
    return;
}


bool matchNames(char first[], char second[]){
    for (int i = 0; i < sizeof(first); i++){
        if (first[i] != second[i]){
            return false;
        }
    }
    return true;
}


void searchContact(struct Contact* head, char* name){
    char correct;
    if (head == NULL){
        cout << "Contact list is empty. Return?(y)" << endl;
        cin >> placeholder;
        return;
    }
    struct Contact *finder;
    finder = head;
    while (finder != NULL){
        if (matchNames(name, finder->firstName) || matchNames(name, finder->lastName)){
            system("cls");
            cout << "Contact Found:" << endl;
            cout << "\tName: " << finder->firstName << " " << finder->lastName << endl;
            cout << "\tPhone Number: " << finder->phoneNumber << endl;
            cout << "\tEmail: " << finder->email << endl;
            cout << "Is this the correct contact?(y/n)" << endl;
            cin >> correct;
            if (correct == 'y'){
                cout << "Great. Return to menu?(y)" << endl;
                cin >> placeholder;
                return;
            }
        }
        finder = finder->next;
    }
    cout << "Could not find specified contact. Try searching again. Return to menu?(y)" << endl;
    cin >> placeholder;
    return;
}


struct Contact* deleteContact(struct Contact* head, char* name){
    char correct;
    if (head == NULL){
        system("cls");
        cout << "Contact list is empty. Return?(y)" << endl;
        cin >> placeholder;
        return head;
    }
    struct Contact *deleter;
    struct Contact *prev;
    deleter = head;
    prev = head;
    system("cls");
    while (deleter != NULL){
        if (matchNames(name, deleter->firstName) || matchNames(name, deleter->lastName)){
            cout << "Found " << deleter->firstName << " " << deleter->lastName << endl;
            cout << "Are you sure this is the contact you would like to delete?(y/n)" << endl;
            cin >> correct;
            if (correct == 'y'){
                if (deleter == head){
                    struct Contact *temp = head;
                    head = head->next;
                    free(temp);
                    temp = NULL;
                } else {
                    prev->next = deleter->next;
                    deleter->next = NULL;
                    free(deleter);
                    deleter = NULL;
                }
                cout << "Contact successfully deleted. Return to menu?(y)" << endl;
                cin >> placeholder;
                return head;
            }
        }
        deleter = deleter->next;
        if (deleter != head->next){
            prev = prev->next;
        }
    }
    cout << "Could not find specified contact. Try searching again. Return to menu?(y)" << endl;
    cin >> placeholder;
    return head;
}



int main(){
    struct Contact *head = (struct Contact*)malloc(sizeof(struct Contact));
    head = NULL;
    bool running = true;
    int choice;
    while(running){
        system("cls");
        cout << "Welcome to your contact list. What would you like to do?" << endl;
        cout << "1) Create and Add Contact\n2) Display All Contacts\n3) Search for Contact\n4) Delete Contact\n5) Exit Program" << endl;
        cin >> choice;

        switch (choice){
            case 1:
                system("cls");
                head = createAndAddContact(head);
                cout << "Return to menu?(y)" << endl;
                cin >> placeholder;
                break;
            case 2:
                system("cls");
                displayContacts(head);
                cout << "Return to menu?(y)" << endl;
                cin >> placeholder;
                break;
            case 3:
                char search[50];
                system("cls");
                cout << "Enter either the first or last name of the contact you would like to search for: ";
                cin >> search;
                searchContact(head, search);
                break;
            case 4:
                char del[50];
                system("cls");
                cout << "Enter either the first or last name of the contact you would like to search for: ";
                cin >> del;
                head = deleteContact(head, del);
                break;
            case 5:
                running = false;
                break;
        }
    }
    free(head);
    return 1;
}