#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n == 1) {
            cout << 1 << "\n";
            continue;
        }
        if (n == 2) {
            cout << -1 << "\n";
            continue;
        }
        vector<long long> a(n);
        a[0] = 1;
        a[1] = 2;
        a[2] = 3;
        long long currSum = 6;
        for (int i = 3; i < n; i++) {
            a[i] = currSum;
            currSum += a[i];
        }
        for (int i = 0; i < n; i++) {
            cout << a[i] << (i == n - 1 ? "" : " ");
        }
        cout << "\n";
    }
    return 0;
}