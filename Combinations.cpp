#include<bits/stdc++.h>
using namespace std;
using i64=long long;
const int MOD = 998244353;
const int MAXN = 200000; // 按需要改大小（要 ≥ n 最大值）

i64 fac[MAXN+1], ifac[MAXN+1];

// 快速幂
i64 qpow(i64 a, i64 b) {
    i64 r = 1;
    while (b) {
        if (b & 1) r = r * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return r;
}

// 预处理 factorial 和 inverse factorial
void init(int n) {
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = fac[i-1] * i % MOD;

    ifac[n] = qpow(fac[n], MOD - 2);       // 费马小定理
    for (int i = n; i > 0; i--)
        ifac[i-1] = ifac[i] * i % MOD;
}

// C(n, k)
i64 C(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fac[n] * ifac[k] % MOD * ifac[n-k] % MOD;
}