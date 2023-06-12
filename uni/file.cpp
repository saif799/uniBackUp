#include <iostream>
using namespace std;
struct file
{
    int data;
    file *next;
};
void defiler(file *&top)
{
    if (top)
    {
        file *f = top;
        top = top->next;
        delete f;
    }
}
int topfile(file *p)
{
    return p->data;
}
void enfiler(file *&begining, file *&end, int x)
{
    file *newfile = new file;
    newfile->data = x;
    newfile->next = nullptr;
    if (!begining)
    {
        begining = newfile;
        end = newfile;
    }
    else
    {
        end->next = newfile;
        end = newfile;
    }
}
void read(file *beg, file *end)
{
    file *curent = beg;
    while (curent != nullptr)
    {
        cout << curent->data << " ";
        curent = curent->next;
    }
}
struct pile
{
    int data;
    pile *next;
};
int topPile(pile *p)
{
    return p->data;
}
void empiler(pile *&begining, pile *&end, int x)
{
    pile *newpile = new pile;
    newpile->data = x;
    newpile->next = nullptr;
    if (!begining)
    {
        begining = newpile;
        end = newpile;
    }
    else
    {
        newpile->next = begining;
        begining = newpile;
    }
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
bool emptyp(pile *p)
{
    if (p)
        return false;
    else
        return true;
}
bool emptyf(file *p)
{
    if (p)
        return false;
    else
        return true;
}
void inversefile(file *&f, file *&end, file *&a, file *&endd)
{
    pile *p = new pile, *k;
    file *e = nullptr, *q = nullptr;
    while (!emptyf(f))
    {
        empiler(p, k, topfile(f));
        enfiler(e, q, topfile(f));
        defiler(f);
    }
    while (!emptyp(p))
    {
        enfiler(a, endd, topPile(p));
        enfiler(f, end, topfile(e));
        defiler(e);
        depiler(p);
    }
}
int main()
{
    file *ebg = NULL, *end = NULL, *s = NULL, *h = nullptr;
    enfiler(ebg, end, 3);
    enfiler(ebg, end, 4);
    enfiler(ebg, end, 5);
    // inversefile(ebg, end, s, h);
    pile *p = nullptr, *k = nullptr;
    file *e = nullptr, *q = nullptr;
    while (!emptyf(ebg))
    {
        empiler(p, k, topfile(ebg));
        enfiler(e, q, topfile(ebg));
        defiler(ebg);
    }
    while (!emptyp(p))
    {
        enfiler(s, h, topPile(p));
        enfiler(ebg, end, topfile(e));
        defiler(e);
        depiler(p);
    }
    read(ebg, end);
    cout << endl;
    read(s, end);
}