#include<bits/stdc++.h>
using namespace std;

#define int         long long
#define test        int t; cin>>t; while(t--)
#define ll          long long
#define pb          push_back
#define pob         pop_back
#define forc(i, n)  for(int i=0; i<n; i++)
#define yes         cout<<"YES\n"
#define no          cout<<"NO\n"
#define all(n)      n.begin(),n.end()
#define rll(n)      n.rbegin(),n.rend()
#define sz          size()
#define vi          vector<int>
#define vl          vector<ll>
#define vc          vector<char>
#define vs          vector<string>
#define mp          map<int, int>
#define ff          first
#define ss          second
#define endl        "\n"
#define mem(a)      memset(a, -1, sizeof(a))
#define setbit(a)   __builtin_popcount(a)

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

int32_t main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int, int>>> graph(n+5);
    forc(i, m)
    {
        int x,y,wt;
        cin>>x>>y>>wt;
        graph[x].push_back({y, wt});
    }
    dijkstra(n, graph);
}
