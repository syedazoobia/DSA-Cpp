#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

node hashtable[5];

void insert(int value)
{
    int index = value % 5;

    if (hashtable[index].data == -1)
    {
        hashtable[index].data = value;
        hashtable[index].next = NULL;
        return;
    }

    node *newnode = new node;
    newnode->data = value;
    newnode->next = NULL;

    node *temp = hashtable[index].next;

    if (temp == NULL)
    {
        hashtable[index].next = newnode;
        return;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void search(int value)
{
    int index = value % 5;
    int pos = 1;

    if (hashtable[index].data == value)
    {
        cout << "Found at index" << index << ",position " << pos;
        return;
    }

    node *temp = hashtable[index].next;

    while (temp != NULL)
    {
        pos++;
        if (temp->data == value)
        {
            cout << "Found at index" << index << ", position " << pos;
            return;
        }
        temp = temp->next;
    }
    cout << "NOT FOUND!";
}

void display(){
    for(int i=0; i<5; i++){
            cout << i <<":\t";


        if(hashtable[i].data == -1){
            cout << "-";
        }

        else{
            cout << hashtable[i].data << "\t";

            node *temp = hashtable[i].next;
            
            while(temp != NULL){
                cout << temp->data << "\t";
                temp = temp->next;
            }

        }
        cout <<endl;
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
            cout << "\nDISPLAY ALL ELEMENTS\n";
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