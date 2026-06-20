#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        sort(a.begin(), a.end());

        int odd = 0;
        int sz = 1;

        for (int i = 1; i < n; i++) {
            if (a[i] - a[i - 1] <= k) {
                sz++;
            } else {
                if (sz & 1) odd++;
                sz = 1;
            }
        }

        if (sz & 1) odd++;

        cout << (odd <= 1 ? "YES" : "NO") << '\n';
    }
}