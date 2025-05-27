/*blank*/
#include <bits/stdc++.h>
const int N = 2e5 + 10; // 数组大小上限（根据题目调整）
int n, m, a[N], rt[N], idx;
struct Node { int l, r, v; } tr[N << 5]; // 注意 N<<5 是经验值，可根据题目数据范围改
std::vector<int> raw; // 离散化原数组
// 返回 x 离散化后的值（排名）
int xid(int x) {
    return lower_bound(raw.begin(), raw.end(), x) - raw.begin() + 1;
}

// 可持久化线段树插入，建第 i 棵权值线段树
void add(int& o, int pre, int x, int s = 1, int e = raw.size()) {
    o = ++idx;           
    tr[o] = tr[pre];     
    tr[o].v++;           
    if (s == e) return;  

    int mid = s + e >> 1;
    if (x <= mid)
        add(tr[o].l, tr[pre].l, x, s, mid);
    else
        add(tr[o].r, tr[pre].r, x, mid + 1, e);
}
// 查询区间第 k 小
int query(int o, int ol, int k, int s = 1, int e = raw.size()) {
    if (s == e) return s; // 到叶子节点，返回编号（离散化后的值）

    int mid = s + e >> 1;
    int lc = tr[tr[o].l].v - tr[tr[ol].l].v; 

    if (k <= lc)
        return query(tr[o].l, tr[ol].l, k, s, mid);
    else
        return query(tr[o].r, tr[ol].r, k - lc, mid + 1, e);
}
using i64 = long long;
void work()
{
   std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        raw.push_back(a[i]);
    }

    // 离散化
    sort(raw.begin(), raw.end());
    raw.erase(unique(raw.begin(), raw.end()), raw.end());

    // 建树，rt[i] 表示第 i 棵权值线段树的根
    for (int i = 1; i <= n; i++)
        add(rt[i], rt[i - 1], xid(a[i]));

    // m 次查询
    while (m--) {
        int l, r, k;
        std::cin >> l >> r >> k; 
        std::cout << raw[query(rt[r], rt[l - 1], k) - 1] << "\n"; // 注意 -1 因为离散化下标+1 了
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int _=1;
    //std::cin>>_;
    while(_--)work();
    return 0;
}