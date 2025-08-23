/*blank*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long // 一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
#define pair <int, int> PII
#define debug(x) cout << #x << '=' << x << '\n'

void work()
{
    string s = "123";
    cout << regex_match(s, regex("\\d+")) << '\n';
    string s1 = "123_Abc";
    smatch m;
    regex pattern("(\\d+)_(.{3})");
    regex_match(s1, m, pattern);
    for (int i = 0; i < m.size(); ++i)
    {
        cout << m[i] << '\n';
        string s2 = "";
    }
    cout << regex_match(s1, regex("123_abc", regex::icase)) << '\n';
    cout << regex_match(s1, regex("123_abc")) << '\n';

    int a[4];
    string ss = "123 456 789 110";
    smatch res;
    regex pattern1("(\\d+)");
    int idx = 0;
    string tmp;
    string::const_iterator iterStart = ss.begin();
    string::const_iterator iterEnd = ss.end();
    while (regex_search(iterStart, iterEnd, res, pattern1))
    {
        a[idx] = stoi(res[0]);
        idx++;
        iterStart = res[0].second;
    }

    for (int i : a)
        cout << i << ' ' << '\n';

    string str = "HEHE_2020";
    regex pattern2("(.{2})(.{2})_(\\d{4})");
    cout << regex_replace(str, pattern2, "$1$3_$2") << '\n';
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