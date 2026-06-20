#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
void solve() {
    long long a, b, x;
    cin >> a >> b >> x;
    vector<pair<long long, int>> path_a; // {value, number of divisions}
    long long curr_a = a;
    int div_a = 0;
    while (true) {
        path_a.push_back({curr_a, div_a});
        if (curr_a == 0) break;
        curr_a /= x;
        div_a++;
    }
    vector<pair<long long, int>> path_b; // {value, number of divisions}
    long long curr_b = b;
    int div_b = 0;
    while (true) {
        path_b.push_back({curr_b, div_b});
        if (curr_b == 0) break;
        curr_b /= x;
        div_b++;
    }
    long long min_ops = abs(a - b);
    for (const auto& pA : path_a) {
        for (const auto& pB : path_b) {
            long long val_a = pA.first;
            int ops_a = pA.second;
            
            long long val_b = pB.first;
            int ops_b = pB.second;
            long long total_ops = ops_a + ops_b + abs(val_a - val_b);
            min_ops = min(min_ops, total_ops);
        }
    }
    cout << min_ops << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}