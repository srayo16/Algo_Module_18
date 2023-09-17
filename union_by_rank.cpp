#include <bits/stdc++.h>
using namespace std;
int parent[1000];
int parentLevel[1000];

void dsu_set(int n)
{

    for (int i = 0; i <= n; i++)
    {
        parent[i] = -1;
        parentLevel[i] = 0;
    }
}

int dsu_find(int n)
{

    while (parent[n] != -1)
    {
        n = parent[n];
    }
    return n;
}

void dsu_union(int a, int b)
{

    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);

    if (leaderA != leaderB)
    {
        if (parentLevel[leaderA] > parentLevel[leaderB])
        {
            parent[leaderB] = leaderA;
        }
        else if (parentLevel[leaderA] < parentLevel[leaderB])
        {
            parent[leaderA] = leaderB;
        }
        else
        {
            parent[leaderB] = leaderA;
            parentLevel[leaderA]++;
        }
    }
}

int main()
{

    int n, e;
    cin >> n >> e;
    dsu_set(n);
    while (e--)
    {
        int u, v;
        cin >> u >> v;
        dsu_union(u, v);
    }

    cout << dsu_find(3);

    return 0;
}