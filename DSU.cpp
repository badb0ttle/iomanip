/*blank*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long//一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
const int mx=2e5+1;
ll pre[mx];
int root(int v)
{
    return pre[v]=(pre[v]==v?v:root(pre[v]));
}
void merge(int a,int b)
{
    pre[root(a)]=root(b);
}
bool same(int a,int b)
{   
    return root(a)==root(b);
}
void work()
{
    
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