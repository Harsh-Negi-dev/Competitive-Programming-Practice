#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        vector<int> c(k);
        bool threeOrMore = false;
        int pairCount = 0;
        for (int i = 0; i < k; i++) {
            long long c;
            cin >> c;
            if (c >= 3) threeOrMore = true;
            if (c == 2) pairCount++;
        } 
        if (threeOrMore || pairCount >= 2) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}