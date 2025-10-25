/*ordinary.exe*/
#include <bits/stdc++.h>
using namespace std;
using i64=long long;
const int N=2e7+9;
string str;
char s[N];
int n,p[N];
void work()
{
    cin>>str;
    n=(int)str.size();
    for(int i=1;i<=n;++i)s[i]=str[i-1];
    for(int i=2*n+1;i>=1;--i)
    {
        if(i&1)s[i]='#';
        else s[i]=s[i>>1];
    }
    s[0]='$',s[2*n+2]='^';
    int C=0,R=0,ans=1;
    for(int i=1;i<=2*n+1;++i)
    {
        p[i]=i<R?min(R-i,p[2*C-i]):1;
        while(s[i+p[i]]==s[i-p[i]])p[i]++;
        if(p[i]+i>R){
            C=i;
            R=i+p[i];
        }
    }
    for(int i=1;i<=2*n+1;++i)
        ans=max(ans,p[i]-1);
    cout<<ans<<'\n';
}
int main() {
ios::sync_with_stdio(0);
cin.tie(0);
int t=1;
// cin >> t;
while(t--)
work();
}