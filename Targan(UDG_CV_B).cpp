// 功能：Tarjan 算法求无向图割点数量 和 桥的数量
//O(n+m)
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll N = 2e5 + 10;

int idx, dfn[N], low[N];
vector<int> g[N];
int cnt1, cnt2; // cnt1 割点数量，cnt2 桥数量

// Tarjan 核心，寻找割点和桥
void tarjan(int x, int fa) {
    dfn[x] = low[x] = ++idx;
    int child = 0; // 子树个数

    for (auto y : g[x]) {
        if (y == fa) continue; // 无向图跳过父亲

        if (!dfn[y]) {
            tarjan(y, x);
            low[x] = min(low[x], low[y]);

            // 判断是否是桥
            if (low[y] > dfn[x]) cnt2++;

            // 判断是否是割点
            if (low[y] >= dfn[x]) child++;
        } else {
            low[x] = min(low[x], dfn[y]);
        }
    }

    // 判断是否是割点（根据子树个数）
    if ((child >= 1 && fa) || (child >= 2 && fa == 0)) cnt1++;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    // 建图
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    // 对每个连通块执行 Tarjan
    for (int i = 1; i <= n; i++)
        if (!dfn[i]) tarjan(i, 0);

    // 输出割点数量 和 桥数量
    cout << cnt1 << " " << cnt2;
    return 0;
}