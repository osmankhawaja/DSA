#include<bits/stdc++.h>
using namespace std;
int const INF=1e16;

void dijkstra(int n, vector<vector<pair<int, int>>> &graph)
{
    vector<int>dis(n+5, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dis[1]=0;
    pq.push({0, 1});
    while(!pq.empty())
    {
        int cur_node=pq.top().second;
        int cur_node_dis=pq.top().first;
        pq.pop();

        if(dis[cur_node] < cur_node_dis)
         continue;

        for(auto &i:graph[cur_node])
        {
            int child_node=i.first;
            int child_node_dis=i.second;
            if(dis[cur_node] + child_node_dis < dis[child_node])
            {
                dis[child_node]=dis[cur_node] + child_node_dis;
                pq.push({dis[child_node], child_node});
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        cout<<dis[i]<<" ";
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int, int>>> graph(n+5);
    for(int i=0; i<m; i++)
    {
        int x,y,wt;
        cin>>x>>y>>wt;
        graph[x].push_back({y, wt});
    }
    dijkstra(n, graph);
}
