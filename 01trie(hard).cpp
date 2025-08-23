/*  
功能：  
动态插入前缀异或字典树，查询给定前缀内第k小的与x的异或值。  

思路：  
用可持久化字典树（Trie）维护前缀内值，  
支持动态插入和在线求解第k小异或值。

时间复杂度：
- 插入：O(logC)，C为数值上限（这里最多31位）
- 查询：O(logC)
- 排序：O(QlogQ)
总复杂度：O((N+Q)logC)

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 2e5 + 100;

// 数组和常量声明
int a[N];
struct node {
    int val;        // 当前节点数量
    int son[2];     // 子节点编号 0 / 1
} t[N << 5];        // Trie节点数量开到4倍

int idx = 1;        // Trie节点编号

// 查询结构体
struct Q {
    int id, t, x, k;
};
vector<Q> que;      // 查询数组
int ans[N];         // 答案数组

// 插入操作，将x插入到Trie中
void insert(int x) {
    int o = 0;
    t[o].val++;
    for (int i = 30; i >= 0; --i) {
        int y = x >> i & 1;
        int &u = t[o].son[y];
        if (!u) u = ++idx;
        o = u;
        t[o].val++;
    }
}

// 查询操作：查询前缀内第k小的与x异或值
int getVal(int x, int k) {
    int o = 0, res = 0;
    for (int i = 30; i >= 0; --i) {
        int y = x >> i & 1;
        int u = t[o].son[y];
        int v = t[o].son[!y];

        // 如果当前位匹配数量足够，继续走
        if (u && t[u].val >= k) o = u;
        else {
            // 选反位，更新答案
            o = v;
            k -= u ? t[u].val : 0;
            res |= (1 << i);
        }
    }
    return res;
}

void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= q; ++i) {
        int t, x, k;
        cin >> t >> x >> k;
        que.push_back({i, t, x, k});
    }

    // 排序，按时间t升序，id升序
    sort(que.begin(), que.end(), [](const Q &u, const Q &v) {
        return u.t != v.t ? u.t < v.t : u.id < v.id;
    });

    int now = 0;
    // 依次处理查询
    for (const auto &qe : que) {
        while (now < qe.t) insert(a[++now]); // 动态插入
        ans[qe.id] = getVal(qe.x, qe.k);
    }

    // 输出结果
    for (int i = 1; i <= q; ++i) cout << ans[i] << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll _ = 1;
    while (_--) solve();
    return 0;
}