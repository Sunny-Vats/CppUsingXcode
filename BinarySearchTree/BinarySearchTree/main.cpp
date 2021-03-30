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
    void addNode();
    void traverse();
    
};
int main() {
    
    return 0;
}
