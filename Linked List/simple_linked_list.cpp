#include <iostream>
#include <cstdlib>
using namespace std;

struct node{
    int data;
    node *next;
};

node *list = NULL;

void insert(int value){
    node *temp = (node*) malloc(sizeof(node));
    temp->data = value;
    temp->next = NULL;

    if(list == NULL){
        list = temp;
    }
    else{
        node *current = list;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = temp;
    }
}

void search(int key){
    if(list == NULL){
        cout << "LIST IS EMPTY!";
        return;
    }

    node *temp = list;
    int pos = 1;
    int flag = 0;

    while(temp != NULL){
        if(temp->data == key){
            flag = 1;
            cout << "ELEMENT IS FOUND AT " << pos << " POSITION";
        }
        temp = temp->next;
        pos++;
    }

    if(flag == 0){
        cout << "NOT FOUND IN THE LIST";
    }
}

void delete_node(int value){
    if (list == NULL){
        cout << "LIST IS EMPTY";
        return;
    }

    node *current = list;

    if(value == list->data){
        list = list->next;
        free(current);
        cout << "DELETE SUCCESSFULLY";
        return;
    }

    node *previous = list;
    current = list->next;

    while(current != NULL){
        if(value == current->data){
            previous->next = current->next;
            free(current);
            cout << "DELETE SUCCESSFULLY";
            return;
        }
        previous = current;
        current = current->next;
    }

    cout << "VALUE DOES NOT EXIST";
}

void display(){
    if (list == NULL){
        cout << "LIST IS EMPTY";
        return;
    }

    node *temp = list;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main(){
    int sel, flag = 0, num;

    while(flag == 0){
        cout << "\n\nSELECT FROM MENU" << endl
             << "1. Insert" << endl
             << "2. Search" << endl
             << "3. Delete" << endl
             << "4. Display" << endl
             << "5. Exit" << endl
             << "Enter the number (1-5): ";

        cin >> sel;

        switch (sel){
        case 1:
            cout << "\nEnter a number to insert: ";
            cin >> num;
            insert(num);
            break;

        case 2:
            cout << "\nEnter Number to search: ";
            cin >> num;
            search(num);
            break;

        case 3:
            cout << "\nEnter the number to delete: ";
            cin >> num;
            delete_node(num);
            break;

        case 4:
            cout << "\nDISPLAY ALL ELEMENTS\n";
            display();
            break;

        case 5:
            flag = 1;
            cout << "\nProgram exiting...";
            break;

        default:
            cout << "\nInvalid choice. Please try again.";
        }
    }

    return 0;
}

