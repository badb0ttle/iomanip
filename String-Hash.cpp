/*blank*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long//一时偷懒不收敛，乱开ll终遭谴
#define ull unsigned long long//一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
#define PII pair<int,int>
#define debug(x) cout<<#x<<'='<<x<<'\n'
const int mx=1e6+9;
const ull base=1771;
char s[mx];
ull b[mx],h[mx],hr[mx];
ull gh(int l,int r)
{
    return h[r]-h[l-1]*b[r-l+1];
}
ull ghr(int l,int r)
{
    return h[l]-h[r+1]*b[r-l+1];
}
void work()
{
    int n;
    cin>>n;
    cin>>s+1;
    b[0]=1;
    for(int i=1;i<=n;++i)
    {
        b[i]=b[i-1]*base;
        h[i]=h[i-1]*base+s[i]-'a'+1;
    }
    for(int i=n;i>=1;--i)hr[i]=hr[i+1]*base+s[i]-'a'+1;
    int q;
    cin>>q;
    while(q--)
    {
        int l,r,x,y;
        cin>>l>>r>>x>>y;
        cout<<(gh(l,r)==gh(x,y)?"YES\n":"NO\n");
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