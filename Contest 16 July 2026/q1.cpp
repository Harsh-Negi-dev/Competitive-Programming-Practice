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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (n < 2 * k) {
        cout << -1 << "\n";
        return;
    }
    int flip = 0;
    rep(i, 0, k) {
        if (s[i] == 'L') flip++;
    }
    rep(i, n - k, n) {
        if (s[i] == 'R') flip++;
    }
    cout << flip << "\n";
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