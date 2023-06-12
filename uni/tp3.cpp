#include <iostream>

using namespace std;
class stacks
{
    stacks *top = nullptr;
    stacks *next;
    int v;
    string f;
    int size = 0;

public:
    void push(int x)
    {
        stacks *n = new stacks();
        n->v = x;
        if (top == nullptr)
        {
            n->next = nullptr;
            top = n;
        }
        else
        {
            n->next = top;
            top = n;
        }
        size++;
    }
    void pushchar(string x)
    {
        stacks *n = new stacks();
        n->f = x;
        if (top == nullptr)
        {
            n->next = nullptr;
            top = n;
        }
        else
        {
            n->next = top;
            top = n;
        }
        size++;
    }
    bool empty()
    {
        bool x;
        if (top == nullptr)
            x = true;
        else
            x = false;
        return x;
    }
    int topp()
    {
        return top->v;
    }
    string toppstirng()
    {
        return top->f;
    }
    void pop()
    {

        if (top == nullptr)
        {
            cout << "stack is empty ." << endl;
        }
        else
        {
            stacks *ppop = top;
            top = top->next;
            delete ppop;
            size--;
        }
    }
    int length()
    {
        return size;
    }
    void change(int dd)
    {
        top->v = dd;
    }
};
void invStack(stacks *old, stacks *news)
{
    stacks *d;
    while (!old->empty())
    {
        news->push(old->topp());
        d->push(old->topp());
        old->pop();
    }
    while (!d->empty())
    {
        old->push(d->topp());
        d->pop();
    }
}
void print(stacks *dre)
{
    if (dre->empty())
        cout << "vide" << endl;
    else
    {
        while (!dre->empty())
        {
            cout << dre->topp() << endl;
            dre->pop();
        }
    }
}
bool isitt()
{
    stacks *f = new stacks();
    int y;
    string tab[20], x, s;
    cout << "whats the size : ";
    cin >> y;
    for (int i = 0; i < y; i++)
        cin >> tab[i];
    for (int i = 0; i < y; i++)
    {
        x = tab[i];
        if (x == "{" || x == "[" || x == "(")
            f->pushchar(x);
        if ((x == ")" || x == "]" || x == "}") && f->empty())
        {
            i = y + 1;
            return false;
        }
        else if (x == "}" && f->toppstirng() != "{" || x == "]" && f->toppstirng() != "[" || x == ")" && f->toppstirng() != "(")
        {
            return false;
            i = y + 1;
        }
        else if (x == "}" && f->toppstirng() == "{" || x == "]" && f->toppstirng() == "[" || x == ")" && f->toppstirng() == "(")
            f->pop();
        else if (x == ".")
            i = y + 1;
    }
    if (f->empty())
        return true;
    else
        return false;
}
void isit()
{
    stacks *f = new stacks();
    int y, z = 1;
    string tab[20], x, s;
    cout << "whats the size : ";
    cin >> y;
    for (int i = 0; i < y; i++)
        cin >> tab[i];
    for (int i = 0; i < y; i++)
    {
        x = tab[i];
        if (x == "{" || x == "[" || x == "(")
        {
            f->pushchar(x);
            z = 0;
        }
        if ((x == ")" || x == "]" || x == "}") && f->empty())
        {
            i = y + 1;
            z = 0;
        }
        // else if (x == "}" && f->toppstirng() != "{" || x == "]" && f->toppstirng() != "[" || x == ")" && f->toppstirng() != "(")
        // {
        //     z = 0;
        //     i = y + 1;
        // }
        else if (x == "}" && f->toppstirng() == "{" || x == "]" && f->toppstirng() == "[" || x == ")" && f->toppstirng() == "(")
        {
            f->pop();
            if (f->empty())
                z = 1;
        }
        else if (x == ".")
            i = y + 1;
    }
    if (z == 1)
        cout << " bien " << endl;
    else
        cout << " not bien" << endl;
}
int main()
{

    // stacks *d = nullptr;
    // stacks *s = nullptr;
    // d->push(5);
    // d->push(3);
    // d->push(2);
    // isit();
    cout << isitt();
    // d->push(1);
    // stacks *m;
    // while (!d->empty())
    // {
    //     s->push(d->topp());
    //     d->pop();
    // }
    // print(d);
}