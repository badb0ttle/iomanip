/*blank*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long//一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
#define PII pair<int,int>
#define debug(x) cout<<#x<<'='<<x<<'\n'
const int mx=1e6+9;
char s[mx],t[mx];
int nex[mx];
void work()
{
    cin>>s+1>>t+1;
    int n=strlen(s+1),m=strlen(t+1);
    s[n+1]='#',t[m+1]='$';
    //getnex
    nex[1]=0;
    for(int i=2,j=0;i<=m;++i)
    {
        while(j&&t[i]!=t[j+1])j=nex[j];
        if(t[i]==t[j+1])j++;
        nex[i]=j;
    }
    for(int i=1,j=0;i<=n;++i)
    {
        while(j&&t[j+1]!=s[i])j=nex[j];
        if(t[j+1]==s[i])j++;
        if(j==m)
        {
            cout<<i-j+1<<' ';
        }
    }
    cout<<'\n';
    for(int i=1;i<=m;++i)cout<<nex[i]<<' ';
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