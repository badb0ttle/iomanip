/*ordinary.exe*/
#include <bits/stdc++.h>
using namespace std;
using i64=long long;
using u64=unsigned long long;
i64 mo(i64 x,i64 p){return (x%p+p)%p;}
i64 exgcd(i64 a,i64 b,i64&x,i64&y)
{
    if(!b)return x=1,y=0,a;
    i64 d = exgcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}
void work()
{
    i64 a,b,c;cin>>a>>b>>c;
    i64 x,y,d=exgcd(a<0?-a:a,b<0?-b:b,x,y);
    if(c%d)return void(cout<<"-1\n");
    if(a<0)x=-x;
    x=mo(x*(c/d),b/d);
    cout<<x<<'\n';
}
int main() {
ios::sync_with_stdio(0);
cin.tie(0);
int t=1;
// cin >> t;
while(t--)
work();
}