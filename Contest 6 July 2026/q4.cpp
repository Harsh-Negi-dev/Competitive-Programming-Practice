#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        int n = a.length();
        int m = b.length();
        vector<int> pa(n + 1, 0), pb(m + 1, 0);
        for (int i = 0; i < n; i++) pa[i + 1] = (pa[i] + (a[i] - '0')) % 10;
        for (int j = 0; j < m; j++) pb[j + 1] = (pb[j] + (b[j] - '0')) % 10;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        dp[0][0] = 0;
        vector<vector<int>> best(10, vector<int>(m + 1, -1));
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (dp[i - 1][j] != -1) {
                    int diff = (pa[i - 1] - pb[j] + 10) % 10;
                    best[diff][j] = max(best[diff][j], dp[i - 1][j]);
                }
            }
            vector<int> running_max(10, -1);
            for (int j = 1; j <= m; j++) {
                int prev_q = j - 1;
                for (int d = 0; d < 10; d++) {
                    if (best[d][prev_q] != -1) {
                        running_max[d] = max(running_max[d], best[d][prev_q]);
                    }
                }
                int target_diff = (pa[i] - pb[j] + 10) % 10;
                if (running_max[target_diff] != -1) {
                    dp[i][j] = running_max[target_diff] + 1;
                }
            }
        }
        cout << dp[n][m] << "\n";
    }
    return 0;
}