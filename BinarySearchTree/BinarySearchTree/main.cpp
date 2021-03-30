//
//  main.cpp
//  BinarySearchTree
//
//  Created by Sunny Vats on 26/03/21.
//
#include <iostream>
using namespace std;

class BinarySearchTree {
    struct node {
        int data;
        node *left;
        node *right;
    }*ROOT;
public:
    BinarySearchTree();
    void addNode(int data);
    void traverse();
    void search(int data);
    void inOrder(node *ptr);
};
BinarySearchTree::BinarySearchTree() {
    ROOT = NULL;
}
void BinarySearchTree::addNode( int data ) {
    if( ROOT != NULL ) {
        node *current = new node;
        current -> data = data;
        current -> left = NULL;
        current -> right = NULL;
        node *tmp = ROOT;
        node *parent = NULL;
        while( tmp != NULL ) {
            parent = tmp;
            if( parent -> data > current -> data )
                tmp = tmp -> left;
            else
                tmp = tmp -> right;
        }
        if( parent -> data > current -> data )
            parent -> left = current;
        else
            parent -> right = current;
    }
    else {
        ROOT = new node;
        ROOT -> data = data;
        ROOT -> left = NULL;
        ROOT -> right = NULL;
    }
    cout << data << " inserted." << endl;
}
void BinarySearchTree::traverse() {
    if( ROOT == NULL ) cout << "Tree is empty.. No  on this tree." << endl;
    else {
        node *tmp = ROOT;
        cout << endl << "INORDER TRAVERSAL" << endl;
        inOrder(tmp);
        cout << "NULL" << endl;
    }
}
void BinarySearchTree::inOrder(node *ptr) {
    if( ptr != NULL ) {
        inOrder(ptr -> left);
        cout << ptr -> data << " --> ";
        inOrder(ptr -> right);
    }
}

int main() {
    BinarySearchTree obj;
    obj.addNode(34);
    obj.addNode(22);
    obj.addNode(45);
    obj.addNode(18);
    obj.traverse();
    return 0;
}
