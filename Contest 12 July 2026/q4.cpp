#include <bits/stdc++.h>
using namespace std;
const int MAX_VAL = 300005;
const int K = 19;
int c[MAX_VAL];
long long dp[K][MAX_VAL];
int getC(int x) {
    if (x == 0) return 0;
    return __builtin_popcount(x) + (31 - __builtin_clz(x));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // precomputation
    for (int i = 1; i < MAX_VAL; i++) {
        c[i] = getC(i);
    }
    for (int k = 0; k < K; k++) {
        int step = 1 << k;    
        dp[k][MAX_VAL - 1] = ((MAX_VAL - 1) % step == 0) ? c[MAX_VAL - 1] : 1e15;
        for (int x = MAX_VAL - 2; x >= 1; x--) {
            dp[k][x] = 1e15;
            if (dp[k][x + 1] != 1e15) {
                dp[k][x] = dp[k][x + 1] + 1;
            }
            if (x % step == 0) {
                dp[k][x] = min(dp[k][x], (long long)c[x]);
            }
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        long long min_total_moves = 1e18;
        for (int k = 0; k < K; k++) {
            long long current_cost = 0;
            for (int i = 0; i < n; i++) {
                current_cost += dp[k][a[i]];
            }
            current_cost -= 1LL * k * (n - 1);
            min_total_moves = min(min_total_moves, current_cost);
        }
        cout << min_total_moves << "\n";
    }
    
    return 0;
}