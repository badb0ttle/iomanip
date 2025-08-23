#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 2e5 + 10;

int dfn[N], low[N], idx;       // dfn：时间戳，low：能追溯到的最小时间戳，idx：当前时间戳
int stk[N], top;               // 栈，top：栈顶指针
int col, cnt[N];               // col：强连通分量编号，cnt[i]：编号为 i 的强连通分量大小
bitset<N> bs;                  // bs[i]：结点 i 是否在当前栈中
vector<int> g[N];              // 邻接表存图

// Tarjan 算法，求强连通分量
void tarjan(int x) {
    dfn[x] = low[x] = ++idx;   // 时间戳赋值
    stk[++top] = x;            // 入栈
    bs[x] = 1;                 // 标记在栈中

    for (auto y : g[x]) {      // 遍历所有邻接点
        if (!dfn[y]) {         // 如果 y 没有访问过，递归 tarjan
            tarjan(y);
            low[x] = min(low[x], low[y]);
        } else if (bs[y]) {    // 如果 y 在栈中，更新 low 值
            low[x] = min(low[x], dfn[y]);
        }
    }

    // 找到一个强连通分量
    if (dfn[x] == low[x]) {
        col++;                 // 强连通分量编号 +1
        while (stk[top + 1] != x) { // 弹栈，直到 x 出现
            cnt[col]++;        // 当前强连通分量内点数 +1
            bs[stk[top--]] = 0;// 出栈并取消标记
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;

    // 建图（有向图）
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }

    // 对每个未访问的点执行 tarjan
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) tarjan(i);
    }

    vector<int> v;
    // 收集所有大小大于 1 的强连通分量的大小
    for (int i = 1; i <= col; i++) {
        if (cnt[i] > 1) v.push_back(cnt[i]);
    }

    if (!v.size()) cout << -1 << "\n";
    else {
        sort(v.begin(), v.end());
        for (auto u : v) cout << u << " ";
    }

    return 0;
}