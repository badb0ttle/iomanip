#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
struct node
{
    bool end=0;
    int leaves;
    node *ch[26] = {nullptr};
};
void del(node *root)
{
    for (int i = 0; i < 26; ++i)
    {
        if (root->ch[i])
            del(root->ch[i]);
    }
    delete root;
}
void insert(node *root, string s)
{
    node *cur = root;
    for (auto &c : s)
    {
        int t = c - 'a';
        if (!cur->ch[t])
            cur->ch[t] = new node();
        cur = cur->ch[t];
        cur->leaves++;
    }
    cur->end=1;
}
int querypre(node *root, string pre)//查询前缀个数
{
    node *cur = root;
    for (auto &c : pre)
    {
        int t = c - 'a';
        if (!cur->ch[t])
            return 0;
        cur = cur->ch[t];
    }
    return cur->leaves;
}
bool ser(node *root, string s)//查询单词是否存在
{
    node *cur = root;
    for (auto &c : s)
    {
        int t = c - 'a';
        if (!cur->ch[t])
            return 0;
        cur = cur->ch[t];
    }
    return cur->end;
}
void work()
{
    int n;
    cin >> n;
    node *root = new node();
    for(int i=1;i<=n;++i)
    {
        string s;
        cin>>s;
        insert(root,s);
    }
    unordered_map<string,int>mp;
    int q;cin>>q;
    while(q--)
    {
        string s;cin>>s;
        if(mp[s])
        {
            cout<<"REPEAT"<<'\n';
        }
        else if(ser(root,s))
        {
            cout<<"OK"<<'\n';
            mp[s]=1;
        }
        else 
        {
            cout<<"WRONG"<<'\n';
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        work();
}