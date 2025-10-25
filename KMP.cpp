/*ordinary.exe*/
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
const int mx = 1e6 + 9;
char s[mx], t[mx];
string str, tstr;
int nex[mx];
void work()
{
    cin >> tstr >> str;
    int n = str.size(), m = tstr.size();
    for (int i = 1; i <= n; ++i)
        s[i] = str[i - 1];
    for (int i = 1; i <= m; ++i)
        t[i] = tstr[i - 1];
    s[n + 1] = '#', t[m + 1] = '$';
    // getnex
    nex[1] = 0;
    for (int i = 2, j = 0; i <= m; ++i)
    {
        while (j && t[i] != t[j + 1])
            j = nex[j];
        if (t[i] == t[j + 1])
            j++;
        nex[i] = j;
    }
    for (int i = 1, j = 0; i <= n; ++i)
    {
        while (j && t[j + 1] == s[i])
            j = nex[j];
        if (t[j + 1] == s[i])
            j++;
    }
    for (int i = 1; i <= m; ++i)
        cout << nex[i] << ' ';
    cout << '\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        work();
}