/*ordinary.exe*/
#include <bits/stdc++.h>
using namespace std;
using i64=long long;
using u64=unsigned long long;
const int mx=2e5+1;
const i64 inf=4e18;
struct edge{
i64 v,w;
bool operator <(const edge&a)const{
    return w==a.w?v<a.v:w>a.w;
}
};
vector<edge>g[mx];
i64 dp[mx];
void dijkstra(int st)
{
    bitset<mx>vis;
    fill(begin(dp),end(dp),inf);
    priority_queue<edge>qp;
    dp[st]=0;
    qp.push({st,0});
    while(qp.size())
    {
        i64 x=qp.top().v;
        qp.pop();
        if(vis[x])continue;
        vis[x]=1;
        for(auto&[v,w]:g[x])
        {
            if(!vis[v]&&dp[v]>dp[x]+w)dp[v]=dp[x]+w;
            qp.push({v,dp[v]});
        }
    }
}
void work()
{
    int n,m,s,t;cin>>n>>m>>s>>t;
    for(int i=1;i<=m;++i)
    {
        int u,v,w;cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    dijkstra(s);
    cout<<dp[t]<<'\n';
}
int main() {
ios::sync_with_stdio(0);
cin.tie(0);
int t=1;
// cin >> t;
while(t--)
work();
}