#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (auto &x : a) cin >> x;
        sort(a.begin(), a.end());
        int ans = n;
        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && a[j] == a[i]) j++;
            int left = i;
            int right = n - j;
            ans = min(ans, max(left, right));
            i = j;
        }
        cout << ans << '\n';
    }
    return 0;
}