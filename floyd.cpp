/*blank*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long // 一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
const int mx = 301;
const ll inf=4e18;
ll dp[mx][mx];
void work()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        fill(begin(dp[i]), end(dp[i]), inf);
    for(int i=1;i<=n;++i)dp[i][i]=0;
    for(int k=1;k<=n;++k)  
    for(int i=1;i<=n;++i)  
    for(int j=1;j<=n;++j)dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j])  ;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _ = 1;
    // cin >> _;
    // sc("%d",&_);
    while (_--)
        work();
    return 0;
}