#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 qp(i64 a, i64 b, i64 mod) {
    i64 res = 1;
    a %= mod;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
// exgcd
i64 exgcd(i64 a, i64 b, i64 &x, i64 &y) {
    if (!b) return x = 1, y = 0, a;
    i64 d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
// 逆元（mod 不一定是质数）
i64 inv(i64 a, i64 mod) {
    i64 x, y;
    exgcd(a, mod, x, y);
    return (x % mod + mod) % mod;
}
// 计算 n! 去掉 p 因子的部分
i64 fac(i64 n, i64 p, i64 pk) {
    if (!n) return 1;
    i64 res = 1;
    for (i64 i = 1; i <= pk; i++)
        if (i % p) res = res * i % pk;
    res = qp(res, n / pk, pk);
    for (i64 i = 1; i <= n % pk; i++)
        if (i % p) res = res * i % pk;
    return res * fac(n / p, p, pk) % pk;
}
// 计算 C(n,k) mod p^k
i64 C(i64 n, i64 m, i64 p, i64 pk) {
    if (n < m) return 0;
    i64 a = fac(n, p, pk);
    i64 b = fac(m, p, pk);
    i64 c = fac(n - m, p, pk);
    i64 cnt = 0;
    for (i64 i = n; i; i /= p) cnt += i / p;
    for (i64 i = m; i; i /= p) cnt -= i / p;
    for (i64 i = n - m; i; i /= p) cnt -= i / p;
    return a * inv(b, pk) % pk * inv(c, pk) % pk * qp(p, cnt, pk) % pk;
}
// CRT 合并
i64 CRT(vector<i64> &r, vector<i64> &m) {
    i64 M = 1, ans = 0;
    int n = r.size();
    for (int i = 0; i < n; i++) M *= m[i];
    for (int i = 0; i < n; i++) {
        i64 Mi = M / m[i];
        i64 x, y;
        exgcd(Mi, m[i], x, y);
        ans = (ans + r[i] * Mi % M * x % M) % M;
    }
    return (ans % M + M) % M;
}
// exLucas
i64 exLucas(i64 n, i64 m, i64 mod) {
    vector<i64> r, p;
    for (i64 i = 2; i * i <= mod; i++) {
        if (mod % i == 0) {
            i64 pk = 1;
            while (mod % i == 0) {
                mod /= i;
                pk *= i;
            }
            r.push_back(C(n, m, i, pk));
            p.push_back(pk);
        }
    }
    if (mod > 1) {
        r.push_back(C(n, m, mod, mod));
        p.push_back(mod);
    }
    return CRT(r, p);
}
void work() {
    i64 n, m, mod;
    cin >> n >> m >> mod;
    cout << exLucas(n, m, mod) << '\n';
}
int main() {
ios::sync_with_stdio(0);
cin.tie(0);
int t=1;
// cin >> t;
while(t--)
work();
}
