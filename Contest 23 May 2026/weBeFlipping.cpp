#include<bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<long long> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        long long NEG = -(long long)4e18;
        vector<array<long long,2>> dp(n + 2);
        vector<array<int,2>> nxt(n + 2);
        dp[n + 1][0] = 0;
        dp[n + 1][1] = NEG;
        for (int i = n; i >= 1; i--) {
            for (int p = 0; p < 2; p++) {
                dp[i][p] = NEG;
                long long add;
                if (p == 0) {
                    add = a[i];
                } else {
                    add = -a[i];
                }
                for (int q = 0; q < 2; q++) {
                    if (dp[i + 1][q] == NEG) {
                        continue;
                    }
                    bool ok = true;
                    if (p != q) {
                        long long cur;
                        if (q == 0) {
                            cur = a[i];
                        } else {
                            cur = -a[i];
                        }
                        if (cur <= 0) {
                            ok = false;
                        }
                    }
                    if (!ok) {
                        continue;
                    }
                    long long cand = add + dp[i + 1][q];
                    if (cand > dp[i][p]) {
                        dp[i][p] = cand;
                        nxt[i][p] = q;
                    }
                }
            }
        }
        int p;
        if (dp[1][0] >= dp[1][1]) {
            p = 0;
        } else {
            p = 1;
        }
        vector<int> ops;
        for (int i = 1; i <= n; i++) {
            int q = nxt[i][p];
            if (p != q) {
                ops.push_back(i);
            }
            p = q;
        }
        reverse(ops.begin(), ops.end());
        cout << ops.size() << '\n';
        for (int i = 0; i < (int)ops.size(); i++) {
            if (i) {
                cout << ' ';
            }
            cout << ops[i];
        }
        cout << '\n';
    }
    return 0;
}