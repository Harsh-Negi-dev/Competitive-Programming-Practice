#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Tree {
    int n;
    vector<vector<int>> adj;
    vector<int> a;
    vector<int> depth;
    vector<vector<int>> up;
    vector<int> up_nz;
    int LOG;

    Tree(int n) : n(n) {
        adj.resize(n + 1);
        a.resize(n + 1);
        depth.resize(n + 1, 0);
        LOG = 20;
        up.assign(n + 1, vector<int>(LOG, 0));
        up_nz.assign(n + 1, 0);
    }

    void dfs(int u, int p, int last_nz) {
        up[u][0] = p;
        up_nz[u] = last_nz;
        
        for (int i = 1; i < LOG; ++i) {
            up[u][i] = up[up[u][i - 1]][i - 1];
        }
        
        int current_nz = (a[u] != 0) ? u : last_nz;
        
        for (int v : adj[u]) {
            if (v != p) {
                depth[v] = depth[u] + 1;
                dfs(v, u, current_nz);
            }
        }
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        for (int i = LOG - 1; i >= 0; --i) {
            if (depth[u] - (1 << i) >= depth[v]) {
                u = up[u][i];
            }
        }
        if (u == v) return u;
        for (int i = LOG - 1; i >= 0; --i) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }

    void solve_queries(int q) {
        depth[0] = -1; 
        dfs(1, 1, 0);
        
        while (q--) {
            int x, y;
            cin >> x >> y;
            int g = lca(x, y);
            
            vector<pair<int, int>> left_nz;
            int curr = x;
            int prev_depth = depth[x] + 1;
            
            while (curr != 0 && depth[curr] > depth[g]) {
                if (a[curr] != 0) {
                    left_nz.push_back({a[curr], prev_depth - depth[curr] - 1});
                    prev_depth = depth[curr];
                    curr = up_nz[curr];
                } else {
                    curr = up_nz[curr];
                }
            }
            int zeros_at_end_left = prev_depth - depth[g] - 1;

            vector<pair<int, int>> right_nz;
            curr = y;
            prev_depth = depth[y] + 1;
            
            while (curr != 0 && depth[curr] > depth[g]) {
                if (a[curr] != 0) {
                    right_nz.push_back({a[curr], prev_depth - depth[curr] - 1});
                    prev_depth = depth[curr];
                    curr = up_nz[curr];
                } else {
                    curr = up_nz[curr];
                }
            }
            int zeros_at_end_right = prev_depth - depth[g] - 1;

            vector<pair<int, int>> non_zero;
            for (auto& p : left_nz) {
                non_zero.push_back(p);
            }
            
            int pending_zeros = 0;
            if (a[g] != 0) {
                non_zero.push_back({a[g], zeros_at_end_left});
                pending_zeros = zeros_at_end_right;
            } else {
                pending_zeros = zeros_at_end_left + 1 + zeros_at_end_right;
            }
            
            for (int i = (int)right_nz.size() - 1; i >= 0; i--) {
                non_zero.push_back({right_nz[i].first, pending_zeros});
                pending_zeros = right_nz[i].second;
            }
            non_zero.push_back({0, pending_zeros});

            long long total_hospitable = 0;

            for (auto& p : non_zero) {
                long long z = p.second;
                total_hospitable += (1LL * z * (z + 1)) / 2;
            }

            int sz = non_zero.size() - 1; 
            for (int i = 0; i < sz; i++) {
                int current_xor = 0;
                int current_sum = 0;
                
                for (int j = i; j < sz; j++) {
                    if ((current_xor & non_zero[j].first) != 0) {
                        break; 
                    }
                    current_xor ^= non_zero[j].first;
                    current_sum += non_zero[j].first;

                    long long ways_left = non_zero[i].second + 1;
                    long long ways_right = non_zero[j + 1].second + 1;
                    total_hospitable += ways_left * ways_right;
                }
            }

            cout << total_hospitable << "\n";
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            int n, q;
            cin >> n >> q;
            Tree tree(n);
            for (int i = 1; i <= n; i++) cin >> tree.a[i];
            for (int i = 0; i < n - 1; i++) {
                int u, v;
                cin >> u >> v;
                tree.adj[u].push_back(v);
                tree.adj[v].push_back(u);
            }
            tree.solve_queries(q);
        }
    }
    return 0;
}