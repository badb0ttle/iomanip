// 功能：无向图中求环的大小（如果存在大小大于1的环，记录环大小）
// O(n)
#include <cstring>
#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
constexpr int N = 2e5 + 10;

int n;
vector<int> out[N];      // 邻接表建图
int dfn[N], low[N];      // 时间戳，low 数组
int ts;                  // 时间戳递增器
int stk[N], top;         // 栈 和 栈顶指针
int circle_sz;           // 最大环的大小
bitset<N> instk;         // 标记点是否在栈内

// Tarjan 算法核心，寻找强连通分量（无向图中环）
void tarjan(int u, int fa) {
    dfn[u] = low[u] = ++ts;
    stk[++top] = u;
    instk[u] = 1;

    for (auto v : out[u]) {
        if (v == fa) continue;  // 无向图跳过父亲

        if (!dfn[v]) {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
        } else if (instk[v])
            low[u] = min(low[u], dfn[v]);
    }

    // 如果 u 是强连通分量的根
    if (low[u] == dfn[u]) {
        int cnt = 0;
        while (stk[top + 1] != u) {
            instk[stk[top--]] = 0;
            cnt++;
        }
        if (cnt > 1) circle_sz = cnt;  // 如果是环（点数 > 1）
    }
}

void solve() {
    // 初始化
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(stk, 0, sizeof(stk));
    ts = 0;
    top = -1;
    circle_sz = 0;
    instk.reset();

    // 读入无向图
    cin >> n;
    for (int i = 1; i <= n; i++) out[i].clear();
    for (int i = 1; i <= n; i++) {
        int u, v;
        cin >> u >> v;
        out[u].push_back(v);
        out[v].push_back(u);
    }

    // 从点 1 开始 Tarjan
    tarjan(1, 0);

    // 输出环大小
    cout << circle_sz << "\n";
}

int main() {
    int _;
    cin >> _;
    while (_--)
        solve();
    return 0;
}