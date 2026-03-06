#include <iostream>
using namespace std;

struct node{
    int value;
    node *next;
};

void display();   

node *front = NULL;
node *rear = NULL;

void EnQueue(int value){
    node *newnode = new node();
    newnode->value = value;
    newnode->next = NULL;

    if(front == NULL){
        front = rear = newnode;
    }
    else{
        rear->next = newnode;
        rear = newnode;
    }
}

void DeQueue(){
    if(front == NULL){
        cout << "Queue is empty\n";
        return;
    }

    node *temp = front;
    front = front->next;
    delete temp;

    if(front == NULL){
        rear = NULL;
    }

    cout << "After DeQueue, Queue is:\n";
    display();   
}

void display(){
    if(front == NULL){
        cout << "Queue is empty\n";
        return;
    }

    node *temp = front;
    while(temp != NULL){
        cout << temp->value << "  ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
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
