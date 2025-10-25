/* I128.cpp */
#include <bits/stdc++.h>
using namespace std;
using i128 = __int128;
string to_string_i128(i128 x) {
    if (x == 0) return "0";
    bool neg = x < 0;
    if (neg) x = -x;
    string res;
    while (x > 0) {
        res.push_back('0' + x % 10);
        x /= 10;
    }
    if (neg) res.push_back('-');
    reverse(res.begin(), res.end());
    return res;
}
i128 read_i128() {
    string s;
    cin >> s;
    bool neg = false;
    i128 res = 0;
    int i = 0;
    if (s[0] == '-') { neg = true; i = 1; }
    for (; i < (int)s.size(); i++) res = res * 10 + (s[i] - '0');
    if (neg) res = -res;
    return res;
}
ostream& operator<<(ostream &os, i128 x) {
    os << to_string_i128(x);
    return os;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // 读入 i128
    cout << "请输入两个 i128 数字:" << endl;
    i128 a = read_i128();
    i128 b = read_i128();
    // 加减乘除
    i128 sum = a + b;
    i128 diff = a - b;
    i128 prod = a * b;
    i128 quot = 0;
    if (b != 0) quot = a / b;
    cout << "a + b = " << sum << "\n";
    cout << "a - b = " << diff << "\n";
    cout << "a * b = " << prod << "\n";
    if (b != 0) cout << "a / b = " << quot << "\n";
    long long c = 1234567890123456789LL;
    i128 d = a + c;
    cout << "a + c = " << d << "\n";

    return 0;
}