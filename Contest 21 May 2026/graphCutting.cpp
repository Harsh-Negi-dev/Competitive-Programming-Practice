#include<bits/stdc++.h>
using namespace std;
long long main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n, d;
        cin >> n >> d;
        vector<vector<long long>> g(n);
        for (long long i = 0; i < n - 1; i++) {
            long long u, v;
            cin >> u >> v;
            u--, v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        long long D = d - 1;
        vector<vector<long long>> dist(n, vector<long long>(n, -1));
        for (long long s = 0; s < n; s++) {
            queue<long long> q;
            q.push(s);
            dist[s][s] = 0;
            while (!q.empty()) {
                long long u = q.front();
                q.pop();
                for (long long v : g[u]) {
                    if (dist[s][v] == -1) {
                        dist[s][v] = dist[s][u] + 1;
                        q.push(v);
                    }
                }
            }
        }
        long long ans = 0;
        for (long long m = 0; m < n; m++) {
            vector<vector<long long>> comps;
            for (long long it : g[m]) {
                vector<long long> cnt(D + 1, 0);
                for (long long v = 0; v < n; v++) {
                    if (v == m) continue;
                    if (dist[m][v] == dist[it][v] + 1) {
                        long long len = dist[m][v];
                        if (len <= D) cnt[len]++;
                    }
                }
                comps.push_back(move(cnt));
            }
            vector<vector<long long>> dp(4, vector<long long>(D + 1, 0));
            dp[0][0] = 1;
            for (auto &cnt : comps) {
                auto ndp = dp;
                for (long long k = 0; k < 3; k++) {
                    for (long long s = 0; s <= D; s++) {
                        if (!dp[k][s]) continue;
                        for (long long len = 1; len <= D - s; len++) {
                            if (!cnt[len]) continue;
                            ndp[k + 1][s + len] += dp[k][s] * cnt[len];
                        }
                    }
                }
                dp.swap(ndp);
            }
            ans += dp[3][D];
            vector<vector<long long>> dp2(3, vector<long long>(D + 1, 0));
            dp2[0][0] = 1;
            for (auto & cnt : comps) {
                auto ndp = dp2;
                for (long long k = 0; k < 2; k++) {
                    for (long long s = 0; s <= D; s++) {
                        if (!dp2[k][s]) continue;
                        for (long long len = 1; len <= D - s; len++) {
                            if (!cnt[len]) continue;
                            ndp[k + 1][s + len] += dp2[k][s] * cnt[len];
                        }
                    }
                }
                dp2.swap(ndp);
            }
            ans += dp2[2][D];
        }
        cout << ans << "\n";
    }
    return 0;
}