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
int n, m;
ll t, T[N], W[N], dp[N];
void solve()
{
    cin >> n >> m >> t;
    for (int i = 1; i <= n; ++i)
        cin >> T[i] >> W[i];
    for (int i = 1; i <= m; ++i)
    {
        for (int j = t; j >= T[i]; --j)
        {
            if (j >= T[i])
                dp[j] = max(dp[j - T[i]] + W[i], dp[j]);
            else
                dp[j] = dp[j];
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