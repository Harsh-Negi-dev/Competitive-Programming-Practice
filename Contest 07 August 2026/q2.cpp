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
    vi a(n);
    rep(i, 0, n) cin >> a[i];
    vi c;
    vi s;
    rep(i, 0, n) {
        if (c.empty() || c.back() != a[i]) {
            c.push_back(a[i]);
            s.push_back(1);
        }
        else s.back()++;
    }
    int C = c.size();
    bool plus2 = false;
    rep(i, 0, C - 1) {
        if (s[i] >= 2 && s[i + 1] >= 2) {
            plus2 = true;
            break;
        }
    }
    if (plus2) {
        cout << C + 2 << "\n";
        return;
    }
    bool plus1 = false;
    rep(i, 0, C) {
        if (s[i] >= 2) {
            bool op1 = (i + 1 < C) && ((i + 2 >= C) || (c[i] != c[i + 2]));
            bool op2 = (i - 1 >= 0) && ((i - 2 < 0) || (c[i] != c[i - 2]));
            if (op1 || op2) {
                plus1 = true;
                break;
            }
        }
    } 
    if (plus1) cout << C + 1 << "\n";
    else cout << C << "\n";
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