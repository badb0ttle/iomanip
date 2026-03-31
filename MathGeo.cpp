/*ordinary.exe*/
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
const int N = 1e3 + 10;
const int mod = 1e9 + 7;
typedef pair<int, int> PII;

//--------------------------------------------------------------
const double eps = 1e-9;
const double pi = acos(-1);
inline double sqr(double x) { return x * x; } // 平方
int sign(double x)
{
	if (fabs(x) < eps)
		return 0;
	if (x > 0)
		return 1;
	return -1;
} // 符号
struct point
{
	double x, y;
	point() {}
	point(double a, double b) : x(a), y(b) {}
	friend point operator+(const point &a, const point &b)
	{
		return point(a.x + b.x, a.y + b.y);
	}
	friend point operator-(const point &a, const point &b)
	{
		return point(a.x - b.x, a.y - b.y);
	}
	friend bool operator==(const point &a, const point &b)
	{
		return !sign(a.x - b.x) && !sign(a.y - b.y);
	}
	friend point operator*(const point &a, const double &b)
	{
		return point(a.x * b, a.y * b);
	}
	friend point operator*(const double &a, const point &b)
	{
		return point(a * b.x, a * b.y);
	}
	friend point operator/(const point &a, const double &b)
	{
		return point(a.x / b, a.y / b);
	}
	// 向量模长
	double norm()
	{
		return sqrt(sqr(x) + sqr(y));
	}
};

struct line
{
	point a, b;
	line() {}
	line(point x, point y) : a(x), b(y) {}
};

double det(const point &a, const point &b)
{
	return a.x * b.y - a.y * b.x;
} // 叉积 判断两点共线 ,绝对值等于两个向量所构成的平行四边形面积

double dot(const point &a, const point &b)
{
	return a.x * b.x + a.y * b.y;
} // 点积

double dist(const point &a, const point &b)
{
	return (a - b).norm();
} // 两点距离

point rotate_point(const point &a, const point &p, double A)
{
	double tx = p.x - a.x, ty = p.y - a.y;
	return point(a.x + tx * cos(A) - ty * sin(A), a.y + tx * sin(A) + ty * cos(A));
} // p 点 绕 a 点逆时针旋转 A 弧度

int toleft(const point &p, const point &a, const point &b)
{
	return sign(det(b - a, p - a));
	// 1 左 0 上 -1 右
} // 只适用凸多边形

// 判断点 p 是否在线段 st 上(包括端点)
bool point_on_segment(point p, point s, point t)
{
	return sign(det(p - s, t - s)) == 0 && sign(dot(p - s, p - t)) <= 0;
}

bool parallel(line a, line b)
{
	return !sign(det(a.a - a.b, b.a - b.b));
} // 判断两个直线是否平
bool line_make_point(line a, line b, point &res)
{
	if (parallel(a, b))
		return 0;
	double s1 = det(a.a - b.a, b.b - b.a);
	double s2 = det(a.b - b.a, b.b - b.a);
	res = (s1 * a.b - s2 * a.a) / (s1 - s2);
	return 1;
} //
int n, m;
struct node
{
	double x, y, dis;
};
vector<node> ans[N];
void work()
{
	cin >> n >> m;
	double xs, ys, xt, yt;
	cout << fixed << setprecision(10);
	cin >> xs >> ys >> xt >> yt;
	point s, t;
	s = {xs, ys}, t = {xt, yt};
	line l = {s, t};
	vector<point> p(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> p[i].x >> p[i].y;
	point now;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = i + 1; j <= n; ++j)
		{
			auto p1 = p[i];
			auto p2 = p[j];
			if (toleft(s, p1, p2) * toleft(t, p1, p2) > 0)
				continue;
			line r = {p1, p2};
			line_make_point(l, r, now);
			ans[i].emplace_back(now.x, now.y, dist(now, s));
			ans[j].emplace_back(now.x, now.y, dist(now, s));
		}
	}
	int h, k;
	for (int i = 1; i <= n; ++i)
		sort(ans[i].begin(), ans[i].end(),
			 [&](node a, node b)
			 { return a.dis < b.dis; });
	for (int i = 1; i <= m; ++i)
	{
		cin >> h >> k;
		if (ans[h].size() < k)
			cout << "-1\n";
		else cout << ans[h][k - 1].x << ' ' << ans[h][k - 1].y << '\n';
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