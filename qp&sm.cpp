/*blank*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long // 一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
ll a, b, p;


//模板片段


ll qp(ll a, ll b, ll mod) // quick power
{
    a %= mod;
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = (res * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return res;
}
ll sm(ll a, ll b, ll mod) // slow mul
{
    a %= mod;
    ll res = 0;
    while (b)
    {
        if (b & 1)
            res = (res + a) % mod;
        b >>= 1;
        a = (a + a) % mod;
    }
    return res;
}




void work()
{
    cin >> a >> b >> p;
    cout << a << "^" << b << " mod " << p << "=" << qp(a, b, p);
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