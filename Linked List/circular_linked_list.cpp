#include <iostream>
#include <cstdlib>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *list = NULL;

void insert(int value)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = value;

    if (list == NULL)
    {
        list = newnode;
        list->next = list;
    }
    else
    {
        node *current = list;
        while (current->next != list)
        {
            current = current->next;
        }
        current->next = newnode;
        newnode->next = list;
    }
}

void search(int key)
{
    if (list == NULL)
    {
        cout << "LIST IS EMPTY!";
        return;
    }

    node *temp = list;
    int pos = 1;

    do
    {
        if (temp->data == key)
        {
            cout << "ELEMENT FOUND AT POSITION: " << pos;
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != list);

    cout << "NOT FOUND IN THE LIST";
}

void delete_node(int value)
{
    if (list == NULL)
    {
        cout << "LIST IS EMPTY";
        return;
    }

    node *current = list;
    node *prev = NULL;

    if (list->data == value)
    {

        if (list->next == list)
        {
            free(list);
            list = NULL;
            cout << "DELETED SUCCESSFULLY";
            return;
        }

        node *last = list;
        while (last->next != list)
        {
            last = last->next;
        }
        list = list->next;
        last->next = list;
        free(current);
        cout << "DELETED SUCCESSFULLY";
        return;
    }

    prev = list;
    current = current->next;

    while (current != list)
    {
        if (current->data == value)
        {
            prev->next = current->next;
            free(current);
            cout << "DELETED SUCCESSFULLY";
            return;
        }
        prev = current;
        current = current->next;
    }
     cout << "VALUE NOT FOUND";
}

void display()
{
    if (list == NULL)
    {
        cout << "LIST IS EMPTY";
        return;
    }
    node *temp = list;
    do
    {
        cout << temp->data << "  ";
        temp = temp->next;
    } while (temp != list);
}

int main()
{
    int sel, flag = 0, num;

    while (flag == 0)
    {
        cout << "\n\nSELECT FROM MENU"
             << "\n1. Insert"
             << "\n2. Search"
             << "\n3. Delete"
             << "\n4. Display"
             << "\n5. Exit"
             << "\nEnter the number (1-5): ";

        cin >> sel;

        switch (sel)
        {
        case 1:
            cout << "Enter a number to insert: ";
            cin >> num;
            insert(num);
            break;

        case 2:
            cout << "Enter number to search: ";
            cin >> num;
            search(num);
            break;

        case 3:
            cout << "Enter the number to delete: ";
            cin >> num;
            delete_node(num);
            break;

        case 4:
            cout << "DISPLAY ALL ELEMENTS\n";
            display();
            break;

        case 5:
            flag = 1;
            cout << "Program exiting...";
            break;

        default:
            cout << "Invalid choice!";
        }
    }

    return 0;
}
