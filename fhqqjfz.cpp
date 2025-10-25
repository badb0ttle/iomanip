/*ordinary.exe*/
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
const int mx = 2e5 + 5;
mt19937 sj(1919810);
struct node
{
    int l, r;
    int v, key;
    int sz;
    bool rev;
} fhq[mx];
int cnt, root;
int build(int v) // 建树
{
    fhq[++cnt].v = v;
    fhq[cnt].key = sj();
    fhq[cnt].sz = 1;
    return cnt;
}
void pushup(int u) // 更新节点
{
    fhq[u].sz = (fhq[u].l ? fhq[fhq[u].l].sz : 0) + (fhq[u].r ? fhq[fhq[u].r].sz : 0) + 1;
}
void pushdown(int u) // 更新标记
{
    if (fhq[u].rev)
    {
        swap(fhq[u].l, fhq[u].r);
        if (fhq[u].l)
            fhq[fhq[u].l].rev ^= 1;
        if (fhq[u].r)
            fhq[fhq[u].r].rev ^= 1;
        fhq[u].rev = 0;
    }
}
void split(int u, int siz, int &x, int &y) // 从u节点分裂成两棵树(两个区间)
{
    if (!u)
        x = y = 0;
    else
    {
        if (fhq[u].rev)
            pushdown(u);
        int lsz = fhq[u].l ? fhq[fhq[u].l].sz : 0;
        if (lsz < siz)
        {
            x = u;
            split(fhq[u].r, siz - lsz - 1, fhq[u].r, y);
        }
        else
        {
            y = u;
            split(fhq[u].l, siz, x, fhq[u].l);
        }
        pushup(u);
    }
}
int merge(int x, int y) // 合并x,y节点的树(区间合并)
{
    if (!x || !y)
        return x + y;
    if (fhq[x].key < fhq[y].key)
    {
        if (fhq[x].rev)
            pushdown(x);
        fhq[x].r = merge(fhq[x].r, y);
        pushup(x);
        return x;
    }
    else
    {
        if (fhq[y].rev)
            pushdown(y);
        fhq[y].l = merge(x, fhq[y].l);
        pushup(y);
        return y;
    }
}
void rev(int l, int r) // 区间反转
{
    int x, y, z;
    split(root, l - 1, x, y);
    split(y, r - l + 1, y, z);
    fhq[y].rev ^= 1;
    root = merge(merge(x, y), z);
}
void work()
{
    int n, m;
    cin >> n >> m;
    root = 0;
    cnt = 0;
    for (int i = 1; i <= n; i++)
        root = merge(root, build(i));
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        rev(l, r);
    }
    vector<int> res;
    auto dfs = [&](auto self,int u)->void
    {
        if (!u)
            return;
        if (fhq[u].rev)
            pushdown(u);
        self(self,fhq[u].l);
        res.push_back(fhq[u].v);
        self(self,fhq[u].r);
    };
    dfs(dfs,root);
    for (int i = 0; i < n; i++)
        cout << res[i] << " \n"[i == n - 1];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        work();
}