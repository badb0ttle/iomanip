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
int fa[N][30],dep[N];
const int T=20;
vector<int>g[N];
//倍增求lca
void dfs(int x)
{
    dep[x]=dep[fa[x][0]]+1;
    for(int i=1;i<=T;++i)
    {
        fa[x][i]=fa[fa[x][i-1]][i-1];
    }
    for(const auto&y:g[x])
    {
        dfs(y);
    }
}
int lca(int x,int y)
{
    if(dep[x]<dep[y])swap(x,y);
    //使得dep[x]>=dep[y]
    for(int i=T;i>=0;--i)
    {
        if(dep[fa[x][i]]>=dep[y])x=fa[x][i];

    }
    if(x==y)return x;
    for(int i=T;i>=0;--i)
    {
        if(fa[x][i]!=fa[y][i])
        {
            x=fa[x][i];
            y=fa[y][i];
        }
    }
    return fa[x][0];
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 2; i <= n; ++i)
    {
        cin >> fa[i][0];
        g[fa[i][0]].pb(i);
    }
    dfs(1);
    int q;
    cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        cout << lca(x, y) << '\n';
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