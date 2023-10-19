#include <iostream>
#include "testFile.h"
using namespace std;

int main(){
    LinkedList stevensxc;
    Node* nodeA = new Node("Mick", 2);
    Node* nodeB = new Node("Kaitlyn", 1);
    Node* nodeC = new Node("Gianna", 2);
    Node* nodeD = new Node("Jacky", 4);
    Node* nodeE = new Node("Caleb", 2);
    Node* nodeF = new Node("Jake P", 3);
    Node* nodeG = new Node("Ronnie", 5);

    cout << "Created nodes" << endl;

    stevensxc.RosterSpot(nodeA);
    stevensxc.RosterSpot(nodeB);
    stevensxc.RosterSpot(nodeC);
    stevensxc.RosterSpot(nodeD);
    stevensxc.RosterSpot(nodeE);
    stevensxc.RosterSpot(nodeF);
    stevensxc.RosterSpot(nodeG);

    cout << "Stevens XC Roster: ";
    stevensxc.PrintList();
}