/*blank*/
#include <bits/stdc++.h>

using i64 = long long;
const int N = 2e5 + 9;
i64 fac[N], inv[N];  
i64 ksm(i64 a, i64 b, i64 p) {
    i64 ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return ans;
}
// 求逆元：费马小定理 a^(p-2) ≡ a^(-1) mod p
i64 ginv(i64 x, i64 p) {
    return ksm(x, p - 2, p);
}

// 组合数 C(n, m) mod p，要求 fac 和 inv 预处理好
i64 C(i64 n, i64 m, i64 p) {
    if (n < 0 || m < 0 || n < m) return 0;
    return fac[n] * inv[m] % p * inv[n - m] % p;
}

// Lucas 定理：解决 n, m 很大，但 p 较小的组合数取模问题
i64 lucas(i64 n, i64 m, i64 p) {
    if (!m) return 1;
    return lucas(n / p, m / p, p) * C(n % p, m % p, p) % p;
}
void work()
{
i64 n, m, p; 
    std::cin >> n >> m >> p;

    // 预处理阶乘和阶乘逆元
    fac[0] = 1;
    for (int i = 1; i < p; i++) fac[i] = fac[i - 1] * i % p;
    inv[p - 1] = ginv(fac[p - 1], p);
    for (int i = p - 2; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % p;

    // 输出 C(n + m, n) mod p
    std::cout << lucas(n + m, n, p) << "\n";
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int _=1;
    //std::cin>>_;
    while(_--)work();
    return 0;
}