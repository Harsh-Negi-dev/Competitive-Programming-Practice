#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int mini = INT_MAX, maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            mini = min(mini, x);
            maxi = max(maxi, x);
        }
        cout << (maxi - mini + 1) / 2 << "\n";
    }
    return 0;
}