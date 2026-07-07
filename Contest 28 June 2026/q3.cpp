#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj(n + 1);
        for (int i = 2; i <= n; ++i) {
            int p;
            cin >> p;
            adj[p].push_back(i);
        }
        vector<int> depth(n + 1, 0);
        vector<int> maxDepth(n + 1, 0);
        long long totalGuilds = n;
        auto dfs = [&](auto &self, int u, int d) -> void {
            depth[u] = d;
            maxDepth[u] = d;
            int m1 = -1, m2 = -1;
            for (int v : adj[u]) {
                self(self, v, d + 1);
                maxDepth[u] = max(maxDepth[u], maxDepth[v]);
                int md = maxDepth[v];
                if (md > m1) {
                    m2 = m1;
                    m1 = md;
                }
                else if (md > m2) {
                    m2 = md;
                }
            }
            if (m2 != -1) {
                totalGuilds += max(0, m2 - d);
            }
        };
        dfs(dfs, 1, 0);
        cout << totalGuilds << "\n";
    }
    return 0;
}