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
ll n, s, w, v, m;
ll dp[N];
void solve()
{
    for (int i = 1; i <= n; ++i)
    {
        cin >> s >> w >> v;
        vector<int> vec;
        int x = 1;
        while (s >= x)
        {
            vec.push_back(x);
            s -= x;
            x <<= 1;
        }
        if (s)
            vec.push_back(s);
        for (int k : vec)
        {
            for (int j = m; j >= k * v; --j)
                dp[j] = max(dp[j], dp[j - k * v] + k * w);
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