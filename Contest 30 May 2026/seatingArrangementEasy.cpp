#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n, x, s;
        cin >> n >> x >> s;

        string u;
        cin >> u;

        vector<int> dp(x + 1, -1000000000);
        dp[0] = 0;

        for (char c : u) {
            vector<int> ndp = dp; // kick this person out

            for (int eia = 0; eia <= x; eia++) {
                if (dp[eia] < 0) continue;

                int q = dp[eia];

                if (c == 'I') {
                    if (eia < x) {
                        ndp[eia + 1] = max(ndp[eia + 1], q);
                    }
                }
                else if (c == 'E') {
                    if (q < 1LL * eia * (s - 1)) {
                        ndp[eia] = max(ndp[eia], q + 1);
                    }
                }
                else { // 'A'
                    if (eia < x) {
                        ndp[eia + 1] = max(ndp[eia + 1], q);
                    }

                    if (q < 1LL * eia * (s - 1)) {
                        ndp[eia] = max(ndp[eia], q + 1);
                    }
                }
            }

            dp.swap(ndp);
        }

        int ans = 0;

        for (int m = 0; m <= x; m++) {
            if (dp[m] >= 0) {
                ans = max(ans, m + dp[m]);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}