#include <iostream>
using namespace std;

struct node
{
    int value;
    node *next;
};

node *front = NULL;
node *rear = NULL;

void EnQueue(int val)
{
    node *newnode = new node();
    newnode->value = val;
    newnode->next = NULL;

    if (rear == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}

int DeQueue()
{
    if (front == NULL)
        return NULL;

    node *temp = front;
    front = front->next;

    int val = temp->value;
    delete temp;

    if (front == NULL)
        rear = NULL;

    return val;
}
void print_matrix(int mat[][10], int n)
{
    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << "  ";
        }
        cout << endl;
    }
}

void degree_undirected(int mat[][10], int n)
{
    cout << "\nDEGREES\n";
    for (int i = 0; i < n; i++)
    {
        int degree = 0;
        for (int j = 0; j < n; j++)
        {
            if (i == j && mat[i][j] == 1)
                degree += 2 * mat[i][j];
            else
                degree += mat[i][j];
        }
        cout << "Vertex " << i + 1 << " Degree = " << degree << endl;
    }
}

void degree_directed(int mat[][10], int n)
{
    cout << "IN-DEGREE AND OUT-DEGREE" << endl;

    for (int i = 0; i < n; i++)
    {
        int in = 0;
        int out = 0;

        for (int j = 0; j < n; j++)
        {
            out += mat[i][j];
            in += mat[j][i];
        }
        cout << "Vertex " << i + 1 << " -> In: " << in << ", Out: " << out << endl;
    }
}

int visited[10];

bool path(int mat[][10], int v, int start, int end, int visited[])
{
    if (start == end)
    {
        return true;
    }

    visited[start] = 1;

    for (int i = 0; i < v; i++)
    {
        if (mat[start][i] == 1 && !visited[i])
        {
            if (path(mat, v, i, end, visited))
            {
                return true;
            }
        }
    }
    return false;
}

void dfs_traversal(int mat[][10], int v, int start, int visited[])
{
    cout << start << " ";
    visited[start] = 1;

    for (int i = 0; i < v; i++)
    {
        if (mat[start][i] == 1 && !visited[i])
        {
            dfs_traversal(mat, v, i, visited);
        }
    }
}

bool cycle(int mat[][10], int v, int start, int visited[], int parent)
{
    visited[start] = 1;

    for (int i = 0; i < v; i++)
    {
        if (mat[start][i] == 1)
        {
            if (!visited[i])
            {
                if (cycle(mat, v, i, visited, start))
                {
                    return true;
                }
            }
            else if (i != parent)
            {
                    return true;
            }
        }
    }
    return false;
}

void neighbours(int mat[][10], int v, int node){

    cout << "Neighbours of " << node << " are: ";

    bool found = false;

    for(int i = 0; i < v; i++){
        if(mat[node][i] == 1){
            cout << i << " ";
            found = true;
        }
    }

    if(!found){
        cout << "None";
    }

    cout << endl;
}

void bfs(int mat[][10], int v, int start){
    for (int i = 0; i < v; i++)
        visited[i] = 0;


    visited[start] = 1;
    EnQueue(start);

    while(front != NULL){
        int temp = DeQueue();
        cout << temp + 1 << " ";

        for(int i=0; i<v; i++){
            if(mat[temp][i] == 1 && visited[i] == 0){
                visited[i] = 1;
                EnQueue(i);
            }
        }
    }
    cout << endl;
}
int main()
{
    // int i, j, v, choice;
    // cout << "Enter the number of vertexes: ";
    // cin >> v;

    // int mat[10][10];

    // cout << "\n1. Undirected Graph\n2. Directed Graph\n";
    // cout << "Enter your choice: ";
    // cin >> choice;
    // cout << endl;

    // if (choice == 1)
    // {

    //     for (int i = 0; i < v; i++)
    //     {
    //         for (int j = 0; j < v; j++)
    //         {
    //             if (i < j)
    //             {
    //                 cout << "Enter 1 if vertex " << i + 1 << " is adjacent to " << j + 1 << ", otherwise 0 : ";
    //                 cin >> mat[i][j];
    //                 mat[j][i] = mat[i][j];
    //             }

    //             else if (i == j)
    //             {
    //                 cout << "Enter 1 if self loop at vertex " << i + 1 << ", otherwise 0 : ";
    //                 cin >> mat[i][j];
    //             }
    //         }
    //     }

    //     print_matrix(mat, v);
    //     degree_undirected(mat, v);
    // }
    // else
    // {
    //     for (int i = 0; i < v; i++)
    //     {
    //         for (int j = 0; j < v; j++)
    //         {
    //             cout << "Enter 1 if vertex " << i + 1 << " is adjacent to " << j + 1 << ", otherwise 0 : ";
    //             cin >> mat[i][j];
    //         }
    //     }

    //     print_matrix(mat, v);
    //     degree_directed(mat, v);
    // }

    // cout << "\n\nSEARCH FOR PATH"<<endl;
    // int start, end;

    // cout << "\nEnter start vertex: ";
    // cin >> start;

    // cout << "Enter end vertex: ";

    // cin >> end;

    // for (int i = 0; i < v; i++)
    //     visited[i] = 0;

    // if (dfs(mat, v, start - 1, end - 1, visited))
    //     cout << "Path Exists!\n";
    // else
    //     cout << "No Path!\n";

    int v = 4;

    int mat[10][10] = {
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
        {0, 0, 0, 0}};

    cout << "\n\nSEARCH FOR CYCLE" << endl;
    int start;

    cout << "\nEnter start vertex: ";
    cin >> start;

    for (int i = 0; i < v; i++)
    {
        visited[i] = 0;
    }
    if (cycle(mat, v, start - 1, visited, -1))
    {
        cout << "cycle exits!";
    }
    else
    {
        cout << "cycle not exit";
    }

    cout << "\n";

    
    neighbours(mat, v, 1);
    cout << "\n";
    dfs_traversal(mat, v , 1, visited);
    cout << "\n";
    bfs(mat, v, 1);
     
    return 0;
}