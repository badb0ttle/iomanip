/*ordinary.exe*/
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
const int N = 2e5 + 5;
vector<int> g[N];
int dfn[N], low[N], cut, idx;
vector<int> ans;
void tarjan(int x, int fa)
{
    dfn[x] = low[x] = ++idx;
    int chi = 0;
    bool f = 0;
    for (const auto &y : g[x])
    {
        if (y == fa)
            continue;
        if (!dfn[y])
        {
            chi++;
            tarjan(y, x);
            low[x] = min(low[x], low[y]);
            if (low[y] >= dfn[x] && fa != 0)
                f = 1;
        }
        else
            low[x] = min(low[x], dfn[y]);
    }
    if ((fa == 0 && chi >= 2) || (fa != 0 && f))
    {
        ans.push_back(x);
        cut++;
    }
}
set<pair<int, int>> st;
void work()
{
    cut = 0, idx = 0;
    ans.clear();
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        g[i].clear();
        dfn[i] = low[i] = 0;
    }
    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i)
        if (!dfn[i])
            tarjan(i, 0);
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << " \n"[i == ans.size() - 1];
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