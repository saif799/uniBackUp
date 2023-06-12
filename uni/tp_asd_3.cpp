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
void readforward(node *n)
{
    if (head != nullptr)
    {
        cout << "here is your list :" << endl;

        while (n != NULL)
        {
            cout << n->value << endl;
            n = n->next;
        }
    }
    else
    {
        cout << "list est vide :" << endl;
    }
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
        cout << "list est vide :" << endl;
    }
}
void addlast(int x)
{
    node *newnode = new node();
    newnode->value = x;
    if (head != nullptr)
    {

        newnode->pre = tail;

        tail->next = newnode;
        newnode->next = nullptr;
        tail = newnode;
    }
    else
    {
        newnode->next = nullptr;
        newnode->pre = nullptr;
        head = newnode;
        tail = newnode;
    }
}

int main()
{
    int n, i, v;
    node *p;

    cout << "donner la tail : ";
    cin >> n;
    cout << "creation de la list de qui contient " << n << " element" << endl;
    p = head;
    for (i = 0; i < n; i++)
    {
        cout << "give me the value : ";
        cin >> v;
        addlast(v);
    }
    readforward(head);

    readbackward(tail);
}
