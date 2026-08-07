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
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vll a(x);
    rep(i, 0, x) cin >> a[i];
    vll b(y);
    rep(i, 0, y) cin >> b[i];
    int p1 = x - 1;
    int p2 = y - 1;
    ll ans = 0;
    int cntA = 0, cntB = 0, totCnt = 0;
    while ((p1 >= 0 || p2 >= 0) && totCnt < n + m - 1) {
        if (p1 >= 0 && p2 >= 0) {
            if (a[p1] == b[p2]) {
                ans += a[p1];
                totCnt++;
                p1--;
                p2--;
            }
            else if (a[p1] > b[p2]) {
                if (cntA < n) {
                    cntA++;
                    totCnt++;
                    ans += a[p1];
                }
                p1--;
            }
            else {
                if (cntB < m) {
                    cntB++;
                    totCnt++;
                    ans += b[p2];
                }
                p2--;
            }
        }
        else if (p1 >= 0) {
            if (cntA < n) {
                cntA++;
                totCnt++;
                ans += a[p1];
            }
            p1--;
        }
        else {
            if (cntB < m) {
                cntB++;
                totCnt++;
                ans += b[p2];
            }
            p2--;
        }
    }
    cout << ans << "\n";
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