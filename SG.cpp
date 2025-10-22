#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
vector<int> v; // 存储1和所有质数
const int N = 1e5 + 5;
void init(int n)
{
    bitset<N> vis;
    vis[0] = vis[1] = 1;
    for (int i = 2; i <= n; ++i)
        for (int j = i * i; j <= n; j += i)
            vis[j] = 1;
    v.push_back(1);
    for (int i = 2; i <= n; ++i)
        if (!vis[i])
            v.push_back(i);
}
map<int, int> sg;
i64 getSG(int x)
{
    if (!x)
        return 0;
    if (sg.count(x))
        return sg[x];
    unordered_set<i64> st;
    for (const auto &i : v)
    {
        if (i <= x)
            st.insert(getSG(x - i));
        else
            break;
    }
    for (int i = 0;; ++i)
    {
        if (!st.count(i))
            return sg[x] = i;
    }
}
void work()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        ans^=a[i];
    }
    cout<<(ans%4?"YES":"NO")<<'\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    init(1000);
        // for (int i = 1; i <= 100; ++i)
        //     cout << getSG(i) << ' ';
    int t;
    cin >> t;
    while (t--)
        work();
}