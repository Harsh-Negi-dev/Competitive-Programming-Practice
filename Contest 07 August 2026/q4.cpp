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
    ll x, y;
    cin >> x >> y;
    ll minDist = -1;
    ll bestK = 1;
    ll bestPx = 0;
    for (ll k = 1;; k++) {
        ll s = k * (k + 1) / 2;
        if (s > x + y) break;
        ll minVal = max(0LL, s - y);
        ll maxVal = min(s, x);
        if (minVal > maxVal) continue;
        ll opt = (x - y + s) / 2;
        for (ll step = 0; step <= 1; step++) {
            ll px = opt + step;
            if (px < minVal) px = minVal;
            if (px > maxVal) px = maxVal;
            ll py = s - px;
            ll dist = (x - px) * (x - px) + (y - py) * (y - py);
            if (minDist == -1 || dist < minDist) {
                minDist = dist;
                bestK = k;
                bestPx = px;
            }
        }
    }
    string s(bestK, 'Y');
    ll req = bestPx;
    for (ll w = bestK; w >= 1; w--) {
        if (req >= w) {
            req -= w;
            s[bestK - w] = 'X';
        }
    }
    cout << s << "\n";
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