/*ordinary.exe*/
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 2e5 + 5;
i64 n, m,w,v,u,ans,pre[N];
struct edge
{
    i64 u, v, w;
    bool operator<(const edge &a) const
    {
        return w == a.w ? (u == a.u ? v < a.v : u < a.u) : w < a.w;
    }
};
i64 root(i64 v) { return pre[v] == v ? v : pre[v] = root(pre[v]); }
vector<edge>es;
void work()
{
    cin >> n >> m;
    for(int i=1;i<=n;++i)pre[i]=i;
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
    for(int i=1;i<n;++i)if(root(i)!=root(i+1))return void(cout<<"-1\n");
    cout<<ans<<'\n';
    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    // cin >> t;
    while (t--)
        work();
}