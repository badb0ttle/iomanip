/*ordinary.exe*/
#include <bits/stdc++.h>
using namespace std;
using i64=long long;
using u64=unsigned long long;
/*归并排序
void merge(i64 a[], i64 l, i64 r)
{
    if (r - l < 1)
        return;
    i64 mid = (l + r) >> 1;
    merge(a, l, mid);
    merge(a, mid + 1, r);
    i64 i = l, j = mid + 1;
    for (i64 k = l; k <= r; k++)
    {
        if (j > r || i <= mid && a[i] <= a[j])
            b[k] = a[i++];
        else
            cnt += mid - i + 1,b[k] = a[j++];
    }
    for (i64 k = l; k <= r; k++)
        a[k] = b[k];
}
*/
void work()
{
    
}
int main() {
ios::sync_with_stdio(0);
cin.tie(0);
int t=1;
cin >> t;
while(t--)
work();
}