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
//启发式并查集
int pre[N],sz[N],a[N];
int find(int x)
{
    return pre[x] = (pre[x]==x ? x : find(pre[x]));
}
void merge(int x,int y)
{
    int fx=find(x),fy=find(y);
    if(fx==fy)return;
    if(sz[fx]>sz[fy])swap(fx,fy);
    pre[fx]=fy;
    sz[fy]+=sz[fx];
}
void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i)pre[i]=i,sz[i]=1;
    int m;cin>>m;
    while(m--)
    {
        int x, y;cin>>x>>y;
        merge(x,y);
    }
    int ans=0;
    for(int i=1;i<=n;++i)if(pre[i]!=i)a[find(i)]^=a[i];
    for(int i=1;i<=n;++i)if(pre[i]==i)ans=max(ans,a[i]);
    cout<<ans<<'\n';
}
//联通块大小
/*void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i)pre[i]=i,sz[i]=1;
    while(m--)
    {
        int x, y;cin>>x>>y;
        merge(x,y);
    }
    vector<int>vc;
    for(int i=1;i<=n;++i)if(pre[i]==i)vc.pb(sz[i]);
    sort(all(vc));
    for(const auto &i:vc)cout<<i<<' ';
}*/
signed main(){
    io;
    ll _ = 1;
    //cin >> _;
    while(_ -- ) solve();
    return 0;
}