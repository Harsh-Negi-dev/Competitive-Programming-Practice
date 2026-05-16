#include<bits/stdc++.h>
using namespace std;
int dontTryToCount(string x, string s) {
    int count = 0;
    while (count <= 10) {
        if (x.find(s) != string::npos) {
            return count;
        }
        x += x;
        count++;
    }
    return -1;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string x;
        cin >> x;
        string s;
        cin >> s;
        cout << dontTryToCount(x, s) << "\n";
    }
    return 0;
}