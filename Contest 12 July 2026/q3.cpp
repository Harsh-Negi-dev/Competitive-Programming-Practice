#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        int C = 0;
        vector<pair<int, int>> pos;
        
        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;
            if (val == -1) {
                C++;
            } else {
                if (pos.empty() || pos.back().first != val) {
                    pos.push_back({val, 1});
                } else {
                    pos.back().second++;
                }
            }
        }
        
        long long W0 = 1;
        for (auto p : pos) {
            W0 = (W0 * power(2, p.second - 1)) % MOD;
        }
        
        long long E = (C == 0) ? 1 : power(2, C - 1);
        long long O = (C == 0) ? 0 : power(2, C - 1);
        
        long long P = 0;
        for (size_t i = 1; i < pos.size(); i++) {
            if (pos[i].first == pos[i-1].first + 1) {
                P++;
            }
        }
        
        long long ans = (E * W0) % MOD;
        long long odd_part = (O * P) % MOD;
        odd_part = (odd_part * W0) % MOD;
        
        ans = (ans + odd_part) % MOD;
        
        cout << ans << "\n";
    }
    return 0;
}