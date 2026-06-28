#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;
const long long MOD1 = MOD - 1;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, m, r, c;
        cin >> n >> m >> r >> c;
        long long exp = 0;
        exp = (exp + ((r - 1) * m) % MOD1) % MOD1;
        exp = (exp + ((c - 1) * n) % MOD1) % MOD1;
        exp = (exp - ((r - 1) * (c - 1)) % MOD1 + MOD1) % MOD1;
        long long ans = 1;
        long long base = 2;
        long long e = exp;
        while (e) {
            if (e & 1) ans = ans * base % MOD;
            base = base * base % MOD;
            e >>= 1;
        }
        cout << ans << '\n';
    }
    return 0;
}