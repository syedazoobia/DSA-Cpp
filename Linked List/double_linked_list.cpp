#include <iostream>
#include <cstdlib>
using namespace std;

struct node
{
    int data;
    node *next;
    node *prev;
};

node *list = NULL;

void insert(int value)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = value;
    newnode->next = NULL;
    newnode->prev = NULL;

    if (list == NULL)
    {
        list = newnode;
        return;
    }

    node *current = list;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newnode;
    newnode->prev = current;
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

    while (temp != NULL)
    {
        if (temp->data == key)
        {
            cout << "ELEMENT FOUND AT POSITION: " << pos;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "NOT FOUND IN THE LIST";
}

void delete_node(int value)
{
    if (list == NULL)
    {
        cout << "LIST IS EMPTY";
        return;
    }

    node *temp = list;
    if (list->data == value)
    {
        list = list->next;
        if (list != NULL)
        {
            list->prev = NULL;
        }
        free(temp);
        cout << "DELETED SUCCESSFULLY";
        return;
    }

    temp = temp->next;
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            if (temp->next != NULL)
            {
                temp->next->prev = temp->prev;
            }
            if (temp->prev != NULL)
            {
                temp->prev->next = temp->next;
            }
            free(temp);
            cout << "DELETED SUCCESSFULLY";
            return;
        }
        temp = temp->next;
    }
    cout << "VALUE NOT FOUND";
}

void display_forward()
{
    if (list == NULL)
    {
        cout << "LIST IS EMPTY";
        return;
    }

    node *temp = list;
    while (temp != NULL)
    {
        cout << temp->data << "  ";
        temp = temp->next;
    }
}

void display_backward()
{
    if (list == NULL)
    {
        cout << "LIST IS EMPTY";
        return;
    }

    node *temp = list;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    while (temp != NULL)
    {
        cout << temp->data << "  ";
        temp = temp->prev;
    }
}

int main()
{
    int sel, flag = 0, num, dis;

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
            cout << "\nSELECT\n"
                 << "1. FORWARD DISPLAY \n"
                 << "2. Backward Display \n";
            cin >> dis;
            if (dis == 1)
            {
                cout << "DISPLAY ALL ELEMENTS IN FORWARD\n";
                display_forward();
            }
            else if (dis == 2)
            {
                cout << "\nDISPLAY ALL ELEMENTS IN BACKWARD\n";
                display_backward();
            }
            else
            {
                cout << "TRY AGAIN";
            }
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
