#include <iostream>
using namespace std;

int stack[10];
int top = 0;  

// Push function
void push(int value) {
    if(top == 10) {
        cout << "Stack Overflow\n";
        return;
    }
    stack[top] = value;
    top++;
}

// Pop function
int pop() {
    if(top == 0) {
        cout << "Stack Underflow\n";
        return -1;
    }
    top--;
    return stack[top];
}

// Display function
void display() {
    if(top == 0) {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Stack elements: ";
    for(int i = top - 1; i >= 0; i--) {
        cout << stack[i] << " ";
    }
    cout << endl;
}

int main() {
    push(1);
    push(2);
    push(3);

    cout << "Before pop: ";
    display();

    int x = pop();
    cout << "Popped element: " << x << endl;

    cout << "After pop: ";
    display();

    return 0;
}
