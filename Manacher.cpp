/*blank*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long // 一时偷懒不收敛，乱开ll终遭谴
#define ull unsigned long long 
#define sc scanf
#define pr printf
#define PII pair<int, int>
#define debug(x) cout << #x << '=' << x << '\n'
const int N = 2e7 + 9;
char s[N];
int n,p[N];//求一个字符串最长回文子串长度or查询
void work()
{
    cin >> n;
    cin>>s+1;
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
        if(p[i]+i>R)
        {
            C=i;
            R=i+p[i];
        }
    }
    for(int i=1;i<=2*n+1;++i)
    {
        ans=max(ans,p[i]-1);
    }
    cout<<ans<<'\n';
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