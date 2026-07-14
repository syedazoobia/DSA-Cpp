#include <iostream>
using namespace std;

struct Vertices;
struct edges;

struct node
{
    Vertices *value;
    node *next;
};

node *front = NULL;
node *rear = NULL;

void EnQueue(Vertices *val)
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

Vertices *DeQueue()
{
    if (front == NULL)
        return NULL;

    node *temp = front;
    front = front->next;

    Vertices *val = temp->value;
    delete temp;

    if (front == NULL)
        rear = NULL;

    return val;
}

struct Vertices
{
    char data;
    Vertices *next;
    edges *edgelist;
    bool visited;
    bool instack;
};

struct edges
{
    Vertices *vertics;
    edges *next;
};

Vertices *Head = NULL;

Vertices *addVertices(char v)
{
    Vertices *newNode = new Vertices;
    newNode->data = v;
    newNode->next = NULL;
    newNode->edgelist = NULL;
    newNode->visited = false;
    newNode->instack = false;

    if (Head == NULL)
        Head = newNode;
    else
    {
        Vertices *temp = Head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    return newNode;
}

Vertices *findVertex(char val)
{
    Vertices *temp = Head;

    while (temp != NULL)
    {
        if (temp->data == val)
            return temp;

        temp = temp->next;
    }
    return NULL;
}

void addEdges(char v1, char v2)
{
    Vertices *src = findVertex(v1);
    Vertices *dest = findVertex(v2);

    if (src == NULL || dest == NULL)
    {
        cout << "Vertex not found!\n";
        return;
    }

    edges *newEdge = new edges;
    newEdge->vertics = dest;
    newEdge->next = NULL;

    if (src->edgelist == NULL)
        src->edgelist = newEdge;
    else
    {
        edges *temp = src->edgelist;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newEdge;
    }
}

void display()
{
    Vertices *v = Head;

    while (v != NULL)
    {
        cout << v->data << " -> ";
        edges *e = v->edgelist;

        while (e != NULL)
        {
            cout << e->vertics->data << " -> ";
            e = e->next;
        }
        cout << endl;
        v = v->next;
    }
}
void reset(){
    Vertices *temp = Head;
    while(temp != NULL){
        temp->visited = false;
        temp->instack =false;
        temp=temp->next;
    }
}

void bfs()
{
    reset();

    Head->visited = true;
    EnQueue(Head);

    while (front != NULL)
    {
        Vertices *temp = DeQueue();
        cout << temp->data << " ";

        edges *e = temp->edgelist;

        while (e != NULL)
        {
            if (!e->vertics->visited)
            {
                e->vertics->visited = true;
                EnQueue(e->vertics);
            }
            e = e->next;
        }
    }
}

void degree(char v)
{
    Vertices *a = findVertex(v);

    if (a == NULL)
    {
        cout << "vertex not found";
        return;
    }

    edges *e = a->edgelist;
    int out = 0;
    int in = 0;

    while (e != NULL)
    {
        out++;
        e = e->next;
    }
    cout << "THE OUT DEGREE OF " << v << " is : " << out;

    Vertices *temp = Head;
    while (temp != NULL)
    {

        edges *e2 = temp->edgelist;

        while (e2 != NULL)
        {

            if (e2->vertics == a)
            {
                in++;
            }
            e2  = e2->next;
        }
        temp = temp->next;
    }
    cout << "\nTHE IN DEGREE OF " << v << " is : " << in;
}

void neighbour(char v){
    Vertices *a = findVertex(v);
    
    if (a == NULL){
        cout << "no vertex ";
        return;
    }

    cout << "THE NEIGHBOURS OF VERTEX " << v << " IS:";
    edges *e = a->edgelist;
    
    while(e != NULL){
        cout << e->vertics->data << "  ";
        e = e->next;
    }
}


bool path(char start, char end)
{
    Vertices *a = findVertex(start);
    Vertices *b = findVertex(end);

    if (a == NULL || b == NULL)
    {
        return false;
    }

    a->visited = true;
    cout << start << " ";

    if (start == end)
    {
        return true;
    }

    edges *e = a->edgelist;

    while (e != NULL)
    {
        if (!e->vertics->visited)
        {
            if (path(e->vertics->data, end))
                return true;
        }
        e = e->next;
    }

    return false;
}

bool isconnected(char v1, char v2){

    Vertices *a = findVertex(v1);
    Vertices *b = findVertex(v2);

    if(a == NULL || b == NULL){
        cout<< "Vertex not found";
        return false;
    }

    a->visited = true;
    if(v1 == v2){
        return true;
    }

    edges *e = a->edgelist;

    while(e!= NULL){
        if(!e->vertics->visited){
            if(isconnected(e->vertics->data,v2)){
                return true;
            }
        }
        e = e->next;
    }
    return false;
}

bool isadjacent(char v1, char v2){
    Vertices *a = findVertex(v1);
    Vertices *b = findVertex(v2);

    if(a == NULL || b == NULL){
        cout<< "VERTEX NOT FOUND";
        return false;
    }

    edges *e = a->edgelist;

    while(e != NULL){
        if(e->vertics == b){
            return true;
        }
        e = e->next;
    }
    return false;
}
bool isgraohconnected()
{
    reset();

    Head->visited = true;
    EnQueue(Head);

    while (front != NULL)
    {

        Vertices *temp = DeQueue();
        edges *e = temp->edgelist;

        while (e != NULL)
        {
            if (!e->vertics->visited)
            {
                e->vertics->visited = true;
                EnQueue(e->vertics);
            }
            e = e->next;
        }
    }

    Vertices *t = Head;

    while (t != NULL)
    {
        if (!t->visited)
        {
            return false;
        }
        t= t->next;
    }
    return true;
}


bool iscycle(Vertices *v)
{

    v->visited = true;
    v->instack = true;

    edges *e = v->edgelist;

    while (e != NULL)
    {

        Vertices *neighbour = e->vertics;

        if (!neighbour->visited)
        {
            if (iscycle(neighbour))
            {
                return true;
            }
        }
        else if (neighbour->instack)
        {
            return true;
        }
        e = e->next;
    }
    v->instack = false;
    return false;
}


int main()
{
    addVertices('A');
    addVertices('B');
    addVertices('C');
    addVertices('D');
    addVertices('E');

    addEdges('A', 'B');
    addEdges('A', 'D');
    addEdges('B', 'C');
    addEdges('C', 'E');
    addEdges('D', 'E');
    addEdges('C', 'D');

    cout << "\nGRAPH\n";
    display();

    cout << "\nBFS:\n";
    bfs();

    cout << "\nDEGREE:\n";
    degree('E');

    cout << "\nNEIGHBOURS:\n";
    neighbour('B');

    cout << "\nPATH\n";
    reset();
    if (!path('A', 'E'))
    {
        cout << "NO PATH";
    };
    cout << "\n";

    cout << "\nCYCLE\n";
    reset();

    if (iscycle(Head))
        cout << "Cycle Exists\n";
    else
        cout << "No Cycle\n";
    cout << "\n";

    cout << "\nGRAPH CONNECTED\n";

    if (isgraohconnected())
        cout << "graph connected\n";
    else
        cout << "graph not connected\n";
    cout << "\n";

    cout << "\nNODE A CONNECTED TO D\n";
    reset();
     if (isconnected('A','D'))
        cout << "Connected\n";
    else
        cout << "Not Connected\n";
    cout << "\n";

    cout << "\nNODE A CONNECTED TO C\n";
    reset();
     if (isadjacent('A','C'))
        cout << "Adjacent\n";
    else
        cout << "Not Adjacent\n";
    cout << "\n";

    return 0;
}