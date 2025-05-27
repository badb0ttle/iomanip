/*blank*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long // 一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
// prim LST
const int mx = 2e5 + 1;
const ll inf = 4e18;
struct edge
{
    ll v, w;
    bool operator<(const edge &a) const
    {
        return w == a.w ? v < a.v : w > a.w;
    }
};
vector<edge> es[mx];
ll n,m;
ll d[mx],u,v,w;
bitset<mx> intree;
void work()
{
    cin>>n>>m;
    fill(begin(d),end(d),inf);
    for(int i=1;i<=m;++i)
    {
        cin>>u>>v>>w;
        es[u].push_back({v,w});
        es[v].push_back({u,w});
    }
    priority_queue<edge>pq;
    pq.push({1,0});
    d[1]=0;
    ll ans=0;
    while(pq.size())
    {
        int x=pq.top().v;
        pq.pop();
        if(intree[x])continue;
        intree[x]=1;
        ans+=d[x];
        d[x]=0;
        for(auto&[y,w]:es[x])
        {
            if(!intree[y]&&d[y]>w)
            {
                d[y]=w; 
                pq.push({y,w});
            }
        }
    }
    for(int i=1;i<=n;++i)if(!intree[i]){ans=-1;break;}
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