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
typedef pair<ll, ll> PAIR;
//树上dp+启发式合并的完美体现
int sz[N], son[N], cnt[N], c[N];
int ans;
vector<int> g[N];
multiset<int> st;
void AddNode(int x)
{
    if (cnt[c[x]])
        st.erase(st.find(cnt[c[x]]));
    if (++cnt[c[x]] != 0)
        st.insert(cnt[c[x]]);
}
void DelNode(int x)
{
    st.erase(st.find(cnt[c[x]]));
    if (--cnt[c[x]] != 0)
        st.insert(cnt[c[x]]);
}
void AddTree(int x)
{
    AddNode(x);
    for (const auto &y : g[x])
        AddTree(y);
}
void DelTree(int x)
{
    DelNode(x);
    for (const auto &y : g[x])
        DelTree(y);
}
void dfs1(int x)
{
    sz[x] = 1;
    for (const auto &y : g[x])
    {
        dfs1(y);
        sz[x] += sz[y];
        if (sz[y] > sz[son[x]])
            son[x] = y;
    }
}
void dfs(int x)
{
    for (const auto &y : g[x])
    {
        if (y == son[x])
            continue;
        dfs(y);
        DelTree(y);
    }
    if (son[x])
        dfs(son[x]);
    for (const auto &y : g[x])
    {
        if (y == son[x])
            continue;
        AddTree(y);
    }
    AddNode(x);
    if (SZ(st) && *st.begin() == *st.rbegin())
        ans++;
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int fa;
        cin >> c[i] >> fa;
        g[fa].pb(i);
    }
    dfs1(1);
    dfs(1);
    cout << ans << '\n';
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