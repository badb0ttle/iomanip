#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 5e5 + 5;
// 数组和常量声明
struct node
{
    int val;                  // 当前节点数量
    node *ch[26] = {nullptr}; // 子节点编号 a / z
}; 
void del(node *cur)
{
    for (int i = 0; i < 26; ++i)
        if (cur->ch[i] != nullptr)
            del(cur->ch[i]);
    delete cur;
}
vector<int> getdiv(int x)
{
    vector<int> ans;
    for (int i = 1; i * i <= x; ++i)
    {
        if (x % i == 0)
        {
            ans.push_back(i);
            if (i * i != x)
                ans.push_back(x / i);
        }
    }
    return ans;
}
void solve()
{
    int n;
    cin >> n;
    vector<i64> term(n + 1,0LL);//处理当前状态的总评分
    node *root = new node();
    i64 ans = 0;
    int cur_i=0;
    for (int i = 1; i <= n; ++i)
    {
        string s;
        cin >> s;
        node *cur = root;
        for (auto &ch : s)
        {
            int c = ch - 'a';
            if (cur->ch[c] == nullptr)
                cur->ch[c] = new node();
            cur = cur->ch[c];
            cur->val=cur->val+1;
            vector<int> dv = getdiv(cur->val);
            for (auto &d : dv)
            {
                if (d > n)  
                    continue;
                i64 pas = term[d];
                term[d] +=(i64) d;
                if (d <= cur_i)
                    ans ^= (pas^term[d] );
            }
        }
        ans ^= term[i];
        cout << ans << " \n"[i ==n];
        cur_i=i;
    }
    del(root);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); 
    int t;
    cin >> t;
    while (t--)
        solve();
}