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

void remove_vertex(char key)
{
    if (Head == NULL)
        return;

    Vertices *temp = Head;
    Vertices *prev = NULL;

    if (temp->data == key)
    {
        Head = temp->next;
        delete temp;
        return;
    }

    while (temp != NULL)
    {
        if (temp->data == key)
        {
            prev->next = temp->next;
            delete temp;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

void addEdges(char v1, char v2)
{
    Vertices *a = findVertex(v1);
    Vertices *b = findVertex(v2);

    if (a == NULL || b == NULL)
    {
        cout << "Vertex not found!\n";
        return;
    }

    edges *e1 = new edges;
    e1->vertics = b;
    e1->next = NULL;

    if (a->edgelist == NULL)
        a->edgelist = e1;
    else
    {
        edges *temp = a->edgelist;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = e1;
    }

    if (a != b)
    {
        edges *e2 = new edges;
        e2->vertics = a;
        e2->next = NULL;

        if (b->edgelist == NULL)
            b->edgelist = e2;
        else
        {
            edges *temp = b->edgelist;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = e2;
        }
    }
}

void remove_edge(char v1, char v2)
{
    Vertices *a = findVertex(v1);
    Vertices *b = findVertex(v2);

    if (a == NULL || b == NULL)
        return;

    edges *e = a->edgelist;
    edges *prev = NULL;

    while (e != NULL)
    {
        if (e->vertics->data == v2)
        {
            if (prev == NULL)
            {
                a->edgelist = e->next;
            }
            else
            {
                prev->next = e->next;
            }
            delete e;
            return;
        }
        prev = e;
        e = e->next;
    }

    e = b->edgelist;
    prev = NULL;
    while (e != NULL)
    {
        if (e->vertics->data == v1)
        {
            if (prev == NULL)
            {
                b->edgelist = e->next;
            }
            else
            {
                prev->next = e->next;
            }
            delete e;
            return;
        }
        prev = e;
        e = e->next;
    }
}

void neighbour(char v)
{
    Vertices *a = findVertex(v);

    if (a == NULL)
    {
        cout << "no vertex ";
        return;
    }

    cout << "THE NEIGHBOURS OF VERTEX " << v << " IS:";
    edges *e = a->edgelist;

    while (e != NULL)
    {
        cout << e->vertics->data << "  ";
        e = e->next;
    }
}
void Degree(char v)
{
    Vertices *a = findVertex(v);
    int count = 0;
    edges *e = a->edgelist;

    while (e != NULL)
    {
        if (e->vertics->data == v)
        {
            count = count + 2;
        }
        else
        {
            count++;
        }
        e = e->next;
    }

    cout << "Degree of " << a->data << " is " << count << endl;
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
        cout << "NULL\n";
        v = v->next;
    }
}

void reset()
{

    Vertices *temp = Head;

    while (temp != NULL)
    {
        temp->visited = false;
        temp = temp->next;
    }
}

bool iscycle(Vertices *v, Vertices *parent)
{

    v->visited = true;

    edges *e = v->edgelist;



    while (e != NULL)
    {

        Vertices *neighbour = e->vertics;

        if (!neighbour->visited)
        {
            if (iscycle(neighbour, v))
            {
                return true;
            }
        }
        else if (neighbour != parent)
        {
            return true;
        }
        e = e->next;
    }
    return false;
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
        t = t->next;
    }
    return true;
}

struct node2
{
    Vertices *value;
    node2 *next;
};

node2 *stackTop = NULL;

void push(Vertices *v)
{
    node2 *newnode = new node2();
    newnode->value = v;
    newnode->next = stackTop;
    stackTop = newnode;
}

Vertices *pop()
{
    if (stackTop == NULL)
        return NULL;

    node2 *temp = stackTop;
    stackTop = stackTop->next;

    Vertices *v = temp->value;
    delete temp;

    return v;
}

bool isEmpty()
{
    return stackTop == NULL;
}

void dfs()
{

    reset();

    Head->visited = true;
    push(Head);

    while (!isEmpty())
    {
        Vertices *temp = pop();
        cout << temp->data << " ";

        edges *e = temp->edgelist;

        while (e != NULL)
        {
            if (!e->vertics->visited)
            {
                e->vertics->visited = true;
                push(e->vertics);
            }
            e = e->next;
        }
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

bool isconnected(char v1, char v2)
{

    Vertices *a = findVertex(v1);
    Vertices *b = findVertex(v2);

    if (a == NULL || b == NULL)
    {
        cout << "Vertex not found";
        return false;
    }

    a->visited = true;
    if (v1 == v2)
    {
        return true;
    }

    edges *e = a->edgelist;

    while (e != NULL)
    {
        if (!e->vertics->visited)
        {
            if (isconnected(e->vertics->data, v2))
            {
                return true;
            }
        }
        e = e->next;
    }
    return false;
}

bool isadjacent(char v1, char v2)
{
    Vertices *a = findVertex(v1);
    Vertices *b = findVertex(v2);

    if (a == NULL || b == NULL)
    {
        cout << "VERTEX NOT FOUND";
        return false;
    }

    edges *e = a->edgelist;

    while (e != NULL)
    {
        if (e->vertics == b)
        {
            return true;
        }
        e = e->next;
    }
    return false;
}

int main()
{
    addVertices('A');
    addVertices('B');
    addVertices('C');
    addVertices('D');
    addVertices('E');
    addVertices('F');
    addVertices('G');

    addEdges('A', 'B');
    addEdges('A', 'D');
    addEdges('B', 'C');
    addEdges('C', 'E');
    addEdges('D', 'E');
    addEdges('C', 'D');

    cout << "\nGRAPH:\n";
    display();

    cout << "\nREMOVE F VERTEX\n";
    remove_vertex('F');
    display();

    cout << "\nBFS:\n";
    bfs();
    cout << "\n";

    cout << "\nDFS:\n";
    dfs();
    cout << "\n";

    cout << "\nDEGREE\n";
    Degree('A');
    cout << "\n";

    cout << "\nNEIGHBOURS\n";
    neighbour('A');
    cout << "\n";

    cout << "\nPATH\n";
    reset();
    if (!path('A', 'E'))
    {
        cout << "NO PATH";
    };
    cout << "\n";

    cout << "\nCYCLE\n";
    reset();

    if (iscycle(Head, NULL))
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
    if (isconnected('A', 'D'))
        cout << "Connected\n";
    else
        cout << "Not Connected\n";
    cout << "\n";

    cout << "\nNODE A CONNECTED TO C\n";
    reset();
    if (isadjacent('A', 'C'))
        cout << "Adjacent\n";
    else
        cout << "Not Adjacent\n";
    cout << "\n";
    return 0;
}