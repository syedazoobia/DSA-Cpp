#include <iostream>
using namespace std;

int Queue[5] = {};
int front = 0;
int rear = 0;
int size = 5;
int count = 0;

void EnQueue(int val) {
    if(count == size){
        cout << "\nQueue is full";
        return;
    }
    Queue[rear] = val;
    rear = (rear + 1) % size;
    count++;
}

void DeQueue() {
    if(count == 0){
        cout << "\nQueue is empty";
        return;
    }
    cout << "\nDequeued: " << Queue[front];
    front = (front + 1) % size;
    count--;
}

void display() {
    if(count == 0){
        cout << "\nQueue is empty";
        return;
    }
    cout << "\nQueue elements: ";
    int i = front;
    for(int c = 0; c < count; c++){
        cout << Queue[i] << "   ";
        i = (i + 1) % size;
    }
    cout << endl;
}

int main() {
    DeQueue();
    EnQueue(1);
    EnQueue(2);
    EnQueue(3);
    EnQueue(4);
    DeQueue();
    EnQueue(5);
    EnQueue(6);    
    EnQueue(7);    
    display();
    return 0;
}
