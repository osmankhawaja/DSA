#include<bits/stdc++.h>
using namespace std;

const int N=1e5;
vector<int>graph[N];
bool visited[N];

//time complexity:O(v+e) vertex+edges

void bfs(int source)
{
    queue<int>q;
    q.push(source);
    visited[source]=true;
    while(!q.empty())
    {
        int cur_vertex=q.front();
        cout<<cur_vertex<<" ";
        q.pop();
        for(auto child : graph[cur_vertex])
        {
            if(!visited[child])
            {
                q.push(child);
                visited[child]=true;
            }
        }
    }
}
int main()
{
    int v,e;
    cin>>v;//vertex
    for(int i=0; i<v-1; i++)//edges
    {
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    bfs(1);
    return 0;
}
