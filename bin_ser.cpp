/*blank*/
#include <bits/stdc++.h>

using i64 = long long;
const int N=2e5+10;
int a[N];
void work()
{
    int n,q;
	std::cin>>n>>q;
	for(int i=1;i<=n;i++)std::cin>>a[i];
	while(q--)
	{
		int x;std::cin>>x;
		int l=0,r=n;
		while(l+1!=r)
		{
			int mid=(l+r)>>1;
			if(a[mid]<x)l=mid;
			else r=mid;
		}
		if(a[r]==x)std::cout<<r<<' ';
		else std::cout<<-1<<' ';
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