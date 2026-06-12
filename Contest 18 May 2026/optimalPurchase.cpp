#include<bits/stdc++.h>
using namespace std;
long long optimalPurchase(long long n, long long a, long long b) {
    long long groups = n / 3;
    long long remaining = n % 3;
    long long cost = groups * min(3 * a, b);
    cost += min(remaining * a, b);
    return cost;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, a, b;
        cin >> n >> a >> b;
        cout << optimalPurchase(n, a, b) << "\n";
    }
    return 0;
}