#include<bits/stdc++.h>
using namespace std;
int lineTrip(vector<int> arr, int n, int x) {
    int minVolume = arr[0];
    for (int i = 0; i < n - 1; i++) {
        minVolume = max(minVolume, arr[i + 1] - arr[i]); 
    }
    minVolume = max(minVolume, 2 * (x - arr[n - 1]));
    return minVolume;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << lineTrip(arr, n, x) << "\n";
    }
    return 0;
}