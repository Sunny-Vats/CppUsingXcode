//
//  main.cpp
//  LinkedList
//
//  Created by Sunny Vats on 16/03/21.
//

#include <iostream>
using namespace std;

// Linked List Implementation
class LinkedList {
private:
    struct node {
        int data;
        node *next;
    } *START;
public:
    LinkedList();
    void append( int num );
    void addAtBeg( int num );
    void addAfer( int c, int num );
    void del( int num );
    void display();
    int count();
    ~LinkedList();
};

LinkedList::LinkedList() {
    START = NULL;
}

void LinkedList::append( int num ) {
    node *q, *t;
    if( START == NULL ) {
        START = new node;
        START -> data = num;
        START -> next = NULL;
    }
    else {
        q = START;
        while( q -> next != NULL )
            q = q -> next;
        t = new node;
        t -> data = num;
        t -> next = NULL;
        q -> next = t;
    }
}

void LinkedList::addAtBeg( int num ) {
    node *q;
    q = new node;
    q -> data = num;
    q -> next = START;
    START = q;
}

void LinkedList::addAfer( int c, int num ) {
    node *q, *t;
    int i;
    for( i = 1, q = START; i < c; i++ ) {
        q = q -> next;
        if( q == NULL ) {
            cout << "There are less than " << c << "elements.";
            return;
        }
    }
    t = new node;
    t -> data = num;
    t -> next = q -> next;
    q -> next = t;
}

void LinkedList::del( int num ) {
    node *q, *t;
    q = START;
    if( q -> data == num ) {
        START = q -> next;
        delete q;
        return;
    }
    t = START;
    while( q -> next != NULL ) {
        if( q -> data == num ) {
            t -> next = q -> next;
            delete q;
            return;
        }
        t = q;
        q = q -> next;
    }
    cout << "Element " << num << " not found." << endl;
}

void LinkedList::display() {
    node *q;
    cout << "Complete Linked List is as follows: " << endl;
    for( q = START; q !=  NULL; q = q -> next ) {
        cout << q -> data << "-->";
    }
    cout << "NULL" << endl;
}

int LinkedList::count() {
    node *q = START;
    int c = 0;
    while( q != NULL ) {
        c++;
        q = q -> next;
    }
    return c;
}
LinkedList::~LinkedList() {
    node *q;
    if( START == NULL )
        return;
    while ( START != NULL ) {
        q = START -> next;
        delete START;
        START = q;
    }
}
int main() {
    LinkedList obj;
    
    obj.append(1);
    obj.append(3);
    obj.append(4);
    obj.append(5);
    
    obj.display();
    cout << "Total elements in LinkedList: " << obj.count() << endl;
    cout << endl;
    obj.addAtBeg(0);
    obj.addAfer(2, 2);
    obj.display();
    cout << "Total elements in LinkedList: " << obj.count() << endl;
    
    return 0;
}
