#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            int n;
            cin >> n;
            vector<int> a(n);
            int nonZeroCount = 0;
            int xorSum = 0;
            for (int i = 0; i < n; ++i) {
                cin >> a[i];
                if (a[i] > 0) {
                    nonZeroCount++;
                }
                xorSum ^= a[i];
            }
            if (nonZeroCount <= 1) {
                cout << 0 << "\n";
                return;
            }
            if (xorSum == 0) {
                cout << 1 << "\n";
                return;
            }
            int ans = 0;
            for (int i = 0; i < n; ++i) {
                if ((xorSum ^ a[i]) < a[i]) {
                    ans++;
                }
            }    
            cout << ans % MOD << "\n";
        }
    }
    return 0;
}