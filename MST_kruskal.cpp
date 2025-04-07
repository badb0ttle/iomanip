/*blank*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long // 一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
const int mx = 1e5 + 1;
ll pre[mx];
//kruskal MST
struct edge
{
    ll u, v, w;
    bool operator<(const edge &a) const
    {
        return w == a.w ? (u == a.u ? v < a.v : u < a.u) : w < a.w;
    }
};
ll root(ll v)
{
    return (pre[v] == v ? v : pre[v]=root(pre[v]));
}
vector<edge> es;
ll n, m,u,v,w;
ll ans;
void work()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        pre[i] = i;
    for(int i=1;i<=m;++i)
    {
        cin>>u>>v>>w;
        es.push_back({u,v,w});
    }
    sort(begin(es),end(es));
    for(auto&[u1,v1,w]:es)
    {
        if(root(u1)==root(v1))continue;
            pre[root(u1)]=root(v1);
            ans+=w;
    }
    for(int i=1;i<n;++i)
    {
        if(root(i)!=root(i+1)){ans=-1;break;}
    }
    cout<<ans<<'\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _ = 1;
    // cin >> _;
    // sc("%d",&_);
    while (_--)
        work();
    return 0;
}