#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (a[i] < a[j]) {
                    a[j] = a[i];
                }
            }
        }
        cout << accumulate(a.begin(), a.end(), 0) << "\n";
    }
    return 0;
}