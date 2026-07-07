#include <bits/stdC++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 1e9;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            long long n;
            int k;
            cin >> n >> k;
            int target = k - 1;
            vector<int> weights;
            for (int h = 1; h <= 18 && h <= n; ++h) {
                weights.push_back((1 << h) - 1);
            }
            vector<int> dp(target + 1, INF);
            dp[0] = 0;
            for (int w : weights) {
                for (int i = w; i <= target; ++i) {
                    if (dp[i - w] != INF) {
                        dp[i] = min(dp[i], dp[i - w] + 1);
                    }
                }
            }
            if (dp[target] == INF) {
                cout << 0 << "\n";
                return;
            }
            vector<long long> cnt(target + 1, 0);
            cnt[0] = 1;
            for (int i = 1; i <= target; ++i) {
                for (int w : weights) {
                    if (i == w && dp[i] == 1) {
                        cnt[i] = (cnt[i] + 1) % MOD;
                    }
                }
                for (int L = 0; L < i; ++L) {
                    int R = i - 1 - L;
                    if (dp[L] != INF && dp[R] != INF && dp[L] + dp[R] == dp[i]) {
                        long long ways = (cnt[L] * cnt[R]) % MOD;
                        cnt[i] = (cnt[i] + ways) % MOD;
                    }
                }
            }
            cout << cnt[target] << "\n";
        }
    }
    return 0;
}