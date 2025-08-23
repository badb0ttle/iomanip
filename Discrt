/*blank*/
#include <bits/stdc++.h>

using i64 = long long;
const int mx=5e5+10;
std::vector<int>X;
i64 a[mx];
struct node
{
    i64 a,b;
}add[mx],que[mx];
int getidx(int x)
{
    return std::lower_bound(X.begin(),X.end(),x)-X.begin()+1;
}
void work()
{
    int n,q;
    std::cin>>n>>q;
    for(int i=1;i<=n;++i)
    {
        int x,w;
        std::cin>>x>>w;
        X.push_back(x);
        add[i]={x,w};
    }
    for(int i=1;i<=q;++i)
    {
        i64 l,r;
        std::cin>>l>>r;
        X.push_back(l),X.push_back(r);
        que[i]={l,r};
    }
    sort(begin(X),end(X));
    X.erase(unique(begin(X),end(X)),end(X));
      for(int i=1;i<=n;++i)
    {
        int x=getidx(add[i].a);
        i64 w=add[i].b;
        a[x]+=w;
    }
    for(int i=1;i<=X.size();++i)a[i]+=a[i-1];
    for(int i=1;i<=q;++i)
    {
        int l=getidx(que[i].a);
        int r=getidx(que[i].b);
        std::cout<<a[r]-a[l-1]<<'\n';
    }
    
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int _=1;
    //std::cin>>_;
    while(_--)work();
    return 0;
}