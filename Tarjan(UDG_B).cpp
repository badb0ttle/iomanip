/*ordinary.exe*/
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
const int N = 5e5 + 5;
vector<pair<int,int>> g[N];
int dfn[N], low[N], es, idx;
vector<int> ans;
bool f[N];
struct edge {
    int u, v;
};
vector<edge>side;
void tarjan(int x, int fa)
{
    dfn[x] = low[x] = ++idx;
    for (const auto &y : g[x])
    {
        int v=y.first,id=y.second;
        if (id == fa)
            continue;
        if (!dfn[v])
        {
            tarjan(v,id);
            low[x] = min(low[x], low[v]);
            if(low[v]>dfn[x]){es++;f[id]=1;}
        }
        else
            low[x] = min(low[x], dfn[v]);
    }
}
void work()
{
    es = 0, idx = 0;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        g[i].clear();
        dfn[i] = low[i] = 0;
    }
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        side.push_back({x,y});
        g[x].push_back({y,i});
        g[y].push_back({x,i});
        f[i]=0;
    }
   idx = 0;
    for(int i=1;i<=n;++i)if(!dfn[i])tarjan(i,-1);
    for (int i = 0; i < m; ++i)
        if (f[i])
            cout << side[i].u << ' ' << side[i].v << '\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        work();
}