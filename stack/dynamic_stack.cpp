#include <iostream>
using namespace std;

struct node {
    int value;
    node *next;
};

node *stack = NULL;

void push (int value){
    node *newnode = new node();
    newnode->value = value;
    newnode->next=stack;
    stack = newnode;
}

void pop(){
    if(stack == NULL){
        cout << "stack is underflow";
    }
    node *temp = stack;
    stack = stack->next;
    delete(temp);
}

void display(){

     if(stack == NULL){
        cout << "stack is underflow";
    }

    node *temp = stack;

    while(temp != NULL){
        cout << temp->value << "  ";
        temp = temp->next;
    }
}

int main(){
    int sel, flag = 0, num, seat, course;

    while(flag == 0){
        cout << "\n\nSELECT FROM MENU" << endl
             << "1. push" << endl
             << "2. pop" << endl
             << "3. Display" << endl
             << "4. Exit" << endl
             << "Enter the number (1-4): ";

        cin >> sel;

        switch (sel){
        case 1:
            cout << "\nEnter a number to push: ";
            cin >> num;
            push(num);
            break;

        case 2:
            pop();
            display();
            break;

        case 3:
            cout << "\nDisplay\n";
            display();
            break;

        case 4:
            flag = 1;
            cout << "\nProgram exiting...";
            break;

        default:
            cout << "\nInvalid choice. Please try again.";
        }
    }
    return 0;
}
