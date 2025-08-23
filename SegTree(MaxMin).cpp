/*blank*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long // 一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
#define PII pair<int, int>
#define debug(x) cout << #x << '=' << x << '\n'
const int mx = 2e5 + 9;
const ll inf=2e18;
ll n, q, a[mx], op;//极值线段树
ll tMax[mx << 2], tMin[mx << 2], lz[mx << 2];

void update(ll s, ll e, ll o, ll x)
{
    tMax[o] += x, tMin[o] += x, lz[o] += x;
}
void pushup(ll v)
{
    tMax[v] = max(tMax[v << 1], tMax[v << 1 | 1]);
    tMin[v] = min(tMin[v << 1], tMin[v << 1 | 1]);
}
void pushdown(ll s = 1, ll e = n, ll o = 1)
{
    ll mid = (s + e) >> 1, ls = o << 1, rs = o << 1 | 1;
    update(s, mid, ls, lz[o]);
    update(mid + 1, e, rs, lz[o]);
    lz[o] = 0;
}
void build(ll s = 1, ll e = n, ll o = 1)
{
    if (s == e)
        return tMax[o] =tMin[o]= a[s], void();
    ll mid = (s + e) >> 1;
    build(s, mid, o << 1), build(mid + 1, e, o << 1 | 1);
    pushup(o);
}
void add(ll l, ll r, ll x, ll s = 1, ll e = n, ll o = 1)
{
    if (l <= s && r >= e)
        return update(s, e, o, x), void();
    pushdown(s, e, o);
    int mid = (s + e) >> 1;
    if (mid >= l)
        add(l, r, x, s, mid, o << 1);
    if (mid + 1 <= r)
        add(l, r, x, mid + 1, e, o << 1 | 1);
    pushup(o);
}
ll queryMax(ll l, ll r, ll s = 1, ll e = n, ll o = 1)
{
    if (l <= s && r >= e)
        return tMax[o];
    pushdown(s, e, o);
    ll mid = (s + e) >> 1;
    ll res = -inf;
    if (mid >= l)
        res =max(res, queryMax(l, r, s, mid, o << 1));
    if (mid + 1 <= r)
        res = max(res,queryMax(l, r, mid + 1, e, o << 1 | 1));
    return res;
}
ll queryMin(ll l, ll r, ll s = 1, ll e = n, ll o = 1)
{
    if (l <= s && r >= e)
        return tMin[o];
    pushdown(s, e, o);
    ll mid = (s + e) >> 1;
    ll res = inf;
    if (mid >= l)
        res = min(res,queryMin(l, r, s, mid, o << 1));
    if (mid + 1 <= r)
        res = min(res,queryMin(l, r, mid + 1, e, o << 1 | 1));
    return res;
}
void work()
{
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    build();

    while (q--)
    {
        cin >> op;
        if (op == 1)
        {
            ll l, r, x;
            cin >> l >> r >> x;
            add(l, r, x);
        }
        else if (op == 2)
        {
            ll l, r;
            cin >> l >> r;
            cout << queryMax(l, r)<<' '<<queryMin(l,r) << '\n';
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _ = 1;
    // cin >> _;
    // sc("%d",&_);
    while (_--)
        work();
    return 0;
}