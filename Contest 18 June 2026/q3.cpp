#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        long long cur = a[0];
        long long ans = cur;
        for (int i = 1; i < n; i++) {
            if (a[i] < cur) {
                cur += a[i];
            } else {
                cur = a[i];
            }
            ans = max(ans, cur);
        }
        cout << ans << "\n";
    }
    return 0;
}