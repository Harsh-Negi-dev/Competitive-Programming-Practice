#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<int> s1(n + 1, 0);
        vector<int> s2(n + 1, 0);
        for (int i = 0; i < n; i++) {
            s1[i + 1] = s1[i] + (a[i] == 1 ? 1 : -1);
            s2[i + 1] = s2[i] + (a[i] <= 2 ? 1 : -1);
        }
        vector<int> maxS2(n + 1, -1e9);
        maxS2[n - 1] = s2[n - 1];
        for (int i = n - 2; i >= 1; i--) {
            maxS2[i] = max(s2[i], maxS2[i + 1]);
        }
        bool possible = false;
        for (int l1 = 1; l1 <= n - 2; l1++) {
            if (s1[l1] >= 0) {
                if (maxS2[l1 + 1] >= s2[l1]) {
                    possible = true;
                    break;
                }
            }
        }
        if (possible) cout << "YES\n";
        if (!possible) cout << "NO\n";
    }
    return 0;
}