#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        long long sum = 0;
        long long bestMin = 0;
        for (int i = 0; i < n; i++) {
            sum += max(a[i], b[i]);
            bestMin = max(bestMin, min(a[i], b[i]));
        }
        cout << sum + bestMin << "\n";
    }
    return 0;
}