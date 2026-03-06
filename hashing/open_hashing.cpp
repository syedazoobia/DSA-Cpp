#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

node hashtable[10];


void insert(int value)
{
    int index = value % 10;

    if (hashtable[index].data == -1)
    {
        hashtable[index].data = value;
        hashtable[index].next = NULL;
    }
    else
    {
        node *newnode = new node;
        newnode->data = value;
        newnode->next = NULL;

        node *current = hashtable[index].next;

        if(current == NULL)
        {
            hashtable[index].next = newnode;
            return; 
        }

        while (current->next != NULL)
        {
            current = current->next;
        }

        current->next = newnode;
    }
}

void search(int value)
{
    int index = value  % 10;

    node *temp = hashtable[index].next;

    while (temp != NULL)
    {
        if (temp->data == value)
        {
            cout << "Value found at index " << index << endl;
            return;
        }
        temp = temp->next;
    }

    cout << "Not found!\n";
}

void display()
{
    cout << "\n\n";
    for (int i = 0; i < 10; i++)
    {
        cout << i << " : ";

        if (hashtable[i].data == -1)
        {
            cout << "\t-";
        }
        else
        {
            cout << "\t" << hashtable[i].data;
            node *temp = hashtable[i].next;

            while (temp != NULL)
            {
                cout << "\t" << temp->data << "\t";
                temp = temp->next;
            }
        }

        cout << endl;
    }
}


int main()
{
    for (int i = 0; i < 10; i++)
    {
        hashtable[i].data = -1;
        hashtable[i].next = NULL;
    }

    int sel, val;
    bool exitflag = false;

    while (!exitflag)
    {
        cout << "\n\nSELECT FROM MENU\n"
             << "1. Insert\n"
             << "2. Search\n"
             << "3. Display\n"
             << "4. exit\n"
             << "Enter choice: ";
        cin >> sel;
        

        switch (sel)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> val;
            insert(val);
            break;

        case 2:
            cout << "Enter value to Search: ";
            cin >> val;
            search(val);
            break;

        case 3:
            cout << "DISPLAY ALL ELEMENTS";
            display();
            break;

        case 4:
            cout << "program exiting.....";
            exitflag = true;
            break;

        default:
            cout << "Invalid choice. try again......\n";
        }
    }
}
