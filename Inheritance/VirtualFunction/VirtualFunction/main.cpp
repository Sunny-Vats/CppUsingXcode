//
//  main.cpp
//  VirtualFunction
//
//  Created by Sunny Vats on 17/03/21.
//

#include <iostream>
using namespace std;
class one {
public:/*
    void display() {    // Normal function will leads to calling display of base class only
        cout << "In base class" << endl;
    }*/
    virtual void display() {    // Virtual function overcome the above drawback
        cout << "In base class" << endl;
    }
};

class oneofone : public one {   // public access specifier allows upcasting
public:
    void display() {
        cout << "In oneforone class" << endl;
    }
};

class twoofone : public one {   // Inheritance can be done using ':' followed by access specifier and name of base class
public:
    void display() {
        cout << "In twoofone class" << endl;
    }
};

int main() {
    one *ptr, obj0;
    ptr = &obj0;
    ptr -> display(); // way to call base class display() function
    
    oneofone obj1;
    twoofone obj2;
    
    ptr = &obj1;
    ptr -> display();   // calls base/parent class display() but after changing to virtual function, it will display derived/chiled class display() function
    
    ptr = &obj2;
    ptr -> display();   // calls base/parent class display()
    return 0;
}
