#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
    int height;
};

node *root = NULL;

int getheight(node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return n->height;
}

int balance_factor(node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return getheight(n->left) - getheight(n->right);
}

node *shift_left(node *current)
{
    node *newroot = current->right;
    node *temp = newroot->left;

    newroot->left = current;
    current->right = temp;

    current->height = max(getheight(current->left), getheight(current->right)) + 1;
    newroot->height = max(getheight(newroot->left), getheight(newroot->right)) + 1; 
    
    return newroot;
}

node *shift_right(node *current)
{
    node *newroot = current->left;
    node *temp = newroot->right;

    newroot->right = current;
    current->left = temp;

    current->height = max(getheight(current->left), getheight(current->right)) + 1;
    newroot->height = max(getheight(current->left), getheight(current->right)) + 1;

    return newroot;
}

node *shift_left_right(node *current)
{
    current->left = shift_left(current->left);
    return shift_right(current);
}

node *shift_right_left(node *current)
{
    current->right = shift_right(current->right);
    return shift_left(current);
}

node *insert(node *current, int value)
{
    if (current == NULL)
    {
        node *newnode = new node(); 
        newnode->data = value;
        newnode->left = NULL;
        newnode->right = NULL;
        newnode->height = 1;
        return newnode;
    }

    if (value < current->data)
    {
        current->left = insert(current->left, value);
    }
    else
    {
        current->right = insert(current->right, value);
    }

    current->height = max(getheight(current->left), getheight(current->right)) + 1;

    int balance = balance_factor(current);

    if (balance > 1 && value < current->left->data)
        return shift_right(current);

    if (balance < -1 && value > current->right->data)
        return shift_left(current);

    if (balance > 1 && value > current->left->data)
        return shift_left_right(current);
    
    if (balance < -1 && value < current->right->data)
        return shift_right_left(current);

    return current;
}

void search(node *current, int value)
{
    if (current == NULL)
    {
        cout << "Value not Found";
        return;
    }

    if (current->data == value)
    {
        cout << "Value Found";
        return;
    }

    if (value < current->data)
    {
        search(current->left, value);
    }
    else
    {
        search(current->right, value);
    }
}

node *to_delete(node *current, int value)
{
    if(current == NULL){
        cout << "Value not found";
        return NULL;
    }

    if(value < current->data){
        current->left = to_delete(current->left, value);
    }
    else if(value > current->data){
        current->right = to_delete(current->right, value);
    }

    else{
        if(current->left == NULL && current->right == NULL){
            delete current;
            return NULL;
        }

        else if(current->left == NULL){
            node *temp = current->right;
            delete current;
            return temp;
        }
        else if(current->right == NULL){
            node *temp = current->left;
            delete current;
            return temp;
        }

        else{
            node *temp = current->right;

            while(temp ->left != NULL){
                temp = temp -> left;
            }

            current->data = temp->data;
            current->right = to_delete(current->right, temp->data);
        }
    }

    if(current == NULL)
        return current;

     current->height = max(getheight(current->left), getheight(current->right)) + 1;

    int balance = balance_factor(current);

    if (balance > 1 && balance_factor(current->left) >= 0 )
        return shift_right(current);

    if (balance > -1 &&  balance_factor(current->right) <= 0)
        return shift_left(current);

    if (balance > 1 && balance_factor(current->left) < 0)
        return shift_left_right(current);
    
    if (balance < -1 && balance_factor(current->right) > 0)
        return shift_right_left(current);

    return current;
}

void inorder(node *current)
{
    if (current != NULL)
    {
        inorder(current->left);
        cout << current->data << "  ";
        inorder(current->right);
    }
}

void postorder(node *current)
{
    if (current != NULL)
    {
        postorder(current->left);
        postorder(current->right);
        cout << current->data << "  ";
    }
}

void preorder(node *current)
{
    if (current != NULL)
    {
        cout << current->data << "  ";
        preorder(current->left);
        preorder(current->right);
    }
}

int main()
{
    int sel, flag = 0, num, sel2;

    while (flag == 0)
    {
        cout << "\n\nSELECT FROM MENU" << endl
             << "1. Insert" << endl
             << "2. Search" << endl
             << "3. Delete" << endl
             << "4. Display" << endl
             << "5. Exit" << endl
             << "Enter the number (1-5): ";

        cin >> sel;

        switch (sel)
        {
        case 1:
            cout << "\nEnter Number to insert: ";
            cin >> num;
            root = insert(root, num);
            break;

        case 2:
            cout << "\nEnter Number to search: ";
            cin >> num;
            search(root, num);
            break;

        case 3:
            cout << "\nEnter the number to delete: ";
            cin >> num;
            root = to_delete(root, num);
            break;

        case 4:
            cout << "\nDISPLAY ALL ELEMENTS\n";
            cout << "\n1. Inorder\n2. Preorder\n3. Postorder\nEnter choice: ";
            cin >> sel2;

            if (sel2 == 1)
            {
                cout << "INORDER :  ";
                inorder(root);
            }
            else if (sel2 == 2)
            {
                cout << "PREORDER :  ";
                preorder(root);
            }
            else if (sel2 == 3)
            {
                cout << "POSTORDER :  ";
                postorder(root);
            }
            else
            {
                cout << "Invalid choice.... ";
            }
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