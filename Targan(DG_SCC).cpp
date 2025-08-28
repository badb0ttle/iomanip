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
typedef pair<ll, ll> PAIR;
// Tarjan有向图缩点
vector<int> g[N];
int dfn[N], low[N], stk[N], top, idx;
int col[N], tot, cnt[N];
bitset<N> ins;
void tarjan(int x)
{
    // 1.初始化dfn和low
    dfn[x] = low[x] = ++idx;
    // 2.入栈并标记
    stk[++top] = x;
    ins[x] = 1;
    // 3.遍历所有儿子
    for (const auto &y : g[x])
    {
        // 判断是否是回点
        if (!dfn[y])
        {
            tarjan(y);
            low[x] = min(low[x], low[y]);
        }
        else if (ins[y])
        {
            low[x] = min(low[x], dfn[y]);
        }
    }
    // 4.收拢
    if (low[x] == dfn[x])
    {
        // 新开一个颜色
        tot++;
        while (stk[top + 1] != x)
        {
            // 染色
            col[stk[top]] = tot;
            cnt[tot]++;
            // 取消标记
            ins[stk[top--]] = 0;
        }
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
    }
    for (int i = 1; i <= n; ++i)
        if (!dfn[i])
            tarjan(i);
    vector<int>v;
    for(int i=1;i<=n;++i)if(cnt[i]>1)v.pb(cnt[i]);
    if(SZ(v))
    {
        sort(all(v));
        for(const auto&i:v)cout<<i<<' ';
        cout<<'\n';
    }
    else cout<<"-1\n";
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