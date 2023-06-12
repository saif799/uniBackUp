#include <iostream>
using namespace std;
class node
{
public:
    int value;
    node *next;
    node *pre;
};
node *tail = nullptr;
node *head = nullptr;

void readforward(node *n)
{
    if (head != nullptr)
    {

        cout << "here is your list :" << endl;

        while (n != NULL)
        {
            cout << n->value << " ";
            n = n->next;
        }
    }
    else
    {
        cout << "list est vide :";
    }
    cout << endl;
}
void exchange(int exvlaue)
{
    node *p = head;
    while (p->value != exvlaue)
    {
        p = p->next;
    }
    p->pre->next = p->next;
    p->next->pre = p->pre;
    p->next = head;
    head = p;
    p->pre = nullptr;
}
void readbackward(node *n)
{
    if (head != nullptr)
    {
        cout << "here is your list backward :" << endl;
        while (n != NULL)
        {
            cout << n->value << endl;
            n = n->pre;
        }
    }
    else
    {
        cout << "your list is empty ." << endl;
    }
}
void addfirst(int x)
{
    node *newnode = new node();
    newnode->value = x;
    newnode->next = head;
    head->pre = newnode;
    newnode->pre = nullptr;
    head = newnode;
}
void addlast(int x)
{
    node *newnode = new node();
    newnode->pre = tail;
    newnode->value = x;
    tail->next = newnode;
    newnode->next = nullptr;
    tail = newnode;
}
void addbefore(node **headd, int value, int stop)
{
    node *newnode = new node();
    node *s = head;

    if (*headd == NULL)
    {
        newnode->value = value;
        head = newnode;
        tail = newnode;
        newnode->next = nullptr;
        newnode->pre = nullptr;
    }
    else
    {
        if (head->value == stop)
        {
            addfirst(value);
        }
        else
        {
            while (s->value != stop)
            {
                s = s->next;
            }
            newnode->pre = s->pre;
            newnode->next = s;
            newnode->value = value;

            (s->pre)->next = newnode;
            s->pre = newnode;
        }
    }
}
void addafter(node **headd, int value, int stop)
{
    node *newnode = new node();
    node *s = head;
    int v = value;
    if (*headd == NULL)
    {
        newnode->value = value;
        head = newnode;
        tail = newnode;
        newnode->next = nullptr;
        newnode->pre = nullptr;
    }
    else
    {
        if (tail->value == stop)
        {
            addlast(v);
        }
        else
        {
            while (s->value != stop)
            {
                s = s->next;
            }
            newnode->pre = s;
            newnode->next = s->next;
            newnode->value = value;

            (s->next)->pre = newnode;
            s->next = newnode;
        }
    }
}
void Delete(int dthis)
{
    node *ptr = head;
    while (ptr->value != dthis)
    {
        ptr = ptr->next;
    }
    if (head->value == ptr->value)
    {
        head = ptr->next;
        head->pre = nullptr;
        delete ptr;
        ptr = nullptr;
    }
    else if (tail->value == ptr->value)
    {
        tail = ptr->pre;
        tail->next = nullptr;
        delete ptr;
        ptr = nullptr;
    }
    else
    {
        (ptr->next)->pre = ptr->pre;
        (ptr->pre)->next = ptr->next;

        delete ptr;
        ptr = nullptr;
    }
}
void wtf(node *tete)
{
    node *p = head;
}
void iteratif(node *tete)
{
    node *p = tete;
    int k = 1;
    while (p != nullptr)
    {
        k++;
        p = p->next;
    }
    cout << "longeur de son list est " << k << endl;
}
int recursive(node *tete)
{
    if (tete == nullptr)
        return 0;
    else
        return 1 + recursive(tete->next);
}
void run()
{
    int x, value, stop, quit;
    quit = 0;
    while (quit != 1)
    {
        cout << "\n  1 add a node before : " << endl;
        cout << "  2 add a node after : " << endl;
        cout << "  3 delete a node :" << endl;
        cout << "  4 read your list forward : " << endl;
        cout << "  5 read your list backward :" << endl;
        cout << "  6 quit :" << endl;
        cout << "  7 exchange :" << endl;
        cin >> x;
        switch (x)
        {
        case 1:
            cout << "give me the value you want to add ." << endl;
            cin >> value;

            cout << "give the value of the node you want to add before it :" << endl;
            cin >> stop;
            addbefore(&head, value, stop);
            run();
            break;
        case 2:
            cout << "give me the value you want add ." << endl;
            cin >> value;
            cout << "give the value of the node you want to add after it :" << endl;
            cin >> stop;
            addafter(&tail, value, stop);
            run();
            break;
        case 3:
            cout << "give me the value you want to delete ." << endl;
            cin >> value;
            Delete(value);
            run();
            break;
        case 4:
            readforward(head);
            break;
        case 5:
            readbackward(tail);
            break;
        case 6:
            quit = 1;
            break;
        case 7:
            cout << "give me the value you want to exchange to the beginig : " << endl;
            cin >> value;
            exchange(value);
            break;
        default:
            cout << "re-enter your choice : ";
            break;
        }
    }
}
int main()
{
    // node *newnode = new node();
    // newnode->value = 5;
    // newnode->next = nullptr;
    // newnode->pre = nullptr;
    // head = newnode;
    // tail = newnode;
    run();
}