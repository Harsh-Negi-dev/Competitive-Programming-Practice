#include<bits/stdc++.h>
using namespace std;
string jaggedSwaps(vector<int> arr, int n) {
    if (arr[0] == 1) return "YES";
    return "NO";
}

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
        cout << jaggedSwaps(arr, n) << "\n";
    }
    return 0;
}