/*blank*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long//一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
const int N = 1e5 + 9;
const ll inf = 2e18;
const int T = 25;
ll stMax[N][T], stMin[N][T], stGcd[N][T];
ll a[N], lg2[N];
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
ll getMax(int l, int r)
{
   int k = lg2[r - l + 1];
   return max(stMax[l][k], stMax[r - (1 << k) + 1][k]);
}
ll getMin(int l, int r)
{
   int k = lg2[r - l + 1] ;
   return min(stMin[l][k], stMin[r - (1 << k) + 1][k]);
}
ll getGcd(int l, int r)
{
   int k = lg2[r - l + 1];
   return gcd(stGcd[l][k], stGcd[r - (1 << k) + 1][k]);
}
void work()
{
   int n, q;
   cin >> n >> q;
   for (int i = 1; i <= n; ++i)
       cin >> a[i];
   // 初始化长度为1的情况
   for (int i = 1; i <= n; ++i)
       stMax[i][0] = stMin[i][0] = stGcd[i][0] = a[i];
   for (int j = 1; j <= lg2[n]; ++j)
   {
       for (int i = 1; i + (1 << j) - 1 <= n; ++i)
       {
           stMax[i][j] = max(stMax[i][j - 1], stMax[i + (1 << (j - 1))][j - 1]);
           stMin[i][j] = min(stMin[i][j - 1], stMin[i + (1 << (j - 1))][j - 1]);
           stGcd[i][j] = gcd(stGcd[i][j - 1], stGcd[i + (1 << (j - 1))][j - 1]);
       }
   }
   while (q--)
   {
       int l, r;
       cin >> l >> r;
       cout << getMax(l, r) << ' ' << getMin(l, r) << ' ' << getGcd(l, r) << '\n';
   }
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
for(int i = 2; i <= N; i++) lg2[i] = lg2[i >> 1] + 1;
int _=1;
cin >> _;
//sc("%d",&_);
while (_--)work();
return 0;
}