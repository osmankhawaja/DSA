#include<bits/stdc++.h>
using namespace std;

const int N=1e5;
vector<int>graph[N];
bool visited[N];

//time complexity:O(V+E) vertex+edges

void dfs(int vertex)
{
    visited[vertex]=true;
    cout<<vertex<<" ";
    for(auto child : graph[vertex])
    {
        if(visited[child])
          continue;
          dfs(child);
    }
}
int main()
{
    int v,e;
    cin>>v>>e;//vertex && edge
    for(int i=0; i<e; i++)//edges
    {
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs(1);
    return 0;
}
