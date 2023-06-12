#include <iostream>
using namespace std;
class node
{
public:
    int data[10];
    void enque(int key, int prio)
    {
        data[prio] = key;
    }
    void deque()
    {
        for (int i = 0; i < 9; i++)
        {
            if (data[i] != NULL)
            {
                data[i] = NULL;
                i = 10;
            }
        }
    }
    void peak()
    {
        for (int i = 0; i < 9; i++)
        {
            if (data[i] != NULL)
            {
                cout << data[i] << endl;
                i = 10;
            }
        }
    }
};
void read(node *t)
{
    for (int i = 0; i < 9; i++)
    {
        if (t->data[i] != NULL)
        {
            cout << t->data[i] << " ";
        }
    }
}
int main()
{
    node *t = new node();
    t->enque(1, 4);
    t->enque(3, 1);
    t->enque(4, 2);
    read(t);
}