/*blank*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long//一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
const int N = 1e5 + 9;
const ll inf = 2e18;
const int T = 18;
ll stMax[N][20], stMin[N][20], stGcd[N][20];
ll a[N];
ll getMax(int l, int r)
{
   int k = log(r - l + 1) / log(2);
   return max(stMax[l][k], stMax[r - (1 << k) + 1][k]);
}
ll getMin(int l, int r)
{
   int k = log(r - l + 1) / log(2);
   return min(stMin[l][k], stMin[r - (1 << k) + 1][k]);
}
ll getGcd(int l, int r)
{
   int k = log(r - l + 1) / log(2);
   return __gcd(stGcd[l][k], stGcd[r - (1 << k) + 1][k]);
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
   for (int j = 1; j <= T; ++j)
   {
       for (int i = 1; i + (1 << j) - 1 <= n; ++i)
       {
           stMax[i][j] = max(stMax[i][j - 1], stMax[i + (1 << (j - 1))][j - 1]);
           stMin[i][j] = min(stMin[i][j - 1], stMin[i + (1 << (j - 1))][j - 1]);
           stGcd[i][j] = __gcd(stGcd[i][j - 1], stGcd[i + (1 << (j - 1))][j - 1]);
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
int _=1;
//cin >> _;
//sc("%d",&_);
while (_--)work();
return 0;
}