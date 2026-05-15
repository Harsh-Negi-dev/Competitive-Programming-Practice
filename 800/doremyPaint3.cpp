#include<bits/stdc++.h>
using namespace std;
string doremyPaint3(vector<int> arr, int n) {
    map<int, int> freq;
    for (auto it : arr) {
        freq[it]++;
    }
    if (freq.size() == 1) return "Yes";
    if (freq.size() > 2) return "No";
    auto it = freq.begin();
    int f1 = it -> second;
    it++;
    int f2 = it -> second;
    if (abs(f1 - f2) <= 1) return "Yes";
    return "No";
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
        cout << doremyPaint3(arr, n) << "\n";
    }
    return 0;
}