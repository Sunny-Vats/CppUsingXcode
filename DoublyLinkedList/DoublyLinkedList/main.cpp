//
//  main.cpp
//  DoublyLinkedList
//
//  Created by Sunny Vats on 23/03/21.
//

#include <iostream>
using namespace std;

class DoublyList {
    struct node {
        node *prev;
        int data;
        node *next;
    }*START;
public:
    DoublyList() {
        START = NULL;
    }
    void createList(int element) {
        node *temp, *current;
        if(START == NULL) {
            START = new node;
            current = START;
            current -> data = element;
            current -> prev = NULL;
            current -> next = NULL;
        }
        else {
            current = START;
            while(current -> next != NULL)
                current = current -> next;
            temp = new node;
            temp -> data = element;
            temp -> prev = current;
            temp -> next = NULL;
            current -> next = temp;
        }
    }
    ~DoublyList() {
        node *temp;
        if(START == NULL) return;
        while(START != NULL) {
            temp = START -> next;
            delete START;
            START = temp;
        }
    }
    void display() {
        node *current = START;
        cout << "NULL <-- ";
        while(current != NULL) {
            cout << current -> data << " <==> ";
            current = current -> next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    DoublyList obj;
    obj.createList(12);
    obj.createList(13);
    obj.createList(14);
    obj.createList(15);
    obj.display();
    cout << endl;
    return 0;
}
