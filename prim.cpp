#include <iostream>
#include <chrono>
#include <vector>
#include <list>
//#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
struct tedge
{
    int weight;
    int u, v;
};
int const n = 5;
int main()
{
    auto start = high_resolution_clock::now();
    vector<vector<int>> graph{{0, 2, 0, 6, 0}, {2, 0, 3, 8, 5}, {0, 3, 0, 0, 7}, {6, 8, 0, 0, 9}, {0, 5, 7, 9, 0}};
    vector<bool> color(n, 0);
    list<tedge> MST;
    list<int> s;
    vector<list<int>> adjlist(n);
    for (auto i = 0; i < n; i++)
    {
        for (auto j = 0; j < n; j++)
        {
            if (graph[i][j])
            {
                adjlist[i].push_back(j);
                adjlist[j].push_back(i);
            }
        }
    }
    s.push_back(0);
    color[0] = 1;
    while (s.size() != n)
    {
        int minweight = INT_MAX;
        tedge bestedge;
        for (auto v1 : s)

            for (auto v2 : adjlist[v1])

                if (!color[v2] && graph[v1][v2] < minweight)
                {
                    minweight = graph[v1][v2];
                    bestedge.u = v1;
                    bestedge.v = v2;
                    bestedge.weight = minweight;
                }
        s.push_back(bestedge.v);
        color[bestedge.v] = 1;
        MST.push_back(bestedge);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << duration.count() << endl;
    cout << "edge \tweight\n";
    for (auto edge : MST)
        cout << edge.u << " - " << edge.v << "\t" << edge.weight << "\n";
    return 0;
}
