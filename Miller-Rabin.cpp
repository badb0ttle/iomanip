#include <iostream>
#include <ctime>
using namespace std;
using i128 = __int128;

// 快速幂 (a^b mod n)
i128 qpow(i128 a, i128 b, i128 mod) {
    i128 res = 1;
    a %= mod;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

// Miller-Rabin 素性测试
bool MillerRabin(i128 n, int k = 10) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;

    i128 d = n - 1;
    int s = 0;
    while (d % 2 == 0) {
        d /= 2;
        ++s;
    }

    srand(time(0));
    for (int i = 0; i < k; ++i) {
        i128 a = rand() % (n - 3) + 2;
        i128 x = qpow(a, d, n);
        if (x == 1 || x == n - 1) continue;

        bool flag = false;
        for (int r = 1; r < s; ++r) {
            x = x * x % n;
            if (x == n - 1) {
                flag = true;
                break;
            }
        }
        if (!flag)
            return false;
    }
    return true;
}

// 输出 __int128 类型
void print_i128(i128 n) {
    if (n == 0) {
        putchar('0');
        return;
    }
    char buf[50];
    int len = 0;
    while (n) {
        buf[len++] = n % 10 + '0';
        n /= 10;
    }
    for (int i = len - 1; i >= 0; --i)
        putchar(buf[i]);
    putchar('\n');
}

int main() {
    i128 n = 1;
    for (int i = 0; i < 28; ++i) n *= 10;
    n -= 1;

    // 从 n 开始，往下找第一个质数
    while (true) {
        if (MillerRabin(n)) {
            cout << "找到 1e28 以下最大质数：" << endl;
            print_i128(n);
            break;
        }
        n -= 2; // 只检查奇数
    }

    return 0;
}