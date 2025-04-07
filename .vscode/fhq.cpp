/*blank*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long//一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
const int mx=2e5+1;
const int inf=1e9;
mt19937 sj(1919810);
struct node{
    int l,r;
    int sz,v,key;
}fhq[mx];
int idx,root,T1,T2,T3;
int build(int v)
{
    fhq[++idx]={0,0,1,v,(int)sj()};
    return idx;
}
void pushup(int v)
{
    fhq[v].sz=fhq[fhq[v].l].sz+fhq[fhq[v].r].sz+1;
}
void split(int u,int v,int&x,int&y)
{
    if(!u)
    {
        x=y=0;
        return ;
    }
    if(fhq[u].v>v)
    {
        y=u;
        split(fhq[u].l,v,x,fhq[u].l);
    }
    else
    {
        x=u;
        split(fhq[u].r,v,fhq[u].r,y);
    }
    pushup(u);
}
int merge(int x,int y)
{
    if(!x||!y) return x+y;
    if(fhq[x].key<fhq[y].key)
    {
        fhq[x].r=merge(fhq[x].r,y);
        pushup(x);
        return x;
    }
    else
    {
        fhq[y].l=merge(x,fhq[y].l);
        pushup(y);
        return y;
    }
}
void ins(int v)
{
    split(root,v,T1,T2);
    root=merge(merge(T1,build(v)),T2);
}
void del(int v)
{
    split(root, v, T1, T2);
    split(T1, v-1, T1, T3);
    if (T3) T3 = merge(fhq[T3].l, fhq[T3].r);
    root = merge(merge(T1, T3), T2);
}
int gr(int v)
{
    split(root, v - 1, T1, T2);
    int res = fhq[T1].sz;
    root = merge(T1, T2);
    return res + 1;
}
int kth(int k)
{
    int u = root;
    while (u)
    {
        int tmp = fhq[fhq[u].l].sz + 1;
        if (tmp == k)
            break;
        else if (tmp <= k)
        {
            k -= tmp;
            u = fhq[u].r;
        }
        else
        {
            u = fhq[u].l;
        }
    }
    return fhq[u].v;
}
int gpre(int v)
{
    split(root, v - 1, T1, T2);
    int u = T1;
    if (!u) {
        root = merge(T1, T2);
        return -inf;
    }
    while (fhq[u].r)
        u = fhq[u].r;
    root = merge(T1, T2);
    return fhq[u].v;
}
int gnext(int v)
{
    split(root, v, T1, T2);
    int u = T2;
    if (!u) {
        root = merge(T1, T2);
        return inf;
    }
    while (fhq[u].l)
        u = fhq[u].l;
    root = merge(T1, T2);
    return fhq[u].v;
}
int getmx()
{
    int u = root;
    while (fhq[u].r)
        u = fhq[u].r;
    return fhq[u].v;
}
int getmn()
{
    int u = root;
    while (fhq[u].l)
        u = fhq[u].l;
    return fhq[u].v;
}
bool vis(int v) {
    split(root, v, T1, T2);
    split(T1, v - 1, T1, T3);
    bool exist = (T3 != 0);
    root = merge(merge(T1, T3), T2);
    return exist;
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