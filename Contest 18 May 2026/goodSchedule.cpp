#include<bits/stdc++.h>
using namespace std;
int goodSchedule(vector<int>& a, vector<int>& b, int n) {
    
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        cout << goodSchedule(a, b, n) << "\n";
    }
    return 0;
}