#include <iostream>
using namespace std;
class node
{
public:
    int value;
    node *next;
    node *pre;
};
node *tail;
node *head;
void link()
{
    node *p = head;
    while (p->next != nullptr)
    {
        p->next->pre = p;
        p = p->next;
    }
}
void readbackward(node *n)
{
    cout << "here is your list backward :" << endl;
    while (n != NULL)
    {
        cout << n->value << endl;
        n = n->pre;
    }
}
void readforward(node *n)
{
    cout << "here is your list :" << endl;

    while (n != NULL)
    {
        cout << n->value << endl;
        n = n->next;
    }
}
void addlast(int x)
{
    node *newnode = new node();
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        head->next = nullptr;
    }
    else
    {
        newnode->value = x;
        tail->next = newnode;
        newnode->next = nullptr;
        tail = newnode;
    }
}
int main()
{
    node *newnod = new node();
    newnod->value = 0;
    newnod->next = nullptr;
    newnod->pre = nullptr;
    head = newnod;
    tail = newnod;
    for (int i = 1; i < 5; i++)
    {
        addlast(i);
    }
    readforward(head);
    link();
    readbackward(tail);
}
