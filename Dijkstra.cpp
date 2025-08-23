/*blank*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long//一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
const int mx=2e5+1;
const ll inf=4e18;
struct edge{
ll v,w;
bool operator <(const edge&a)const{
    return w==a.w?v<a.v:w>a.w;
}
};
vector<edge>g[mx];
ll dp[mx];
void dijkstra(int st)
{
    bitset<mx>vis;
    fill(begin(dp),end(dp),inf);
    priority_queue<edge>qp;
    dp[st]=0;
    qp.push({st,0});
    while(qp.size())
    {
        ll x=qp.top().v;
        qp.pop();
        if(vis[x])continue;
        vis[x]=1;
        for(auto&[v,w]:g[x])
        {
            if(!vis[v]&&dp[v]>dp[x]+w)dp[v]=dp[x]+w;
            qp.push({v,dp[v]});
        }
    }
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