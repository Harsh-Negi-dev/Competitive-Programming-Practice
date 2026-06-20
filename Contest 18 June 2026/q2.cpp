#include <bits/stdc++.h>
using namespace std;

struct BIT {
    int n;
    vector<long long> bit;

    BIT(int n) : n(n), bit(n + 1, 0) {}

    void add(int idx, int val) {
        idx++;
        while (idx <= n) {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    long long sum(int idx) {
        idx++;
        long long res = 0;

        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n);

        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        vector<vector<int>> start(n);
        bool ok = true;

        for (int i = 0; i < n; i++) {
            int pos = lower_bound(b.begin(), b.end(), a[i]) - b.begin();

            if (pos == n) {
                ok = false;
                break;
            }

            start[pos].push_back(i);
        }

        if (!ok) {
            cout << -1 << '\n';
            continue;
        }

        priority_queue<int, vector<int>, greater<int>> pq;
        vector<int> c;

        for (int j = 0; j < n; j++) {
            for (int idx : start[j])
                pq.push(idx);

            if (pq.empty()) {
                ok = false;
                break;
            }

            c.push_back(pq.top());
            pq.pop();
        }

        if (!ok) {
            cout << -1 << '\n';
            continue;
        }

        long long inv = 0;
        BIT bit(n);

        for (int i = n - 1; i >= 0; i--) {
            inv += bit.sum(c[i] - 1);
            bit.add(c[i], 1);
        }

        cout << inv << '\n';
    }

    return 0;
}