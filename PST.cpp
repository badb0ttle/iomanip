#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const int N = 2e5 + 10;
int n, q, a[N], idx;
int rt[N], last[N], prePos[N];
vector<int> raw;

struct Node {
    int l, r, v;
} tr[N << 5];

int xid(int x) {
    return lower_bound(raw.begin(), raw.end(), x) - raw.begin() + 1;
}

void add(int &o, int pre, int x, int s = 1, int e = raw.size()) {
    o = ++idx;
    tr[o] = tr[pre];
    tr[o].v++;
    if (s == e) return;
    int mid = (s + e) >> 1;
    if (x <= mid)
        add(tr[o].l, tr[pre].l, x, s, mid);
    else
        add(tr[o].r, tr[pre].r, x, mid + 1, e);
}

// 查询区间第k小
int queryKth(int o, int ol, int k, int s = 1, int e = raw.size()) {
    if (s == e) return s;
    int mid = (s + e) >> 1;
    int lc = tr[tr[o].l].v - tr[tr[ol].l].v;
    if (k <= lc)
        return queryKth(tr[o].l, tr[ol].l, k, s, mid);
    else
        return queryKth(tr[o].r, tr[ol].r, k - lc, mid + 1, e);
}

// 查询区间 [l, r] 中小于等于 pos 的个数
int queryCount(int lo, int ro, int l, int r, int s = 0, int e = n) {
    if (l > r) return 0;
    if (l <= s && e <= r)
        return tr[ro].v - tr[lo].v;
    int mid = (s + e) >> 1, res = 0;
    if (mid >= l)
        res += queryCount(tr[lo].l, tr[ro].l, l, r, s, mid);
    if (mid + 1 <= r)
        res += queryCount(tr[lo].r, tr[ro].r, l, r, mid + 1, e);
    return res;
}

void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        raw.push_back(a[i]);
    }

    sort(raw.begin(), raw.end());
    raw.erase(unique(raw.begin(), raw.end()), raw.end());

    // 建树，并记录每个值上次出现的位置，方便统计区间内不同数个数
    for (int i = 1; i <= n; i++) {
        int x = xid(a[i]);
        prePos[i] = last[x];
        last[x] = i;

        add(rt[i], rt[i - 1], prePos[i]);
    }

    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            // 查询区间[l, r]不同数个数
            int l, r;
            cin >> l >> r;
            int res = queryCount(rt[l - 1], rt[r], 0, l - 1);
            cout << res << '\n';
        }
        else if (op == 2) {
            // 查询区间[l, r]第k小
            int l, r, k;
            cin >> l >> r >> k;
            int pos = queryKth(rt[r], rt[l - 1], k);
            cout << raw[pos - 1] << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int _ = 1;
    //cin >> _;
    while (_--) solve();
    return 0;
}