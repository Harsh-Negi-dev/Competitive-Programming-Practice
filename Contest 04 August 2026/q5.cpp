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
    vll b(n); 
    map<long long, int> freq;
    rep(i, 0, n) {
        cin >> b[i];
        freq[b[i]]++;
    }
    if (freq.begin()->first != 0) {
        cout << -1 << "\n";
        return;
    }
    vll B, C;
    for (const auto &it : freq) {
        B.push_back(it.first);
        C.push_back(it.second);
    }
    map<long long, long long> btoa;
    ll prevA = 0;
    rep(i, 0, sz(B) - 1) { 
        ll diff = B[i + 1] - B[i];
        if (diff % C[i] != 0) {
            cout << -1 << "\n";
            return;
        }
        ll ai = diff / C[i];
        if (ai <= prevA) {
            cout << -1 << "\n";
            return;
        }
        btoa[B[i]] = ai;
        prevA = ai;
    }
    ll alast = (prevA == 0) ? 1 : prevA + 1;
    btoa[B.back()] = alast;
    rep(i, 0, n) cout << btoa[b[i]] << (i == n - 1 ? "" : " ");
    cout << "\n";
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