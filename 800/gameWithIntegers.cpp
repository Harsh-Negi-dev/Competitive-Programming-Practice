#include<bits/stdc++.h>
using namespace std;
string gameWithIntegers(int n) {
    if ((n + 1) % 3 == 0 || (n - 1) % 3 == 0) return "First";
    return "Second";
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << gameWithIntegers(n) << "\n";
    }
    return 0;
}