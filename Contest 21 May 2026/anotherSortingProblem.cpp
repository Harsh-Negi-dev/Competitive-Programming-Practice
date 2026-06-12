#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int l = 0;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                l = max(l, arr[i] - arr[i + 1]);
            }
        }
        if (l == 0) {
            cout << "YES\n";
            continue;
        }
        vector<int> force0(n, 0), force1(n, 0);
        vector<int> small(n - 1, 0);
        for (int i = 0; i < n - 1; i++) {
            int d = arr[i + 1] - arr[i];
            if (d < l) small[i] = 1;
            if (d < 0) {
                force0[i] = 1;
                force1[i + 1] = 1;
            }
        }
        for (int i = 0; i < n - 1; i++) {
            if (small[i] && force1[i]) force1[i + 1] = 1;
        }
        for (int i = n - 2; i >= 0; i--) {
            if (small[i] && force0[i + 1]) force0[i] = 1;
        }
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (force0[i] && force1[i]) {
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}