//
//  main.cpp
//  Trees
//
//  Created by Sunny Vats on 17/03/21.
//

#include <iostream>
using namespace std;

#define TRUE 1
#define FALSE 0

class Tree {
    struct node {
        node *left;
        int data;
        node *right;
    }*ROOT;
public:
    Tree();
    void search( int n, int &found, node *&parent );
    void insert( int n );
    void traverse();
    void in( node *current );
    void post( node *current );
    void pre( node *current );
};

Tree::Tree() {
    ROOT = NULL;
}

void Tree::search( int n, int &found, node * &parent ) {
    node *current;
    found = FALSE;
    parent = NULL;
    
    if( ROOT == NULL )
        return;
    current = ROOT;
    while( current != NULL ) {
        if( current -> data == n ) {
            found = TRUE;
            return;
        }
        
        if( current -> data > n ) {
            parent = current;
            current = current -> left;
        }
        else {
            parent = current;
            current = current -> right;
        }
    }
}

void Tree::insert( int n ) {
    int found;
    node *current, *parent;
    
    search( n, found, parent );
    
    if( found == TRUE ) {
        cout << "Such a node already exists." << endl;
    }
    else {
        current = new node;
        current -> data = n;
        current -> left = NULL;
        current -> right = NULL;
        
        if( parent == NULL )
            ROOT = current;
        else
            parent -> data > n ? parent -> left = current : parent -> right = current;
    }
}

void Tree::traverse() {
    in( ROOT );
    cout << "NULL" << endl;
    post( ROOT );
    cout << "NULL" << endl;
    pre( ROOT );
    cout << "NULL" << endl;
}

void Tree::in( node *current ) {
    if( current != NULL ) {
        in( current -> left );
        cout << "\t" << current -> data << "---->";
        in( current -> right );
    }
}

void Tree::post( node *current ) {
    if( current != NULL ) {
        post( current -> left );
        post( current -> right );
        cout << "\t" << current -> data << "---->";
    }
}

void Tree::pre( node *current ) {
    if( current != NULL ) {
        cout << "\t" << current -> data << "---->";
        pre( current -> left );
        pre( current -> right );
    }
}

int main() {
    Tree tree;
    int i, num;
    
    for( i = 0; i <= 6; i++ ) {
        cout << "Enter the data for the node to be inserted: ";
        cin >> num;
        tree.insert( num );
    }
    
    tree.traverse();
    return 0;
}
