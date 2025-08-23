/*blank*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+9;
const ll inf=2e18;
int n,idx;
struct Node{
    int ls,rs,val;
} t[N<<5];
vector<int>X;
int a[N],rt[N];
int bin(int x){return lower_bound(X.begin(),X.end(),x)-X.begin()+1;}
void insert(int &o,int pre,int val,int s=1,int e=n)
{
    //分配节点
    o=++idx;
    //复刻上一个版本
    t[o]=t[pre];
    //修改自身的权值
    t[o].val++;
    if(s==e)return;
    //决策下一步
    int mid=(s+e)>>1;
    if(val<=mid)insert(t[o].ls,t[pre].ls,val,s,mid);
    else insert(t[o].rs,t[pre].rs,val,mid+1,e);
}
int queryVal(int lo,int ro,int k,int s=1,int e=n)
{
    if(s==e)return s;
    int left_sum=t[t[ro].ls].val - t[t[lo].ls].val;
    int mid=(s+e)>>1;
    if(k<=left_sum)return queryVal(t[lo].ls,t[ro].ls,k,s,mid);
    return queryVal(t[lo].rs,t[ro].rs,k-left_sum,mid+1,e);
}
void work()
{
    ll q;cin>>n>>q;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i)X.push_back(a[i]);
    sort(X.begin(),X.end());
    X.erase(unique(X.begin(),X.end()),X.end());
    for(int i=1;i<=n;++i)insert(rt[i],rt[i-1],bin(a[i]));
    while(q--)
    {
        int l,r,k;cin>>l>>r>>k;
        cout<<X[queryVal(rt[l-1],rt[r],k)-1]<<'\n';
    }
}
int main() {
    int _=1;
    //std::cin>>_;
    while(_--)work();
    return 0;
}