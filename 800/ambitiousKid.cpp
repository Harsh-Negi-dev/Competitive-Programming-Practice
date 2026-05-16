#include<bits/stdc++.h>
using namespace std;
int ambitiousKid(vector<int> arr, int n) {
    int minOp = INT_MAX;
    for (int i = 0; i < n; i++) {
        minOp = min(minOp, abs(arr[i]));
    }
    return minOp;
}
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << ambitiousKid(arr, n) << "\n";
    return 0;
}