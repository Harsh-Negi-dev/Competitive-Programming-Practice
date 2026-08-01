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
    int n, q;
    cin >> n >> q;
    string s, t;
    cin >> s >> t;
    vi pref01(n + 1, 0);
    vi pref10(n + 1, 0);
    rep(i, 0, n) {
        pref01[i + 1] = pref01[i] + (s[i] == '0' && t[i] == '1' ? 1 : 0);
        pref10[i + 1] = pref10[i] + (s[i] == '1' && t[i] == '0' ? 1 : 0);
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        int len = r - l + 1;
        int c01 = pref01[r] - pref01[l - 1];
        int c10 = pref10[r] - pref10[l - 1];
        if (2 * c01 <= len && 2 * c10 <= len) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t; // Read number of test cases
    while (t--) {
        solve();
    }
    
    return 0;
}