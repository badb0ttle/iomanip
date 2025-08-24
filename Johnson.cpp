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
const ll N = 3e3 + 100, M = 1e6 + 10, base = 13331, mod = 1e9 + 7;
const ull INF = 1e18;
const double pie = acos(-1), eps = 1e-8;
int dir[] = {0, 1, 0, -1, 0};
const int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
const int dy[] = {1, 0, -1, -1, 0, 1, -1};
typedef pair<ll, ll> PAIR;
//Johnson单源最短路
struct Edge
{
    ll x, w;
    bool operator<(const Edge &u) const
    {
        return w == u.w ? x < u.x : w > u.w;
    }
};
ll h[N], d[N][N], n, m;
vector<Edge> g[N];
bool spfa(int st)
{
    for (int i = 1; i <= n; ++i)
        h[i] = INF;
    h[st] = 0;
    bitset<N> inq;
    queue<int> q;
    vector<int> cnt(n + 1);
    q.push(st);
    inq[st] = 1;
    while (SZ(q))
    {
        int x = q.front();
        q.pop();
        inq[x] = 0;
        for (const auto &[y, w] : g[x])
        {
            if (h[x] + w < h[y])
            {
                if (++cnt[y] > n)
                    return 1;
                h[y] = h[x] + w;
                if (!inq[y])
                    q.push(y), inq[y] = 1;
            }
        }
    }
    return 0;
}
void dijkstra(int st, ll d[])
{
    for (int i = 1; i <= n; ++i)
        d[i] = INF;
    priority_queue<Edge> pq;
    bitset<N> vis;
    pq.push({st, d[st] = 0});
    while (SZ(pq))
    {
        int x = pq.top().x;
        pq.pop();
        if (vis[x])
            continue;
        vis[x] = 1;
        for (const auto &[y, w] : g[x])
        {
            if (d[x] + w < d[y])
            {
                d[y] = d[x] + w;
                pq.push({y, d[y]});
            }
        }
    }
    // 还原结果
    for (int i = 1; i <= n; ++i)
        d[i] = d[i] - h[st] + h[i];
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        g[u].pb({v, w});
    }
    // 1.建立虚拟源点
    for (int i = 1; i <= n; ++i)
        g[0].pb({i, 0}), h[i] = INF;
    // 2.Bellman-Ford算法求0点到所有点的单源最短路
    if (spfa(0))
    {
        cout << "-1\n";
        return;
    }
    // 3.改造所有边
    for (int x = 1; x <= n; ++x)
        for (auto &[y, w] : g[x])
            w = w + h[x] - h[y];
    // 4.对每个点Dijkstra
    for (int i = 1; i <= n; ++i)
        dijkstra(i, d[i]);
    for (int x = 1; x <= n; ++x)
    {
        for (int y = 1; y <= n; ++y)
        {
            if (y != 1)
                cout << ' ';
            if (d[x][y] >= INF / 2)
                cout << "-1";
            else
                cout << d[x][y];
        }
        cout << "\n";
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