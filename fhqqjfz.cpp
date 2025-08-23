/*blank*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long//一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
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
int build(int v)//建树
{
    fhq[++cnt].v = v;
    fhq[cnt].key = sj();
    fhq[cnt].sz = 1;
    return cnt;
}
void pushup(int u)//更新节点
{
    fhq[u].sz = fhq[fhq[u].l].sz + fhq[fhq[u].r].sz + 1;
}
void pushdown(int u)//更新标记
{
    swap(fhq[u].l, fhq[u].r);
    fhq[fhq[u].l].rev ^= 1;
    fhq[fhq[u].r].rev ^= 1;
    fhq[u].rev = false;
}
void split(int u, int siz, int &x, int &y)//从u节点分裂成两棵树(两个区间)
{
    if (!u)
        x = y = 0;
    else
    {
        if (fhq[u].rev)
            pushdown(u);
        if (fhq[fhq[u].l].sz < siz)
        {
            x = u;
            split(fhq[u].r, siz - fhq[fhq[u].l].sz - 1, fhq[u].r, y);
        }
        else
        {
            y = u;
            split(fhq[u].l, siz, x, fhq[u].l);
        }
        pushup(u);
    }
}
int merge(int x, int y)//合并x,y节点的树(区间合并)
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
void rev(int l, int r)//区间反转
{
    int x, y, z;
    split(root, l - 1, x, y);
    split(y, r - l + 1, y, z);
    fhq[y].rev ^= 1;
    root = merge(merge(x, y), z);
}
void work()
{
    
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
int _=1;
//cin >> _;
//sc("%d",&_);
while (_--)work();
return 0;
}