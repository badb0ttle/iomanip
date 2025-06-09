/* 倍增最近公共祖先 LCA 模板
   复杂度：
     - 预处理 dfs + 倍增表：O(n log n)
     - 单次查询：O(log n)
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define io ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)

const int N = 2e5 + 100;
const int T = 20;   // 倍增最大幂次，log2(N) 向上取整即可
vector<int> g[N];   // 存图（树）

int fa[N][T + 1];   // fa[i][j] 表示 i 节点往上跳 2^j 个祖先
int dep[N];         // dep[i] 表示 i 节点深度

// dfs 预处理 fa 和 dep
void dfs(int x)
{
    // 先处理当前点的深度
    dep[x] = dep[fa[x][0]] + 1;

    // 倍增预处理 fa[x][i]
    for (int i = 1; i <= T; ++i)
        fa[x][i] = fa[fa[x][i - 1]][i - 1];

    // 遍历子节点，递归 dfs
    for (const auto &y : g[x])
        dfs(y);
}

// 查询 x 和 y 的最近公共祖先 LCA
int lca(int x, int y)
{
    // 让 x 深度 >= y
    if (dep[x] < dep[y])
        swap(x, y);

    // 使 x 和 y 跳到同一深度
    for (int i = T; i >= 0; --i)
        if (dep[fa[x][i]] >= dep[y])
            x = fa[x][i];

    // 如果已经相等，直接返回
    if (x == y)
        return x;

    // 倍增一起往上跳，直到相等
    for (int i = T; i >= 0; --i)
        if (fa[x][i] != fa[y][i])
            x = fa[x][i], y = fa[y][i];

    // 返回公共祖先
    return fa[x][0];
}

void solve()
{
    int n;
    cin >> n;

    // 读入树结构，记录父亲
    for (int i = 2; i <= n; ++i)
    {
        cin >> fa[i][0];            // fa[i][0] 表示 i 的父亲
        g[fa[i][0]].push_back(i);   // 建树
    }

    // 以 1 为根 dfs 预处理
    dfs(1);

    // 处理 q 次查询
    int q;
    cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        cout << lca(x, y) << '\n';
    }
}

signed main()
{
    io;
    solve();
    return 0;
}