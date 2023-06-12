#include <iostream>
#include <vector>
using namespace std;
struct page
{
    int in = 0;
    int frame;
    int loadtime;
};
struct frame
{
    int valide = 0;
    int page;
};
vector<page> TP(20);
vector<frame> MC(4);
void insert(int page)
{
    for (int i = 0; i < sizeof(MC); i++)
    {
        if (MC[i].valide == 0)
        {
            MC[i].valide = 1;
            MC[i].page = page;
            TP[page].frame = i;
            cout << "you entered page " << page << " in the frame : " << i << endl;
            return;
        }
    }
}
void removeAndInsert(int page)
{
    for (int i = 0; i < sizeof(MC) - 1; i++)
    {
        MC[i].page = MC[i + 1].page;
    }
    MC[3].page = page;
    TP[page].in = 1;
    TP[page].frame = 3;
    cout << "MC : " << MC[0].page << " || " << MC[1].page << " || " << MC[2].page << " || " << MC[3].page << endl;
}
int main()
{
    int NPO = 0;
    vector<int> listRef = {3, 5, 6, 8, 3, 9, 6, 12, 3, 6, 10};
    for (int i = 0; i < sizeof(listRef); i++)
    {
        if (TP[listRef[i]].in == 1)
            continue;
        if (NPO < 4)
        {
            insert(listRef[i]);
            NPO++;
            continue;
        }
        removeAndInsert(listRef[i]);
    }
}
