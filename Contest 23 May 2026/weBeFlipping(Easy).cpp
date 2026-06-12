#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        vector<array<long long, 2>> dp(n + 1);
        vector<array<int, 2>> take(n + 1);
        dp[0][0] = dp[0][1] = 0;
        for (int i = 1; i <= n; i++) {
            for (int p = 0; p < 2; p++) {
                dp[i][p] = (long long)4e18;
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int p = 0; p < 2; p++) {
                long long cur;
                if (p == 0) cur = a[i];
                else cur = -a[i];
                long long val = dp[i - 1][p] + cur;
                if (val < dp[i][p]) {
                    dp[i][p] = val;
                    take[i][p] = 0;
                }
                if (cur > 0) {
                    val = dp[i - 1][p ^ 1] - cur;

                    if (val < dp[i][p]) {
                        dp[i][p] = val;
                        take[i][p] = 1;
                    }
                }
            }
        }
        int p;
        if (dp[n][0] <= dp[n][1]) p = 0;
        else p = 1;
        vector<int> ops;
        for (int i = n; i >= 1; i--) {
            if (take[i][p]) {
                ops.push_back(i);
                p ^= 1;
            }
        }
        cout << ops.size() << "\n";
        for (int i = 0; i < (int)ops.size(); i++) {
            if (i) cout << ' ';
            cout << ops[i];
        }
        cout << "\n";
    }
    return 0;
}