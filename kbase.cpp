/*blank*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long//一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
ll trK_10(string s,int k)
{
    ll res=0;
    ll a=1;
    for(int i=s.size()-1;i>=0;--i)
    {
        if(s[i]>='0'&&s[i]<='9')res+=(s[i]-'0')*a;
        else res+=(s[i]-'A'+10)*a;
        a*=k;
    }
    return res;
}
string tr10_k(ll num,int k)
{
    if (num == 0)
        return "0"; 
    string res;
    while(num)
    {
        int tmp=num%k;
        if(tmp<10)res=char(tmp+'0')+res;
        else res=char(tmp-10+'A')+res;
        num/=k;
    }
    return res;
}
void work()
{
    cout<<trK_10("101",2);
    cout<<tr10_k(5,2);
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