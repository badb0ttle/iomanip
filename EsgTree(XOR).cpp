/*blank*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long//一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
using pii = pair<int,int>;
const int N = 2e5 + 10;
const ll inf = 8e18, p = 998244353,mod = 1e9 + 7;

struct seetree
{
   ll sum[N << 2] = {0},a[N] = {0},tg[N << 2] = {0};
   void pushup(int o)
   {
   	sum[o] = sum[o<<1] ^ sum[(o<<1|1)];
   }
   void update(int l,int r,ll x,int o)
   {
   	if((r - l + 1) & 1)
   	{
   		sum[o] ^= x;
   	}
   	tg[o] ^= x;
   }
   void down(int l,int r,int o)
   {
   	int mid = (l + r) >> 1;
   	if(tg[o] != 0)
   	{
   		update(l,mid,tg[o],o<<1);
   		update(mid + 1,r,tg[o],(o<<1|1));
   		tg[o] = 0;
   	}
   }
   void build(int st,int ed,int o)
   {
   	if(st == ed)
   	{
   		sum[o] = a[st];
   		return;
   	}
   	int mid = (st + ed) >> 1;
   	build(st,mid,o<<1);
   	build(mid + 1,ed,(o<<1|1));
   	pushup(o);
   }
   ll query(int a,int b,int l,int r,int o)
   {
   	if(a <= l && b >= r)
   	{
   		return sum[o];
   	}
   	down(l,r,o);
   	int mid = (l + r) >> 1;
   	ll ans = 0;
   	if(a <= mid)
   	{
   		ans ^= query(a,b,l,mid,o<<1);
   	}
   	if(b > mid)
   	{
   		ans ^= query(a,b,mid + 1,r,(o<<1|1));
   	}
   	return ans;
   }
   void add(int a,int b,ll x,int l,int r,int o)
   {
   	if(a <= l && b >= r)
   	{
   		update(l,r,x,o);
   		return;
   	}
   	down(l,r,o);
   	int mid = (l + r) >> 1;
   	if(a <= mid)
   	{
   		add(a,b,x,l,mid,o<<1);
   	}
   	if(mid < b)
   	{
   		add(a,b,x,mid + 1,r,(o<<1|1));
   	}
   	pushup(o);
   }
}ss;


void work()
{
   int n,q;cin >> n >> q;
   for(int i = 1;i <= n;++i)
   {
       cin >> ss.a[i];
   }
   ss.build(1,n,1);
   while(q--)
   {
       int op,l,r;cin >> op >> l >> r;
       if(op == 1)
       {
           int x;cin >> x;
           ss.add(l,r,x,1,n,1);
       }
       else
       {
           cout << ss.query(l,r,1,n,1) << '\n';
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