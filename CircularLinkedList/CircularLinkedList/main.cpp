//
//  main.cpp
//  CircularLinkedList
//
//  Created by Sunny Vats on 23/03/21.
//

#include <iostream>
using namespace std;
class CircularLinked {
    struct node {
        int data;
        node *next;
    } *LAST;
public:
    CircularLinked();
    void addNode(int element);
    bool search(int element, node **previous, node **current);   // Implemented completely
    bool delNode(int element);
    void display();
};

CircularLinked::CircularLinked() {
    LAST = NULL;
}

void CircularLinked::addNode(int element) {
    if(LAST == NULL) {
        LAST = new node;
        LAST -> data = element;
        LAST -> next = LAST;
    }
    else {
        node *current = LAST, *temp = new node;
        temp -> data = element;
        temp -> next = current -> next;
        LAST -> next = temp;
        LAST = temp;
    }
}

bool CircularLinked::search(int element, node **pre, node **current) {
    while( (*current) -> data != element && (*current) -> next != LAST ) {
        *pre = *current;
        *current = (*current) -> next;
    }
    return ((*current) -> data == element);
}

bool CircularLinked::delNode(int element) {
    node *current = LAST -> next, *pre = LAST;
    bool found = search(element, &pre, &current);
    
    if(found) {
        pre -> next  = current -> next;
        delete current;
    }
    else if(LAST -> data == element) {
        current -> next = LAST -> next;
        LAST = current;
        delete LAST;
        found = true;
    }
    else cout << "Element not found" << endl;
    return found;
}

void CircularLinked::display() {
    node *tail = LAST -> next;
    node **temp = &tail;
    cout << ".-->";
    do {
        cout << (*temp) -> data << " ---> ";
        *temp = (*temp) -> next;
    } while(*temp != LAST);
    cout << (*temp) -> data << " <--." << endl;
    *temp = LAST -> next;
    cout << " \\___";
    while(*temp != LAST) {
        cout << "________";
        *temp = (*temp) -> next;
    }
    cout << "____/" << endl;
}

int main() {
    CircularLinked obj;
    for(int i = 12; i < 21; i++)
    obj.addNode(i);
    obj.display();
    cout << endl;
    int element = 12;
    bool result = obj.delNode(element);
    if (result) cout << "Delete element " << element << " result: Deleted" << endl;
    /**
     * .--> 12  --->  13  --->  14  --->  15  --->  16  --->  17  --->  18  --->  19 - -->  20  <--.
     * \__________________________________________________________________________________________/
     * ^ Output ^
     * Delete element 20 result: 1
     * Program ended with exit code: 0
     */
    obj.display();
    return 0;
}
