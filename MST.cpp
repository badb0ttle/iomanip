/*blank*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long // 一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
const int N = 1e5 + 9;
const ll inf = 2e18;

struct Edge
{
    ll x, y, w;
};
vector<Edge> es;
int pre[N], n, m;
int root(int x) { return pre[x] = (pre[x] == x ? x : root(pre[x])); }

void work()
{
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        ll x, y, w;
        cin >> x >> y >> w;
        es.push_back({x, y, w});
    }
    for (int i = 1; i <= n; ++i)
        pre[i] = i;

    sort(es.begin(), es.end(), [](const Edge &u, const Edge &v)
         {
   	if(u.w != v.w)return u.w < v.w;
   	return u.x < v.x; });
    ll ans = 0;
    for (const auto &t : es)
    {
        ll x = t.x, y = t.y, w = t.w;
        int rx = root(x), ry = root(y);
        if (rx != ry)
        {
            // 选中了这条边
            ans += w;
            pre[rx] = ry;
        }
    }
    for (int i = 2; i <= n; ++i)
    {
        if (root(i) != root(1))
        {
            cout << -1 << '\n';
            return;
        }
    }
    cout << ans << '\n';
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