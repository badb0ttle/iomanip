/*ordinary.exe*/
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
// 判断闰年
bool isLeap(int y)
{
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
    // xujc
    //  return (y % 400 == 0 && y % 3200 != 0) || (y % 4 == 0 && y % 100 != 0);
}
// 每月天数
int mdays[13][2] = {
    {0, 0}, {31, 31}, {28, 29}, {31, 31}, {30, 30}, {31, 31}, {30, 30}, {31, 31}, {31, 31}, {30, 30}, {31, 31}, {30, 30}, {31, 31}};
// 计算从公元0年1月1日到y:m:d的总天数
int dateToDays(int y, int m, int d)
{
    int days = 0;
    for (int i = 1; i < y; ++i)
        days += isLeap(i) ? 366 : 365;
    for (int i = 1; i < m; ++i)
        days += mdays[i][isLeap(y)];
    days += d;
    return days;
}
// 从天数推日期
void daysToDate(int total, int &y, int &m, int &d)
{
    y = 1;
    while (true)
    {
        int dy = isLeap(y) ? 366 : 365;
        if (total > dy)
            total -= dy, ++y;
        else
            break;
    }
    m = 1;
    while (1)
    {
        int dm = mdays[m][isLeap(y)];
        if (total > dm)
            total -= dm, ++m;
        else
            break;
    }
    d = total;
}
// 格式化输出 yyyy:mm:dd（补零）
string fmt(int x, int len = 2)
{
    string s = to_string(x);
    while ((int)s.size() < len)
        s = "0" + s;
    return s;
}

void work()
{
    string s1, s2;
    cin >> s1 >> s2;
    if (s2.find(':') != string::npos)
    {
        //计算两日期之间天数差
        int y1, m1, d1, y2, m2, d2;
        sscanf(s1.c_str(), "%d:%d:%d", &y1, &m1, &d1);
        sscanf(s2.c_str(), "%d:%d:%d", &y2, &m2, &d2);
        int ans = abs(dateToDays(y1, m1, d1) - dateToDays(y2, m2, d2));
        cout << ans << "\n";
    }
    else
    {
        //加上天数后求新日期
        int day = stoi(s2);
        int y, m, d;
        sscanf(s1.c_str(), "%d:%d:%d", &y, &m, &d);
        int total = dateToDays(y, m, d) + day;
        int Y, M, D;
        daysToDate(total, Y, M, D);
        cout << fmt(Y, 4) << ":" << fmt(M, 2) << ":" << fmt(D, 2) << "\n";
    }
}
int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        work();
}