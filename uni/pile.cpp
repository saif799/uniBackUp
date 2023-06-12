#include <iostream>
using namespace std;
struct pile
{
    int data;
    pile *next;
};
bool emptyp(pile *p)
{
    if (p)
        return false;
    else
        return true;
}
void depiler(pile *&top)
{
    if (top)
    {
        pile *p = top;
        top = top->next;
        delete p;
    }
}
int topPile(pile *p)
{
    return p->data;
}
void empiler(pile *&begining, int x)
{
    pile *newpile = new pile;
    newpile->data = x;
    newpile->next = nullptr;
    if (!begining)
    {
        begining = newpile;
    }
    else
    {
        newpile->next = begining;
        begining = newpile;
    }
}
void readp(pile *beg)
{
    pile *curent = beg;
    while (curent != nullptr)
    {
        cout << curent->data << " ";
        curent = curent->next;
    }
}
void inversePile(pile *&ebg, pile *&s)
{
    pile *m = NULL;
    while (!emptyp(ebg))
    {
        empiler(s, topPile(ebg));
        empiler(m, topPile(ebg));
        depiler(ebg);
    }
    while (!emptyp(m))
    {
        empiler(ebg, topPile(m));

        depiler(m);
    }
}
int main()
{
    pile *ebg = NULL, *s = NULL;

    empiler(ebg, 3);
    empiler(ebg, 4);
    empiler(ebg, 5);
    inversePile(ebg, s);
    readp(ebg);
    cout << endl;
    readp(s);
}