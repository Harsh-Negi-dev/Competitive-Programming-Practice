#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        long long total = 1LL * n * (n + 1) / 2;
        vector<long long> cnt(3, 0);
        cnt[0] = 1;
        long long bad = 0;
        int pref = 0;
        for (char c : s) {
            pref += (c == '0' ? 1 : -1);
            int rem = ((pref % 3) + 3) % 3;
            bad += cnt[rem];
            cnt[rem]++;
        }
        long long ans = total - bad;
        for (int i = 0; i < n; ) {
            int j = i;
            while (j + 1 < n && s[j] != s[j + 1])
                j++;
            long long m = j - i + 1;
            long long evenPos = (m + 1) / 2;
            long long oddPos = m / 2;
            long long oddSub =
                evenPos * (evenPos + 1) / 2 +
                oddPos * (oddPos + 1) / 2;
            ans -= (oddSub - m);
            i = j + 1;
        }
        cout << ans << '\n';
    }
    return 0;
}