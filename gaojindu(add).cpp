/*blank*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long//一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
string add(string a,string b)
{
    bool f;
    string ans;
    if(a.size()<b.size())swap(a,b);
    while(a.size()<b.size())a='0'+a;
    while(b.size()<a.size())b='0'+b;
    for(int i=a.size()-1;i>=0;--i)
    {
        int t=a[i]-'0'+b[i]-'0'+f;
        f=t/10;
        ans=char(t%10+'0')+ans;
    }
    if(f)ans='1'+ans;
    return ans;
}
void work()
{
    cout<<add("1234","5678");
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