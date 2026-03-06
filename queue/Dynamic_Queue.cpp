#include <iostream>
using namespace std;

struct node {
    int value;
    node *next;
};

node *front = NULL;
node *rear = NULL;

void EnQueue(int val){
    node *newnode = new node();
    newnode->value = val;
    newnode -> next = NULL;

    if(rear == NULL){
        front = newnode;
        rear = newnode;
    }
    else{
        rear ->next = newnode;
        rear = newnode;
    }
}


void DeQueue(){
    if(front == NULL){
        cout << "QUEUE IS EMPTY! ";
        return;
    }

    node *temp = front;
    front = front->next;
    delete (temp);

    cout << "elements..." << endl;
    node *current = front;
    while(current != NULL){
        cout << current->value << "   ";
        current = current->next;
    }

    if(front == NULL){
        rear = NULL;
    }
}


int main(){
    int sel, flag = 0, val;

    while(flag == 0){
        cout << "\n\nSELECT FROM MENU\n"
             << "1. EnQueue\n"
             << "2. DeQueue\n"
             << "3. Exit\n"
             << "Enter choice: ";
        cin >> sel;

        switch(sel){
        case 1:
            cout << "Enter value: ";
            cin >> val;
            EnQueue(val);
            break;

        case 2:
            DeQueue();
            break;


        case 3:
            flag = 1;
            cout << "Program exiting...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }
    }
    return 0;
}