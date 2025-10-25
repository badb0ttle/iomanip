/*ordinary.exe*/
#include <bits/stdc++.h>
using namespace std;
using i64=long long;
using u64=unsigned long long;
const int N=2e5+5;
i64 fac[N],invfac[N];
i64 qp(i64 a,i64 b,i64 p)
{
    i64 ans=1;
    a%=p;
    while(b)
    {
        if(b&1)ans=(ans*a)%p;
        a=a*a%p;
        b>>=1;
    }
    return ans;
}
i64 inv(i64 x,i64 p){return qp(x,p-2,p);}
i64 C(i64 n,i64 m,i64 p)
{
    if(n < m || m < 0) return 0;
	return fac[n] * invfac[m] % p * invfac[n - m] % p;
}
i64 lucas(i64 n,i64 m,i64 p)
{
    if(!m)return 1;
    return lucas(n/p,m/p,p)*C(n%p,m%p,p)%p;
}
void work()
{
    i64 n,m,p;  
    cin>>n>>m>>p;
    fac[0]=1;
    for(int i=1;i<p;++i)
    fac[i]=fac[i-1]*i%p;
    invfac[p-1]=inv(fac[p-1],p);
    for(int i=p-2;i>=0;--i)
    invfac[i]=invfac[i+1]*(i+1)%p;
    cout<<lucas(n+m,n,p)<<'\n';
}
int main() {
ios::sync_with_stdio(0);
cin.tie(0);
int t=1;
cin >> t;
while(t--)
work();
}