#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int total = 0;
        int dist = 0;
        int temp = n;
        for (int i = 2; i * i <= temp; ++i) {
            if (temp % i == 0) {
                dist++;
                while (temp % i == 0) {
                    total++;
                    temp /= i;
                }
            }
        }
        if (temp > 1) {
            dist++;
            total++;
        }
        cout << total + dist - 1 << "\n";
    }
    return 0;
}