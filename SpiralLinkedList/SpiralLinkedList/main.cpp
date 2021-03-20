//
//  main.cpp
//  SpiralLinkedList
//
//  Created by Sunny Vats on 20/03/21.
//

#include <iostream>
using namespace std;

class LinkedList {
    struct Node {
        int data;
        Node *next;
    } *HEAD;
public:
    LinkedList();
    void createList(int element);
    int lengthOfList();
    void display();
    void spiralList();
};

LinkedList::LinkedList() {
    HEAD = NULL;
}

void LinkedList::createList(int element) {
    Node *current, *temp;
    if( HEAD == NULL ) {
        HEAD = new Node;
        HEAD -> data = element;
        HEAD -> next = NULL;
    }
    else {
        temp = HEAD;
        while( temp -> next != NULL )
            temp = temp -> next;
        current = new Node;
        current -> data = element;
        current -> next = NULL;
        temp -> next = current;
    }
}

int LinkedList::lengthOfList() {
    int count = 0;
    while( HEAD != NULL ) {
        HEAD = HEAD -> next;
        count++;
    }
    return count;
}

void LinkedList::display() {
    while( HEAD != NULL ) {
        cout << HEAD -> data << " --> ";
        HEAD = HEAD -> next;
    }
    cout << "NULL" << endl;
}

void LinkedList::spiralList() {
    Node *current=HEAD, *temp=NULL , *mid=NULL;
    Node *fast, *slow;
    fast = slow = HEAD;
    while( fast && fast -> next ) {
        fast = fast -> next -> next;
        slow = slow -> next;
        mid = current -> next;
        current -> next = temp;
        temp = current;
        current = mid;
    }
    HEAD = temp;
    Node *NewHEAD = new Node;
    NewHEAD = current;
    while( NewHEAD ) {
        cout << NewHEAD -> data << " --> ";
        NewHEAD = NewHEAD -> next;
        cout << HEAD -> data << " --> ";
        HEAD = HEAD -> next;
    }
    cout << "NULL" << endl;
}

int main() {
    int arr[] = {1,3,5,7,9,14,19,22,23};
    LinkedList obj;
    for( int i=0; i < sizeof(arr)/sizeof(arr[0]); i++ ) {
        obj.createList(arr[i]);
    }
    obj.display();
    cout << endl;
    obj.spiralList();
    cout << endl;
    
    return 0;
}
