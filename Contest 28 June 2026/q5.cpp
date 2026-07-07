#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -INF));
        dp[0][0] = 0;
        for (int i = 0; i < n; ++i) {
            vector<vector<int>> nextDp(n + 2, vector<int>(n + 2, -INF));
            vector<int> choices;
            if (s[i] == 'T') choices.push_back(-1);
            else if (s[i] == 'F') choices.push_back(1);
            else {
                choices.push_back(-1);
                choices.push_back(1);
            }
            for (int choice : choices) {
                int f_cost = (choice == 1) ? 1 : 0;
                for (int cur = 0; cur <= i; ++cur) {
                    for (int mx = cur; mx <= i; ++mx) {
                        if (dp[cur][mx] == -INF) continue;
                        int ncur = max(0, cur + choice);
                        int nmx = max(mx, ncur);
                        nextDp[ncur][nmx] = max(nextDp[ncur][nmx], dp[cur][mx] + f_cost);
                    }
                }
            }
            dp = move(nextDp);
        }
        int maxMist = 0;
        for (int cur = 0; cur <= n; ++cur) {
            for (int mx = cur; mx <= n; ++mx) {
                if (dp[cur][mx] != -INF) {
                    maxMist = max(maxMist, dp[cur][mx] - mx);
                }
            }
        }
        cout << maxMist << "\n";
    }
    return 0;
}