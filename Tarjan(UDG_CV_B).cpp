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
const int T = 20;
const ull INF = 1e18;
const double pie = acos(-1), eps = 1e-8;
int dir[] = {0, 1, 0, -1, 0};
const int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
const int dy[] = {1, 0, -1, -1, 0, 1, -1};
typedef pair<int, int> PAIR;
// Tarjan求割点
vector<int> g[N];
int dfn[N], low[N], cut, es, idx;
//割点
void tarjan1(int x, int fa)
{
    dfn[x] = low[x] = ++idx;
    int child = 0;
    for (const auto &y : g[x])
    {
        // 1.不走父亲
        if (y == fa)
            continue;
        // 2.判断是否是搜索树的儿子
        if (!dfn[y])
        {
            tarjan1(y, x);
            low[x] = min(low[x], low[y]);
            child += (low[y] >= dfn[x]);
        }
        else
        {
            low[x] = min(low[x], dfn[y]);
        }
    }
    if ((!fa == 0 && child >= 2) || fa && child >= 1)
        cut++;
}
//割边
void tarjan2(int x, int fa)
{
    dfn[x] = low[x] = ++idx;
    for (const auto &y : g[x])
    {
        // 1.不走父亲
        if (y == fa)
            continue;
        // 2.判断是否是搜索树的儿子
        if (!dfn[y])
        {
            tarjan2(y, x);
            low[x] = min(low[x], low[y]);
            //如果y回不到自身以及父亲树上
            if(low[y]>dfn[x])es++;
        }
        else
        {
            low[x] = min(low[x], dfn[y]);
        }
    }
}
set<PAIR> st;
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
        st.insert({x, y}), st.insert({y, x});
    }
    for (int i = 1; i <= n; ++i)
        if (!dfn[i])
            tarjan1(i, 0);
    for (int i = 1; i <= n; ++i)
        dfn[i] = low[i] = 0;
    idx = 0;
    for(int i=1;i<=n;++i)if(!dfn[i])tarjan2(i,0);
    cout << cut << ' ' << es << '\n';
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