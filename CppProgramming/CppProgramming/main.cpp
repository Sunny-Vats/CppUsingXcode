//
//  main.cpp
//  CppProgramming
//
//  Created by Sunny Vats on 16/03/21.
//

#include <iostream>
using namespace std;

#define MAX 10

// Stack Implementation
class Stack {
private:
    int arr[MAX];
    int top;
public:
    Stack() {
        top = -1;
    }
    void push( int item ) {
        if( top == MAX - 1 ) {
            cout << "Stack is full." << endl;
            return;
        }
        top++;
        arr[top] = item;
    }
    int pop() {
        if( top == -1 ) {
            cout << "Stack is empty." << endl;
            return NULL;
        }
        int data = arr[top];
        top--;
        return data;
    }
};
// Queue & Circular(In Comments) Implementation
class Queue {
private:
    int arr[MAX];
    int front, rear;
    
public:
    Queue() {
        front = -1;
        rear = -1;
    }
    void addQueue( int item ) {
        if( rear == MAX - 1 ) {
            cout << "Queue is full" << endl;
            return;
        }
        rear++;
        arr[rear] = item;
        if( front == -1 ) {
            front = 0;
        }
    }
    /*void addCircularQueue( int item ) {
        if( (rear == MAX - 1  && front == 0 ) || ( rear + 1 == front ) ) {
            cout << "Queue is full" << endl;
            return;
        }
        if( rear == MAX - 1 )
            rear = 0;
        else
            rear += 1;
        arr[rear] = item;
        if( front == -1 )
            front = 0;
    }*/
    int delQueue() {
        int data;
        if( front == -1 ) {
            cout << "Queue is Empty" << endl;
            return NULL;
        }
        data = arr[front];
        if( front == rear )
            front = rear = -1;
        else
            front++;
        return data;
    }
    /*int delCircularQueue() {
        int data;
        if( front == -1 ) {
            cout << "Circular Queue is empty" << endl;
            return NULL;
        }
        else {
            data = arr[front];
            if( front == rear ) {
                Queue();
            }
            else {
                if( front == MAX - 1 )
                    front = 0;
                else
                    front += 1;
            }
        }
        return data;
    }*/
};

int main() {
    cout << "Hello World!" << endl;
    Stack obj;
    Queue obj1;
    obj.push( 11 );
    obj.push( 12 );
    obj.push( 14 );
    
    obj1.addQueue(12);
    obj1.addQueue(13);
    obj1.addQueue(14);
    
    int i = obj.pop();
    cout << "Item popped: " << i << endl;
    i = obj.pop();
    cout << "Item popped: " << i << endl;
    i = obj.pop();
    cout << "Item popped: " << i << endl;
    obj.pop();
    
    i = obj1.delQueue();
    cout << "Item deleted: " << i << endl;
    i = obj1.delQueue();
    cout << "Item deleted: " << i << endl;
    i = obj1.delQueue();
    cout << "Item deleted: " << i << endl;
    obj1.delQueue();
    
    return 0;
}
