/*🫵😉👍*/
#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <stack>
#include <math.h>
#include <stdlib.h>
#include <queue>
#include <set>
#include <string.h>
#include <string>
#include <stdio.h>
#include <deque>
#include <numeric>
using namespace std;
#define ll long long
#define lll __uint128_t
#define ld long double
#define ull unsigned long long
#define re register
#define il inline
#define fi first
#define SZ(x) ((int)(x).size())
#define se second
#define all(v) v.begin(), v.end()
#define pb push_back
#define lowbit(x) (x & -x)
#define fixed(x) fixed << setprecision(x)
#define lcm(x, y) x *y / __gcd(x, y)
#define endl "\n"
#define debug(x) cout << #x << " = " << (x) << endl;
#define io ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
const ll N = 2e5 + 100, M = 1e6 + 10, base = 13331, mod = 1e9 + 7;
const ull INF = 1e18;
const double pie = acos(-1), eps = 1e-8;
int dir[] = {0, 1, 0, -1, 0};
const int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
const int dy[] = {1, 0, -1, -1, 0, 1, -1};
typedef pair<int, int> PAIR;
int fa[N], dep[N];
const int T = 20;
vector<int> g[N];
// Tarjan求lca
int pre[N], ans[N];
int root(int x) { return pre[x] = (pre[x] == x ? x : root(pre[x])); }
vector<PAIR> Q[N];
bitset<N> vis;
void merge(int x, int y)
{
    // 深度大到深度小
    int fx = root(x), fy = root(y);
    if (dep[fx] < dep[fy])
        swap(fx, fy);
    pre[fx] = fy;
}
void dfs(int x)
{
    dep[x] = dep[fa[x]] + 1;
    vis[x] = 1;
    // 1.处理儿子
    for (const auto &y : g[x])
        dfs(y);
    // 2.处理自己的询问
    for (const auto &[y, i] : Q[x])
    {
        if (!vis[y])
            continue;
        ans[i] = root(y);
    }
    merge(x, fa[x]);
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        pre[i] = i;
    for (int i = 2; i <= n; ++i)
    {
        cin >> fa[i];
        g[fa[i]].pb(i);
    }
    int q;
    cin >> q;
    for (int i = 1; i <= q; ++i)
    {
        int x, y;
        cin >> x >> y;
        Q[x].pb({y, i});
        Q[y].pb({x, i});
    }
    dfs(1);
    for (int i = 1; i <= q; ++i)
        cout << ans[i] << '\n';
}
signed main()
{
    io;
    ll _ = 1;
    // cin >> _;
    while (_--)
        solve();
    return 0;
}