/*ordinary.exe*/
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
const int N = 5e5 + 5;
vector<int> g[N];
int dfn[N], low[N], stk[N], top, idx;
int col[N], tot, cnt[N];
bitset<N> ins;
vector<vector<int>> ans;
void tarjan(int x)
{
    dfn[x] = low[x] = ++idx;
    stk[++top] = x;
    ins[x] = 1;
    for (const auto &y : g[x])
    {
        if (!dfn[y])
        {
            tarjan(y);
            low[x] = min(low[x], low[y]);
        }
        else if (ins[y])
            low[x] = min(low[x], dfn[y]);
    }
    if (low[x] == dfn[x])
    {
        tot++;
        vector<int> tmpv;
        while (1)
        {
            int y = stk[top--];
            col[y] = tot;
            cnt[tot]++;
            ins[y] = 0;
            tmpv.push_back(y);
            if (y == x)
                break;
        }
        ans.push_back(tmpv);
    }
}
void work()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }
    for (int i = 0; i < n; ++i)
        if (!dfn[i])
            tarjan(i);
    cout<<ans.size()<<'\n';
    reverse(begin(ans),end(ans));
    for(const auto&i:ans)
    {
        cout<<i.size()<<' ';
        for(int j=0;j<i.size();++j)
        cout<<i[j]<<" \n"[j==i.size()-1];
    }
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