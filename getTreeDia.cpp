/*ordinary.exe*/
#include<bits/stdc++.h>
using namespace std;
using i64=long long ;
using u64=unsigned long long ;
const int N=1e5+1;
int n,dis[N];
struct edge{
    int u,w;
};
vector<edge>g[N];
void dfs(int u,int fa,int w)
{
    dis[u]=w;
    for(auto i:g[u])
        if(i.u!=fa)dfs(i.u,u,dis[u]+i.w);
} 
void work()
{
    int n,m;cin>>n>>m;
    for(int i=1;i<=m;++i)
    {
        int v,u,w;cin>>u>>v>>w;
        char c;cin>>c;
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,w);
    }
    dfs(1,-1,0);
    int ans=1;
    for(int i=1;i<=n;++i)if(dis[i]>dis[ans])ans=i;
    dfs(ans,-1,0);
    for(int i=1;i<=n;++i)if(dis[i]>dis[ans])ans=i;
    i64 res=dis[ans];
    ans=ans*10+(ans*(ans+1)>>1);
    cout<<res<<'\n';
}
int main() {
ios::sync_with_stdio(0);
cin.tie(0);
int t=1;
// cin >> t;
while(t--)
work();
}