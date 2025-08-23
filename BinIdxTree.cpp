/*blank*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
#define sc scanf
#define pr printf
const int mx=2e5+5;
ll n,q,a[mx],td[mx],ti_1d[mx];
ll lowbit(ll x) {return x&(-x);}
void update(int k,ll x)
{
   for(int i=k;i<=n;i+=lowbit(i))
   {
       td[i]+=x,ti_1d[i]+=x*k;
   }
}
ll getsum(int k)
{
   ll sum=0;
   for(int i=k;i>0;i-=lowbit(i))
   {sum+=(k+1)*td[i]-ti_1d[i];}
   return sum;
}
void work()
{
   cin>>n>>q;
   for(int i=1;i<=n;++i)cin>>a[i];
   for(int i=1;i<=n;++i)
   {
       update(i,a[i]),update(i+1,-a[i]);
   }
   int op;
   while(q--)
   {
       cin>>op;
       if(op==1)
       {
           ll l,r,v;
           cin>>l>>r>>v;
           update(l,v),update(r+1,-v);
       }
       else
       {
           ll l,r;
           cin>>l>>r;
           cout<<getsum(r)-getsum(l-1)<<'\n';
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