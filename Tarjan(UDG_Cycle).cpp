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
// Tarjan求环
vector<int> g[N];
int dfn[N], low[N], stk[N], idx, ans, top;
bitset<N> ins;
void tarjan(int x, int fa)
{
    dfn[x] = low[x] = ++idx;
    stk[++top] = x;
    ins[x] = 1;
    for (const auto &y : g[x])
    {
        if (y == fa)
            continue;
        if (!dfn[y])
        {
            tarjan(y, x);
            low[x] = min(low[x], low[y]);
        }
        else if (ins[y])
        {
            low[x] = min(low[x], dfn[y]);
        }
    }
    if (low[x] == dfn[x])
    {
        int cnt = 0;
        while (stk[top + 1] != x)
        {
            cnt++;
            ins[stk[top--]] = 0;
        }
        if (cnt > 1)
        {
            ans = cnt;
            return;
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        g[i].clear();
        stk[i] = dfn[i] = low[i] = 0;
        ins[i] = 0;
    }
    stk[n + 1] = 0;
    ans = idx = top = 0;
    for (int i = 1; i <= n; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    tarjan(1, 0);
    cout << ans << '\n';
}
signed main()
{
    io;
    ll _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}