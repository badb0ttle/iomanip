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
const ll N = 1e5 + 100, M = 1e6 + 10, base = 13331, mod = 1e9 + 7;
const ull INF = 1e18;
const double pie = acos(-1), eps = 1e-8;
int dir[] = {0, 1, 0, -1, 0};
const int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
const int dy[] = {1, 0, -1, -1, 0, 1, -1};
typedef pair<ll, ll> PAIR;
ll n, m, r, p;
// 加法线段树
ll lz[N << 2], t[N << 2], a[N << 2];
ll mo(ll x)
{
    return (x % p + p) % p;
}
void update(ll s, ll e, ll o, ll x)
{
    t[o] += mo((e - s + 1) * x);
    lz[o] = mo(lz[o] + x);
}
void pushdown(ll s = 1, ll e = n, ll o = 1)
{
    ll mid = (s + e) >> 1, ls = o << 1, rs = o << 1 | 1;
    update(s, mid, ls, lz[o]);
    update(mid + 1, e, rs, lz[o]);
    lz[o] = 0;
}
void pushup(int v)
{
    t[v] = mo(t[v << 1] + t[v << 1 | 1]);
}
void build(ll s = 1, ll e = n, ll o = 1)
{
    if (s == e)
        return t[o] = mo(a[s]), void();
    ll mid = (s + e) >> 1;
    build(s, mid, o << 1);
    build(mid + 1, e, o << 1 | 1);
    pushup(o);
}
void Add(ll l, ll r, ll x, ll s = 1, ll e = n, ll o = 1)
{
    if (l <= s && r >= e) // 当se区间被lr区间完全包含时更新
        return update(s, e, o, x), void();
    pushdown(s, e, o);
    ll mid = (s + e) >> 1;
    if (mid >= l)
        Add(l, r, x, s, mid, o << 1);
    if (mid+1 <= r)
        Add(l, r, x, mid + 1, e, o << 1 | 1);
    pushup(o);
}
ll query(ll l, ll r, ll s = 1, ll e = n, ll o = 1)
{
    if (l <= s && r >= e)
        return t[o];
    pushdown(s, e, o);
    ll mid = (s + e) >> 1;
    ll res = 0;
    if (mid >= l)
        res = mo(res + query(l, r, s, mid, o << 1));
    if (mid + 1 <= r)
        res = mo(res + query(l, r, mid + 1, e, o << 1 | 1));
    return res;
}
// 重链剖分求LCA
vector<int> g[N];
int fa[N], son[N], top[N], dep[N], sz[N], dfn[N];
void dfs1(int x, int pre)
{
    dep[x] = dep[pre] + 1;
    sz[x] = 1;
    fa[x] = pre;
    for (const auto &y : g[x])
    {
        if (y == pre)
            continue;
        dfs1(y, x);
        sz[x] += sz[y];
        if (sz[y] > sz[son[x]])
            son[x] = y;
    }
}
int idx = 0;
void dfs2(int x, int t)
{
    dfn[x] = ++idx;
    top[x] = t;
    // 先走重儿子
    if (son[x])
        dfs2(son[x], t);
    // 再走轻儿子
    for (const auto &y : g[x])
    {
        if (y == fa[x] || y == son[x])
            continue;
        dfs2(y, y);
    }
}
void solve()
{
    cin >> n >> m >> r >> p;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    // 树剖
    dfs1(r, 0);
    dfs2(r, r);

    for (int i = 1; i <= n; ++i)
        Add(dfn[i], dfn[i], a[i]);

    while (m--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x, y, z;//x->y的路径上+z
            cin >> x >> y >> z;
            while (top[x] != top[y])
            {
                if (dep[top[x]] < dep[top[y]])
                    swap(x, y);
                // 将这条链上top[x]->x的结点加上z
                Add(dfn[top[x]], dfn[x], z);
                x = fa[top[x]];
            }
            if (dep[x] < dep[y])
                swap(x, y);
            Add(dfn[y], dfn[x], z);
        }
        else if (op == 2)
        {
            int x, y;//求x->y路径和
            cin >> x >> y;
            ll ans = 0;
            while (top[x] != top[y])
            {
                if (dep[top[x]] < dep[top[y]])
                    swap(x, y);
                // 将这条链上top[x]->x的结点加上
                ans = mo(ans + query(dfn[top[x]], dfn[x]));
                x = fa[top[x]];
            }
            if (dep[x] < dep[y])
                swap(x, y);
            ans = mo(ans + query(dfn[y], dfn[x]));
            cout << ans << '\n';
        }
        else if (op == 3)
        {
            int x, z;//x结点的所有子节点加上z
            cin >> x >> z;
            Add(dfn[x], dfn[x] + sz[x] - 1, z);
        }
        else if (op == 4)
        {
            int x;//求x结点的所有子节点和
            cin >> x;
            cout << query(dfn[x], dfn[x] + sz[x] - 1) << '\n';
        }
    }
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