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
int col[N];
vector<int> g[N];
bool dfs(int x)
{
    for(const auto &y:g[x])
    {
        if(col[y]==-1)
        {
            col[y]=col[x]^1;
            if(!dfs(y))return 0;
        }
        else if(col[y]==col[x])return 0;
    }
    return 1;
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
        g[y].pb(x);
    }
    for (int i = 1; i <= n; ++i)
        col[i] = -1;
    bool ans = 1;
    for(int i=1;i<=n;++i)
    {
        if(col[i]==-1)
        {
            col[i]=0;
            ans&=dfs(i);
        }
    }
    cout << (ans ? "YES" : "NO") << '\n';
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