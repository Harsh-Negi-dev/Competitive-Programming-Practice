#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long ones = 0;
        long long base = 0;
        long long slots = 0;
        for (long long x : arr) {
            if (x == 1) ones++;
            else {
                base += x;
                slots += (x + 1) / 3;
            }
        }
        cout << base + min(ones, slots) << "\n";
    }
    return 0;
}