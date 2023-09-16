#include <bits/stdc++.h>
using namespace std;
int parent[8] = {-1, -1, 1, 1, 6, 4, -1, -1};

void dsu_set(int n)
{

    for (int i = 0; i <= n; i++)
    {
        parent[i] = -1;
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
        parent[leaderB] = leaderA;
    }
}

int main()
{
    // int leader = find(4);
    // cout << "Leader: " << leader << endl;

    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int u, v;
        cin >> u >> v;
        dsu_union(u, v);
    }

    return 0;
}