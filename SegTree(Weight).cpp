/*blank*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long//一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
#define PII pair<int,int>
#define debug(x) cout<<#x<<'='<<x<<'\n'
const int mx=2e5+1;
ll q,op,l,r,x,t[mx<<2],n=mx;//非可持续性权值线段树
void pushup(int v)
{
    t[v]=t[v<<1]+t[v<<1|1];
}
void insert(ll v,ll s=1,ll e=n,ll o=1)
{
    if(s==e)return t[o]++,void();
    ll mid=(s+e)>>1;
    if(v<=mid)insert(v,s,mid,o<<1);
    else insert(v,mid+1,e,o<<1|1);
    pushup(o);
}
ll queryCnt(ll l,ll r,ll s=1,ll e=n,ll o=1)//查询大小在[l,r]的元素的个数之和
{
    if(l<=s&&r>=e)return t[o];
    ll mid=(s+e)>>1;
    ll res=0;
    if(max(s,l)<=min(mid,e))res+=queryCnt(l,r,s,mid,o<<1);
    if(max(mid+1,l)<=min(r,e))res+=queryCnt(l,r,mid+1,e,o<<1|1);
    return res;
}
ll queryVal(ll k,ll s=1,ll e=n,ll o=1)//查询集合中kth小的元素
{
    if(s==e)return s;
    ll ls=t[o<<1];
    ll mid=(s+e)>>1;
    if(k<=ls)return queryVal(k,s,mid,o<<1);
    return queryVal(k-ls,mid+1,e,o<<1|1);
}
void work()
{
    cin>>q;
    while(q--)
    {
        cin>>op;
        if(op==1)
        {
            cin>>x;
            insert(x);
        }
        else if(op==2)
        {
            cin>>l>>r;
            cout<<queryCnt(l,r)<<'\n';
        }
        else if(op==3)
        {
            cin>>x;
            cout<<queryVal(x)<<'\n';
        }
    }
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