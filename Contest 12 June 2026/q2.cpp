#include<bits/stdc++.h>
using namespace std;
string func(const string s, int n, int k) {
    for (int r = 0; r < k; r++) {
        int ones = 0;

        for (int i = r; i < n; i += k) {
            if (s[i] == '1')
                ones++;
        }

        if (ones % 2)
            return "NO";
    }

    return "YES";
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        cout << func(s, n, k) << "\n";
    }
    return 0;
}