/*🫵😉👍*/
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
#define SZ(x) ((int)(x).size())
#define se second
#define all(v) v.begin(),v.end()
#define pb push_back
#define lowbit(x) (x&-x)
#define fixed(x) fixed<<setprecision(x)
#define lcm(x,y) x*y/__gcd(x,y)
#define endl "\n"
#define debug(x) cout << #x << " = " << (x) << endl;
#define io ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
const ll N = 2e5 + 100, M = 1e6+10, base = 13331, mod = 1e9 + 7;
const ull INF=1e18;
const double pie=acos(-1),eps=1e-8;
int dir[]={0,1,0,-1,0};
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,-1,0,1,-1};
typedef pair<ll, ll>PAIR;
//重链剖分求LCA
vector<int>g[N];
int fa[N],son[N],top[N],dep[N],sz[N];
void dfs1(int x,int pre)
{
    dep[x]=dep[pre]+1;
    sz[x]=1;
    for(const auto&y:g[x])
    {
        dfs1(y,x);
        sz[x]+=sz[y];
        if(sz[y]>sz[son[x]])son[x]=y;
    }
}

void dfs2(int x,int t)
{
    top[x]=t;
    //先走重儿子
    if(son[x])dfs2(son[x],t);
    for(const auto&y:g[x])
    {
        if(y==son[x]) continue;
        dfs2(y,y);
    }
}
int lca(int x,int y)
{
    while(top[x]!=top[y])
    {
        //top偏下的往上跳
        if(dep[top[x]]<dep[top[y]])swap(x,y);
        x=fa[top[x]];
    }
    if(dep[x]<dep[y])swap(x,y);
    return y;
}
void solve(){
    int n;cin>>n;
    for(int i=2;i<=n;++i)
    {
        cin>>fa[i];
        g[fa[i]].pb(i);
    }
    dfs1(1,0);
    dfs2(1,1);//以1为根
    int m;
    cin>>m;
    while(m--){
        int x,y;
        cin>>x>>y;
        cout<<lca(x,y)<<'\n';
    }
}
signed main(){
    io;
    ll _ = 1;
    //cin >> _;
    while(_ -- ) solve();
    return 0;
}