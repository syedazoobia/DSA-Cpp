#include <iostream>
using namespace std;

int Queue[5] = {};

int front = 0;
int rear = 0;
int size = 5;

void EnQueue(int val){
    if((rear+1) % size == front){
        cout << "\nQueue is full";
        return;
    }

    Queue[rear] = val;
    rear = ( rear + 1) % size;
}

void DeQueue(){
    if(front == rear ){
        cout << "\nQueue is empty";
        return;
    }
    cout << "\nDeQueued:  " << Queue[front] ;
    front = (front + 1) % size;

}

void display (){
        if(front == rear ){
        cout << "\nQueue is empty";
        return;
    }

    cout << "\nQueue elements: ";
    int i = front;
    while (i != rear){
        cout << Queue[i] <<  "   ";
        i = (i + 1) % size ;
    }
}

int main (){
  int sel, flag = 0, val;

    while(flag == 0){
        cout << "\n\nSELECT FROM MENU\n"
             << "1. EnQueue\n"
             << "2. DeQueue\n"
             << "3. Display\n"
             << "4. Exit\n"
             << "Enter choice: ";
        cin >> sel;

        switch(sel){
        case 1:
            cout << "Enter value to EnQueue: ";
            cin >> val;
            EnQueue(val);
            break;

        case 2:
            DeQueue();
            break;

        case 3:
            display();
            break;

        case 4:
            flag = 1;
            cout << "Program exiting...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }
    }
    return 0;
}