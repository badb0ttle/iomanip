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
struct Edge
{
    ll x, w;
};
vector<Edge> g[N];
ll d[N], n, m;
// 判断是否存在负环
bool spfa(int st)
{
    // 1.初始化
    for (int i = 1; i <= n; ++i)
        d[i] = INF;
    d[st] = 0;
    queue<int> q;
    bitset<N> inq;
    q.push(st);
    inq[st]=1;
    vector<int> cnt(n + 1);
    // 2.只要队列不为空则一直跑
    while (q.size())
    {
        // 取出队头作为松弛的起点
        int x = q.front();
        q.pop();
        inq[x] = 0;
        // 枚举所有出点
        for (auto [y, w] : g[x])
        {
            // 判断是否能够松弛
            if (d[y] > d[x] + w)
            {
                  // 判断是否有负环
                if(++cnt[y] > n)return 1;
                d[y] = d[x] + w;
                if (!inq[y])
                {
                    q.push(y);
                    inq[y] = 1;
                }
            }
        }
    }
    // 没有负环
    return 0;
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
    // 1.初始化
    for (int i = 2; i <= n; i++)
        d[i] = INF;
    // 2.进行n轮松弛，判断第n轮是否进行了松弛操作
    if (spfa(1))
        cout << "-1\n";
    else
    {
        for (int i = 1; i <= n; i++)
            cout << d[i] << " ";
        cout << '\n';
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