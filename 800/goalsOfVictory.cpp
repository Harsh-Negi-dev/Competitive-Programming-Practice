#include<bits/stdc++.h>
using namespace std;
int goalsOfVictory(vector<int> arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return -sum;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n - 1);
        for (int i = 0; i < n - 1; i++) {
            cin >> arr[i];
        }
        cout << goalsOfVictory(arr, n - 1) << "\n";
   }
    return 0;
}