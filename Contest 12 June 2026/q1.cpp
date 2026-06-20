#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> h(n);
        for (int i = 0; i < n; i++) {
            cin >> h[i];
        }
        cout << *max_element(h.begin(), h.end()) - *min_element(h.begin(), h.end()) + 1 << "\n";
    }
    return 0;
}