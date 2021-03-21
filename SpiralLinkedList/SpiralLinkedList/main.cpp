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
    Node *temp = HEAD;
    int count = 0;
    while( temp != NULL ) {
        count++;
        temp = temp -> next;
    }
    return count;
}

void LinkedList::display() {
    Node *temp = HEAD;
    while( temp != NULL ) {
        cout << temp -> data << " --> ";
        temp = temp -> next;
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
    /**
     *NULL <----- 1 -----> 2 ----> 3 -----> 4 -----> 5 -----> null
     * |current                  |  mid
     */
    while( HEAD != NULL ) {
        cout << NewHEAD -> data << " --> ";
        NewHEAD = NewHEAD -> next;
        cout << HEAD -> data << " --> ";
        HEAD = HEAD -> next;
    }
    if( NewHEAD != NULL ) {
        cout << NewHEAD -> data << " --> ";
    }
    cout << "NULL" << endl;
}

int main() {
    int arr[] = {1,3,5,7,9,14,19,20,33,67,89,34};
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
