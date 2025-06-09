/*blank*/
#include <bits/stdc++.h>

using i64 = long long;
struct Node
{
    int a, b;
    // 小于号，默认升序排序
    bool operator<(const Node &other) const
    {
        return a < other.a;
    }
    // 大于号，降序排序用
    bool operator>(const Node &other) const
    {
        return a > other.a;
    }
    // 等于号
    bool operator==(const Node &other) const
    {
        return a == other.a && b == other.b;
    }
    // 不等于号
    bool operator!=(const Node &other) const
    {
        return !(*this == other);
    }
    // 加法
    Node operator+(const Node &other) const
    {
        return {a + other.a, b + other.b};
    }
    // 减法
    Node operator-(const Node &other) const
    {
        return {a - other.a, b - other.b};
    }
    // 输出流（调试超好用）
    friend std::ostream &operator<<(std::ostream &os, const Node &node)
    {
        return os << "(" << node.a << ", " << node.b << ")";
    }
};
void work()
{
     Node x = {3, 5}, y = {2, 7};
    // 比较
    std::cout << (x < y) << '\n';
    std::cout << (x == y) << '\n';
    // 加减
    Node z = x + y;
    std::cout << z << '\n';
    // 排序
    std::vector<Node> v = {{3, 5}, {2, 7}, {8, 1}};
    std::sort(v.begin(), v.end()); // 默认按 a 升序
    for (auto& i : v) std::cout << i << " ";
    std::cout << '\n';
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int _ = 1;
    // std::cin>>_;
    while (_--)
        work();
    return 0;
}