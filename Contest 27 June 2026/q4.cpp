#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, d;
    cin >> n >> d;
    vector<long long> a(n);
    long long totSum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        totSum += a[i];
    }
    vector<long long> pref(2 * n + 1, 0);
    for (int i = 0; i < 2 * n; ++i) {
        pref[i + 1] = pref[i] + a[i % n];
    }
    long long maxHappiness = 0;
    for (int i = 0; i < n; ++i) {
        long long windSum = 0;
        long long realNeighbors = 2LL * d;
        if (2 * d + 1 >= n) {
            windSum = totSum - a[i];
            realNeighbors = n - 1;
        } else {
            int L = i - d + n;
            int R = i + d + n;
            windSum = pref[R + 1] - pref[L] - a[i];
        }   
        long long coefficient = realNeighbors * a[i] - windSum;
        if (coefficient > 0) {
            maxHappiness += coefficient;
        }
    }
    cout << maxHappiness << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}