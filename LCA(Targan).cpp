#include <bits/stdc++.h>
using namespace std;

// 常用宏定义和类型定义
#define ll long long
#define re register
#define fi first
#define se second
#define endl "\n"
#define io ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)

const ll N = 2e5 + 100;
typedef pair<ll, ll> PAIR;

// 图的邻接表
vector<int> g[N];

// 并查集数组
int pre[N];
// 节点深度
int dep[N];
// LCA 查询答案
int ans[N];
// 父节点记录
int fa[N];

// 查询容器，Q[u] 存放所有和 u 查询的点和对应查询编号
vector<PAIR> Q[N];

// 节点访问标记
bitset<N> vis;

// 并查集查找操作，路径压缩
int find(int x) {
    return pre[x] == x ? x : pre[x] = find(pre[x]);
}

// 并查集合并操作，将 x 所在集合与 y 所在集合合并
void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if (dep[x] < dep[y]) swap(fx, fy);
    pre[fx] = fy;
}

// Tarjan+并查集 LCA 求解
void dfs(int x) {
    dep[x] = dep[fa[x]] + 1; // 记录当前节点深度
    vis[x] = 1;              // 标记当前节点已访问

    // 遍历子节点
    for (const auto& y : g[x]) dfs(y);

    // 遍历和 x 有查询关系的点
    for (const auto& [y, id] : Q[x]) {
        if (!vis[y]) continue;        // 如果 y 还未访问，跳过
        ans[id] = find(y);            // 否则，查询 LCA 并记录答案
    }

    // 将当前节点和它父亲合并
    merge(x, fa[x]);
}

// 主流程
void solve() {
    int n;
    cin >> n;

    // 并查集初始化，每个点是自己父亲
    for (int i = 1; i <= n; ++i) pre[i] = i;

    // 读入树结构
    for (int i = 2; i <= n; ++i) {
        cin >> fa[i];
        g[fa[i]].push_back(i);
    }

    int q;
    cin >> q;

    // 读入所有 LCA 查询
    for (int i = 1; i <= q; ++i) {
        int x, y;
        cin >> x >> y;
        Q[x].push_back({y, i});
        Q[y].push_back({x, i});
    }

    // 从根节点 1 开始 DFS
    dfs(1);

    // 输出答案
    for (int i = 1; i <= q; ++i) cout << ans[i] << '\n';
}

signed main() {
    io;
    ll _ = 1;
    while (_--) solve();
    return 0;
}