#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        long long move = sum - n;
        if (move & 1) cout << "Alice\n";
        else cout << "Bob\n";
        
    }
    return 0;
}