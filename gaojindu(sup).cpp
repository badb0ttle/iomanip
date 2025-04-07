/*blank*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long // 一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
#define MAXN 9999     // 数组中的单个元素最多存储DLEN位
#define MAXSIZE 10000 // 大数的长度为MAXSIZE*MAXN
#define DLEN 4        // 数组中的单个元素最多存储DLEN位

class BigNum
{
private:
    bool flag;      // 判断大数是否有负号，有负号为true
    int a[MAXSIZE]; // 可以控制大数的位数
    int len;        // 大数长度,注意这里单位长度是四
public:
    BigNum()
    {
        len = 1;
        memset(a, 0, sizeof(a));
        flag = true;
    }                                  // 构造函数
    BigNum(const int);                 // 将一个int类型的变量转化为大数
    BigNum(const char *);              // 将一个字符串类型的变量转化为大数
    BigNum(const string);              // 将一个字符串类型的变量转化为大数
    BigNum(const BigNum &);            // 拷贝构造函数
    BigNum &operator=(const BigNum &); // 重载赋值运算符，大数之间进行赋值运算

    friend istream &operator>>(istream &, BigNum &); // 重载输入运算符
    friend ostream &operator<<(ostream &, BigNum &); // 重载输出运算符

    BigNum operator+(const BigNum &) const; // 重载加法运算符，两个大数之间的相加运算
    BigNum operator-(const BigNum &) const; // 重载减法运算符，两个大数之间的相减运算
    BigNum operator*(const BigNum &) const; // 重载乘法运算符，两个大数之间的相乘运算
    BigNum operator/(const int &) const;    // 重载除法运算符，大数对一个整数进行相除运算

    BigNum operator^(const int &) const; // 大数的n次方运算
    int operator%(const int &) const;    // 大数对一个int类型的变量进行取模运算
    friend int cmp(BigNum a, BigNum b);
    bool operator>(const BigNum &T) const;  // 大数和另一个大数的大小比较
    bool operator>=(const BigNum &T) const; // 大数和另一个大数的大小比较
    bool operator<(const BigNum &T) const;  // 大数和另一个大数的大小比较
    bool operator<=(const BigNum &T) const; // 大数和另一个大数的大小比较
    bool operator==(const BigNum &T) const; // 大数和另一个大数的大小比较

    void print();  // 输出大数
    void getter(); // test
};
BigNum::BigNum(const int b) // 将一个int类型的变量转化为大数
{
    int c, d = b;
    len = 0;
    memset(a, 0, sizeof(a));
    if (d < 0)
    {
        flag = true;
        d = -d;
    }
    else
        flag = false;
    while (d > MAXN)
    {
        c = d - (d / (MAXN + 1)) * (MAXN + 1);
        d = d / (MAXN + 1);
        a[len++] = c;
    }
    a[len++] = d;
}
BigNum::BigNum(const char *s) // 将一个字符串类型的变量转化为大数
{
    int t, k, index, l;
    memset(a, 0, sizeof(a));
    if (s[0] == '-')
    {
        flag = true;
    }
    else
        flag = false;
    l = strlen(s);
    len = (l - flag) / DLEN;
    if ((l - flag) % DLEN)
    {
        len++;
    }
    index = 0;
    for (int i = l - 1; i >= 0; i -= DLEN)
    {
        t = 0;
        k = i - DLEN + 1;
        if (k <= 0)
            k = (i <= DLEN && flag ? 1 : 0);
        for (int j = k; j <= i; j++)
            t = t * 10 + s[j] - '0';
        a[index++] = t;
    }
}
BigNum::BigNum(const string s)
{ // 将一个字符串类型的变量转化为大数
    int t, k, index, l;
    memset(a, 0, sizeof(a));
    if (s[0] == '-')
    {
        flag = true;
    }
    else
        flag = false;
    l = s.size();
    len = (l - flag) / DLEN;
    if ((l - flag) % DLEN)
        len++;
    index = 0;
    for (int i = l - 1; i >= 0; i -= DLEN)
    {
        t = 0;
        k = i - DLEN + 1;
        if (k <= 0)
        {
            k = (i <= DLEN && flag ? 1 : 0);
        }
        for (int j = k; j <= i; j++)
        {
            t = t * 10 + s[j] - '0';
        }
        a[index++] = t;
    }
}
BigNum::BigNum(const BigNum &T) : len(T.len), flag(T.flag)
{ // 拷贝构造函数
    int i;
    memset(a, 0, sizeof(a));
    for (i = 0; i < len; i++)
        a[i] = T.a[i];
}
BigNum &BigNum::operator=(const BigNum &T)
{ // 重载赋值运算符，大数之间进行赋值运算
    int i;
    len = T.len;
    flag = T.flag;
    memset(a, 0, sizeof(a));
    for (i = 0; i < len; i++)
        a[i] = T.a[i];
    return *this;
}
istream &operator>>(istream &in, BigNum &T)
{ // 重载输入运算
    char ch[MAXSIZE * DLEN];
    int index, t, k;
    in >> ch;
    if (ch[0] == '-')
    {
        T.flag = true;
    }
    else
        T.flag = false;
    int l = strlen(ch);
    T.len = (l - T.flag) / DLEN;
    if ((l - T.flag) % DLEN) // 是DLEN的倍数
        T.len++;
    index = 0;
    for (int i = l - 1; i >= 0; i -= DLEN)
    {
        t = 0;
        k = i - DLEN + 1;
        if (k <= 0)
        {
            k = (i <= DLEN && T.flag ? 1 : 0);
        }
        for (int j = k; j <= i; j++)
        {
            t = t * 10 + ch[j] - '0';
        }
        T.a[index++] = t;
    }
    return in;
}
ostream &operator<<(ostream &out, BigNum &b)
{ // 重载输出运算符
    int i;
    if (b.flag)
    {
        cout << "-";
    }
    cout << b.a[b.len - 1];
    for (i = b.len - 2; i >= 0; i--)
    {
        cout.width(DLEN);
        cout.fill('0');
        cout << b.a[i];
    }
    return out;
}

BigNum BigNum::operator+(const BigNum &T) const
{ // 两个大数之间的相加运算
    BigNum t(*this);
    int i, big; // 位数
    if (!flag && T.flag)
    {
        return T - t;
    }
    else if (flag && !T.flag)
    {
        return t - T;
    }
    big = T.len > len ? T.len : len;
    for (i = 0; i < big; i++)
    {
        t.a[i] += T.a[i];
        if (t.a[i] > MAXN)
        {
            t.a[i + 1]++;
            t.a[i] -= MAXN + 1;
        }
    }
    if (t.a[big] != 0)
        t.len = big + 1;
    else
        t.len = big;
    return t;
}
BigNum BigNum::operator-(const BigNum &T) const
{ // 两个大数之间的相减运算
    int i, j, big;
    bool flag;
    BigNum t1, t2;
    if (this->flag && !T.flag)
    { // 左负右正
        t1 = T;
        t1.flag = true;
        return *this + t1;
    }
    if (!this->flag && T.flag)
    { // 左正右负
        t1 = T;
        t1.flag = false;
        return *this + t1;
    }
    if (*this >= T && !this->flag && !T.flag || this->flag && T.flag && *this < T)
    {
        t1 = *this;
        t2 = T;
        flag = T.flag;
    }
    else
    {
        t1 = T;
        t2 = *this;
        flag = !T.flag;
    }
    big = t1.len;
    for (i = 0; i < big; i++)
    {
        if (t1.a[i] < t2.a[i])
        {
            j = i + 1;
            while (t1.a[j] == 0)
                j++;
            t1.a[j--]--;
            while (j > i)
                t1.a[j--] += MAXN;
            t1.a[i] += MAXN + 1 - t2.a[i];
        }
        else
            t1.a[i] -= t2.a[i];
    }
    t1.len = big;
    while (t1.a[len - 1] == 0 && t1.len > 1)
    {
        t1.len--;
        big--;
    }
    t1.flag = flag;
    return t1;
}

BigNum BigNum::operator*(const BigNum &T) const
{ // 两个大数之间的相乘运算
    BigNum ret;
    if (flag && T.flag || !flag && !T.flag)
    {
        ret.flag = false;
    }
    else
        ret.flag = true;
    int i, j, up;
    int temp, temp1;
    for (i = 0; i < len; i++)
    {
        up = 0;
        for (j = 0; j < T.len; j++)
        {
            temp = a[i] * T.a[j] + ret.a[i + j] + up;
            if (temp > MAXN)
            {
                temp1 = temp - temp / (MAXN + 1) * (MAXN + 1);
                up = temp / (MAXN + 1);
                ret.a[i + j] = temp1;
            }
            else
            {
                up = 0;
                ret.a[i + j] = temp;
            }
        }
        if (up != 0)
            ret.a[i + j] = up;
    }
    ret.len = i + j;
    while (ret.a[ret.len - 1] == 0 && ret.len > 1)
        ret.len--;
    return ret;
}
BigNum BigNum::operator/(const int &b) const
{ // 大数对一个整数进行相除运算
    BigNum ret;
    int d = abs(b);
    if (flag && b < 0 || !flag && b > 0)
    {
        ret.flag = false;
    }
    else
        ret.flag = true;
    int i, down = 0;
    for (i = len - 1; i >= 0; i--)
    {
        ret.a[i] = (a[i] + down * (MAXN + 1)) / d;
        down = a[i] + down * (MAXN + 1) - ret.a[i] * d;
    }
    ret.len = len;
    while (ret.a[ret.len - 1] == 0 && ret.len > 1)
        ret.len--;
    if (ret.len == 1 && ret.a[0] == 0)
    {
        return 0;
    }
    return ret;
}
int BigNum::operator%(const int &b) const
{ // 大数对一个int类型的变量进行取模运算
    int i, d = 0;
    for (i = len - 1; i >= 0; i--)
    {
        d = ((d * (MAXN + 1)) % b + a[i]) % b;
    }
    if (this->flag)
    {
        d = -d;
    }
    return d;
}
BigNum BigNum::operator^(const int &n) const // 大数的n次方运算,仅支持n为正数
{
    BigNum t, ret(1);
    int i;
    if (n < 0)
        exit(-1);
    if (n == 0)
        return 1;
    if (n == 1)
        return *this;
    int m = n;
    while (m > 1)
    {
        t = *this;
        for (i = 1; i << 1 <= m; i <<= 1)
        {
            t = t * t;
        }
        m -= i;
        ret = ret * t;
        if (m == 1)
            ret = ret * (*this);
    }
    if (this->flag && (n & 1))
    {
        ret.flag = true;
    }
    else
        ret.flag = false;
    return ret;
}
int cmp(BigNum a, BigNum b)
{ // 0表示a>b 1表示a<b 2表示a==b
    if (a.flag && !b.flag)
    { // a负b正
        return true;
    }
    if (!a.flag && b.flag)
    { // a正b负
        return false;
    }
    if (a.flag)
    { // 皆正
        if (a.len < b.len)
            return false;
        if (a.len > b.len)
            return true;
        for (int i = a.len; i >= 0; i--)
        {
            if (a.a[i] < b.a[i])
                return false;
            if (a.a[i] > b.a[i])
                return true;
        }
        return 2;
    }
    else
    { // 皆负
        if (a.len < b.len)
            return true;
        if (a.len > b.len)
            return false;
        for (int i = a.len; i >= 0; i--)
        {
            if (a.a[i] < b.a[i])
                return true;
            if (a.a[i] > b.a[i])
                return false;
        }
        return 2;
    }
}
bool BigNum::operator>(const BigNum &T) const
{ // 大数和另一个大数的大小比较
    int t = cmp(*this, T);
    return t == 0;
}
bool BigNum::operator>=(const BigNum &T) const
{ // 大数和另一个大数的大小比较
    int t = cmp(*this, T);
    return t == 0 || t == 2;
}
bool BigNum::operator<(const BigNum &T) const
{ // 大数和另一个大数的大小比较
    int t = cmp(*this, T);
    return t == 1;
}
bool BigNum::operator<=(const BigNum &T) const
{ // 大数和另一个大数的大小比较
    int t = cmp(*this, T);
    return t == 1 || t == 2;
}
bool BigNum::operator==(const BigNum &T) const
{ // 大数和另一个大数的大小比较
    int t = cmp(*this, T);
    return t == 2;
}

void BigNum::print()
{ // 输出大数
    int i;
    if (flag)
    {
        cout << "-";
    }
    // cout << a[len - 1];
    pr("%d", a[len - 1]);
    for (i = len - 2; i >= 0; i--)
    {
        /*cout.width(DLEN);
        cout.fill('0');
        cout << a[i];*/
        pr("%04d", a[i]);
    }
    // cout << '\n';
    pr("\n");
}
void BigNum::getter()
{ // test
    cout << len << " " << flag << '\n';
}
void work()
{
}
int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int _ = 1;
    // cin >> _;
    // sc("%d",&_);
    while (_--)
        work();
    return 0;
}