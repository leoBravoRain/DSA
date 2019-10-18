#include <iostream>

// using namespace
using namespace std;

// define node
struct node
{
    int value;
    node *next;
};
// define data type
typedef struct node node;

// prototype
void appendToListL(node **l, int num);
void printList(node *l);
void inserInList(node **l, int num);
float mediaList(node *l);
int minList(node *l);
int maxList(node *l);
void appendList(node **l, node *q);
void addPrevVal(node *l);
void insertList(node **l, node *q);

int main()
{
    srand(100);

    // define linked list (head)
    node *linked_list = NULL;
    // define linked list q
    node *q = NULL;
    // list of ints
    int n = 5;
    int list[n] = {rand()%10, rand()%10, rand()%10, rand()%10, rand()%10};
    int list_2[n] = {rand()%10, rand()%10, rand()%10, rand()%10, rand()%10};
    // add list elements to linked list
    for (int i = 0; i < n; i++)
    {
        // // add node to left
        appendToListL(&linked_list, list[i]);
        // print list
        // printList(linked_list);
    }
    // add list elements to linked list
    for (int i = 0; i < n; i++)
    {
        // add node to left
        appendToListL(&q, list_2[i]);
        // // print list
        // printList(q);
    }
    // printList(linked_list);
    // printList(q);
    // cout << q << endl;
    // add list
    // appendList(&linked_list, q);

    // print list
    // printList(linked_list);

    // add previuos values
    // this method ensure list is ascending order
    addPrevVal(linked_list);
    addPrevVal(q);

    // print list
    printList(linked_list);
    printList(q);

    // insert each node of q linked list in first linked list
    insertList(&linked_list, q);
    // // insert new element
    // inserInList(&linked_list, 15);

    // // print list
    // printList(linked_list);

    // // compute median
    // printf("Media: %f\n", mediaList(linked_list));
    // // minList(linked_list);
    // // compute min
    // printf("Min: %i\n", minList(linked_list));

    // printf("Max: %i\n", maxList(linked_list));

    // return to SO
    return EXIT_SUCCESS;
}

// add node to list by the right
void appendToListL(node **l, int num)
{
    // printf("Add new node\n");
    // allocate memory to new node
    node *new_node_p = new node;
    new_node_p->value = num;
    new_node_p->next = *l;
    *l = new_node_p;
}

// print list
void printList(node *l)
{
    // printf("Printing linked list\n");
    node *p = l;
    if (p == nullptr)
    {
        printf("Empty list !\n");
    }
    // iterate over list
    while (p != nullptr)
    {
        // print value
        cout << p->value << " ";
        // point to next node
        p = p->next;
    }
    cout << endl;
}

// Cree la función void inserInList(nodo **`, int num); que inserte el nodo
// en su posición correcta.
void inserInList(node **l, int num)
{
    // create new node
    node *new_node = new node;
    new_node->value = num;
    // if num is smaller than first element of linked list
    if (num < (*l)->value)
    {
        // add new node as head
        new_node->next = *l;
        *l = new_node;
    }
    // if num is greater than first element
    else
    {
        // create temp pointer of node to linked list
        node *temp = *l;
        // find predecessor of new node
        while (temp->next != NULL && temp->next->value < num)
        {
            temp = temp->next;
        }
        // next node of the new one
        new_node->next = temp->next;
        // predecessor of new point to new
        temp->next = new_node;
    }
}

// Cree las funciones float mediaList(nodo* `); int minList(nodo* `) e int
// maxList(node* `) que recorra la lista ` y entregue la media, el mínimo y el
// máximo respectivamente.
float mediaList(node *l)
{
    // counter
    int count = 0;
    // sum for median
    int sum = 0;
    // take fisrt element
    node *p = l;
    // iterate linked list
    while (p != nullptr)
    {
        sum += p->value;
        count++;
        p = p->next;
    }

    // printf("length: %i\nsum: %i\n", count, sum);
    return (float)sum / (float)count;
}

// Cree las funciones float mediaList(nodo* `); int minList(nodo* `) e int
// maxList(node* `) que recorra la lista ` y entregue la media, el mínimo y el
// máximo respectivamente.
int minList(node *l)
{
    // define min
    int min = 100000000000;
    // temp pointer
    node *p = l;
    // find min
    while (p != nullptr)
    {
        // cout << p->value << endl;

        if (p->value < min)
        {
            min = p->value;
            // printf("new min: %i\n", min);
        }
        p = p->next;
    }
    // cout << min << endl;
    return min;
}

// Cree las funciones float mediaList(nodo* `); int minList(nodo* `) e int
// maxList(node* `) que recorra la lista ` y entregue la media, el mínimo y el
// máximo respectivamente.
int maxList(node *l)
{
    // define max
    int max = -1;
    // temp pointer
    node *p = l;
    // find max
    while (p != nullptr)
    {
        // cout << p->value << endl;

        if (p->value > max)
        {
            max = p->value;
            // printf("new max: %i\n", max);
        }
        p = p->next;
    }
    // cout << max << endl;
    return max;
}

// 2.- Cree un procedimiento appendList(nodo** l, node* q), que añadirá la lista
// q al final de ∗ l.
void appendList(node **l, node *q)
{
    // if linked list l is empty
    if (*l == nullptr)
    {
        *l = q;
    }
    // if is not empty
    else
    {
        node *p = *l;
        while (p->next != nullptr)
        {
            p = p->next;
        }
        // printf("final p founded !\n");
        // cout << q << endl;
        // cout << "next of p: " << p->value << endl;
        p->next = q;
        // printf("final append LIST !\n");
    }
}

// 3.- Cree un procedimiento addPrevVal(nodo *`), que recorra la lista ` y a cada
// nodo sume acumulativamente el valor del predecesor.
// Ej: ` = 6 → 19 → 2 → 8 ⇒ ` = 6 → 25 → 27 → 35 (note que la lista queda
// creciente)
void addPrevVal(node *l)
{
    int sum = 0;
    node *p = l;
    while (p != nullptr)
    {
        p->value = p->value + sum;
        sum += p->value;
        p = p->next;
    }
}

// 4.- Cree un procedimiento insertList(nodo** `, nodo *q), donde *` y q están
// ordenadas ascendentemente (luego de invocar al método anterior). Inserté a la
// lista *` todos los nodos de la lista q en sus posiciones correctas.
void insertList(node **l, node *q)
{
    // q auxiliar iteartor
    node *a = q;
    // l auxiliar iterator
    node *b = *l;
    // iterate through q
    while (a != nullptr)
    {
        // printf("Add element: %i\n", a->value);
        // if a (i-th element of q) is smaller than first p element
        if (a->value <= (*l)->value)
        {
            // change head of l
            a->next = *l;
            *l = a;
        }
        else
        {
            // printf("%i > %i\n", a->value, (*l)->value);
            // if is greater
            // iterate through l
            while (b != nullptr)
            {
                // if is smaller
                if (a->value <= b->next->value)
                {
                    // printf("%i <= %i\n", a->value, b->next->value);
                    a->next = b->next;
                    b->next = a;
                    // printf("from %i to %i \n", b->next->value, a->next->value);
                    break;
                }
                else
                {
                    b = b->next;
                }
            }
        }

        a = a->next;
    }
}

// Cree la función bool removeFromList(nodo **`, int num); esta debe
// retornar verdadero si encontró y eliminó el nodo con valor num.
bool removeFromList(nodo **`, int num);