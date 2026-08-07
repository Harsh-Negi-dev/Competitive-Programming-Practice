#include <bits/stdc++.h>
using namespace std;

// =========================================================================
// Type Aliases
// =========================================================================
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

// =========================================================================
// Macros
// =========================================================================
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define F first
#define S second
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define rev(i, a, b) for (int i = a; i >= b; --i)

// =========================================================================
// Constants
// =========================================================================
const int MOD = 1e9 + 7; // Standard modulo for CP
const ll INF = 1e18;     // Safe representation of infinity for long long

// =========================================================================
// Utility Functions
// =========================================================================

// Greatest Common Divisor
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

// Least Common Multiple
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

// Modular Exponentiation (base^exp % MOD)
ll modpow(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

// =========================================================================
// Main Logic
// =========================================================================

void solve() {
    // Write your per-test-case logic here
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt0 = 0, cnt1 = 0; //total cnt of 0s and 1s
    int c0 = 0, c1 = 0; //req del to fix adj duplicates
    rep(i, 0, n) {
        if (s[i] == '0') cnt0++;
        else cnt1++;
        if (i > 0 && s[i] == s[i - 1]) {
            if (s[i] == '0') c0++;
            else c1++;
        }
    }
    int a0 = cnt0 - c0, a1 = cnt1 - c1; //cnt of 0s and 1s after collapse
    int del = cnt0 - cnt1;
    int maxLen = -1;
    rep(k, -1, 2) {
        if (abs(del - k) <= 1) {
            int r1 = min(a0 - k, a1);
            if (r1 >= max(0, -k)) {
                int l = 2 * r1 + k;
                maxLen = max(maxLen, l);
            }
        }
    }
    if (maxLen == -1) cout << -1 << "\n";
    else cout << n - maxLen << "\n";
}

int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t; // Read number of test cases. Comment out if the problem is single-test-case.
    while (t--) {
        solve();
    }
    
    return 0;
}