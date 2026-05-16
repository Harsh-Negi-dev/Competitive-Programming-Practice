#include<bits/stdc++.h>
using namespace std;
string howMuchDoesDaytonaCost(vector<int> arr, int n, int k) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == k) return "YES";
    }
    return "NO";
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << howMuchDoesDaytonaCost(arr, n, k) << "\n";
    }
    return 0;
}