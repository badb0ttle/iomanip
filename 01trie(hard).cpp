/*blank*/
#include<bits/stdc++.h>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<stack>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<set>
#include<string.h>
#include<string>
#include<stdio.h>
#include<deque>
#include<numeric>
using namespace std;
#define ll long long
#define lll __uint128_t
#define ld long double
#define ull unsigned long long
#define re register
#define il inline
#define fi first
#define se second
#define all(v) v.begin(),v.end()
#define pb push_back
#define lowbit(x) (x&-x)
#define fixed(x) fixed<<setprecision(x)
#define lcm(x,y) x*y/__gcd(x,y)
#define endl "\n"
#define io ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
const ll N = 2e5 + 100, M = 1e6+10, base = 13331, mod = 1e9 + 7;
const ull INF=1e18;
const double pie=acos(-1),eps=1e-8;
int dir[]={0,1,0,-1,0};
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,-1,0,1,-1};
typedef pair<ll, ll>PAIR;
int a[N];
struct node
{
    int val;
    int son[2];
}t[N<<5];
int idx = 1;
struct Q{
    int id,t, x, k;
};
vector<Q>que;
int ans[N];
void insert(int x)
{
    int o=0;
    t[o].val++;
    for(int i=30;i>=0;--i)
    {
        int y=x>>i&1;
        int &u = t[o].son[y];
        if(!u)u= ++idx;
        o=u;
        t[o].val++;
    }
}
int getVal(int x,int k)
{
    int o=0,res=0;
    for(int i=30;i>=0;--i)
    {
        int y=x>>i&1;
        //u点是小点，v点是大点
        int u=t[o].son[y],v=t[o].son[!y];
        if(u&&t[u].val>=k)o=u;
        else o=v,k -= u?t[u].val:0,res |=(1<<i);
    }
    return res;
}
void solve()
{
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=q;++i)
    {
        int t,x,k; cin>>t>>x>>k;
        que.push_back({i,t,x,k});
    }
    sort(que.begin(),que.end(),[](const Q&u,const Q &v){
        return u.t != v.t ? u.t < v.t : u.id < v.id;
    });
    int now =0;
    for(const auto & qe:que)
    {
        while(now<qe.t) insert (a[++ now]);
        ans [qe.id]=getVal(qe.x,qe.k);
    }
    for(int i=1;i<=q;++i)cout<<ans[i]<<'\n';
}
signed main(){
    io;
    ll _ = 1;
    //cin >> _;
    while(_ -- ) solve();
    return 0;
}