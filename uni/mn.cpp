#include <iostream>
using namespace std;
int main()
{
    int m[2][2] = {1, 2, 3, 4};
    int h[2][2] = {1, 2, 3, 4};
    int d[2][2], s;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int a = 0; a < 2; a++)
            {
                s = m[i][a] + h[a][j] + s;
            }
            d[i][j] = s;
            s = 0;
        }
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << d[i][j] << "||";
        }
    }
}
