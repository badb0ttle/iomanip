#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define io ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)

const int N = 1e5 + 10;

struct node {
    int v;        // 值
    int fa;       // 父节点编号
    int lc, rc;   // 左右子节点编号
    int dep;      // 深度
} t[N];
int root = 0, idx = 0;
map<int, int> mp; // 值 -> 节点编号映射
// 插入操作
void ins(int &u, int v, int fa, int dep) {
    if (!u) {
        u = ++idx;
        t[u] = {v, fa, 0, 0, dep};
        mp[v] = u;
        return;
    }
    if (v < t[u].v) ins(t[u].lc, v, u, dep + 1);
    else ins(t[u].rc, v, u, dep + 1);
}

// 查找值对应的节点编号
int find(int u, int v) {
    if (!u) return 0;
    if (t[u].v == v) return u;
    if (v < t[u].v) return find(t[u].lc, v);
    return find(t[u].rc, v);
}

// 获取兄弟节点的值
int getxd(int u) {
    int f = t[u].fa;
    if (!f) return 0;
    if (t[f].lc == u && t[f].rc) return t[t[f].rc].v;
    if (t[f].rc == u && t[f].lc) return t[t[f].lc].v;
    return 0;
}

// 中序遍历
void inorder(int u) {
    if (!u) return;
    inorder(t[u].lc);
    cout << t[u].v << ' ';
    inorder(t[u].rc);
}

// 前序遍历
void preorder(int u) {
    if (!u) return;
    cout << t[u].v << ' ';
    preorder(t[u].lc);
    preorder(t[u].rc);
}

// 后序遍历
void postorder(int u) {
    if (!u) return;
    postorder(t[u].lc);
    postorder(t[u].rc);
    cout << t[u].v << ' ';
}

// 找最小值（子树最左）
int findmin(int u) {
    while (t[u].lc) u = t[u].lc;
    return u;
}

// 找最大值（子树最右）
int findmax(int u) {
    while (t[u].rc) u = t[u].rc;
    return u;
}

// 删除操作
int rmv(int u, int v) {
    if (!u) return 0;
    if (v < t[u].v) t[u].lc = rmv(t[u].lc, v);
    else if (v > t[u].v) t[u].rc = rmv(t[u].rc, v);
    else {
        if (!t[u].lc) return t[u].rc;
        if (!t[u].rc) return t[u].lc;
        int successor = findmin(t[u].rc);
        t[u].v = t[successor].v;
        t[u].rc = rmv(t[u].rc, t[successor].v);
    }
    return u;
}
// 找前驱（小于v的最大值）
int predecessor(int u, int v) {
    int pre = 0;
    while (u) {
        if (t[u].v < v) {
            pre = u;
            u = t[u].rc;
        } else u = t[u].lc;
    }
    return pre;
}

// 找后继（大于v的最小值）
int successor(int u, int v) {
    int suc = 0;
    while (u) {
        if (t[u].v > v) {
            suc = u;
            u = t[u].lc;
        } else u = t[u].rc;
    }
    return suc;
}

void solve() {
    int n;
    cin >> n;
    int a[n];
    for (int &x : a) cin >> x;

    // 建树
    for (int x : a) ins(root, x, 0, 1);

    // 树遍历演示
    cout << "中序: "; inorder(root); cout << endl;
    cout << "前序: "; preorder(root); cout << endl;
    cout << "后序: "; postorder(root); cout << endl;

    // 查询样例
    cout << "删除 3\n";
    root = rmv(root, 3);
    cout << "中序: "; inorder(root); cout << endl;

    cout << "前驱 后继示例:\n";
    for (int x : a) {
        int pre = predecessor(root, x);
        int suc = successor(root, x);
        cout << x << " 前驱: " << (pre ? t[pre].v : -1) << " 后继: " << (suc ? t[suc].v : -1) << endl;
    }
}

int main() {
    io;
    solve();
    return 0;
}