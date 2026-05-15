#include<bits/stdc++.h>
using namespace std;
bool is_sorted(vector<int> arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) return false;
    }
    return true;
}
string HalloumiBoxes(vector<int> arr, int k) {
    if (k >= 2) return "YES";
    else {
        if (is_sorted(arr)) return "YES";
        else return "NO";
    }
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
        cout << HalloumiBoxes(arr, k) << "\n";
    }
    return 0;
}