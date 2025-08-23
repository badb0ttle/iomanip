/*blank*/
#include <bits/stdc++.h>

using i64 = long long;
const int mx = 1001;
int n, m;
int dif[mx][mx];
void work()
{
    std::cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        dif[x1][y1]++;
        dif[x2 + 1][y1]--;
        dif[x1][y2 + 1]--;
        dif[x2 + 1][y2 + 1]++;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            dif[i][j] = dif[i - 1][j] + dif[i][j - 1] - dif[i - 1][j - 1] + dif[i][j];
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            std::cout << dif[i][j] << ' ';
        }
        std::cout << '\n';
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int _ = 1;
    // std::cin>>_;
    while (_--)
        work();
    return 0;
}