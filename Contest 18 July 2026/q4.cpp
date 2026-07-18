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
struct Hash {
    uint64_t h1, h2;
    bool operator==(const Hash& o) const {
        return h1 == o.h1 && h2 == o.h2;
    }
    Hash operator+(const Hash& o) const {
        return {h1 + o.h1, h2 + o.h2};
    }
};

struct Element {
    int val;
    int id;
};
void solve() {
    // Write your per-test-case logic here
    int n, q;
    if (!(cin >> n >> q)) return;
    
    vector<int> a(n);
    bool sorted = true;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i > 0 && a[i] < a[i - 1]) {
            sorted = false;
        }
    }

    if (sorted) {
        cout << 0 << "\n";
        return;
    }

    vector<Element> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = {a[i], i};
    }

    // Sort to pair original values closely for matching assignment mapping
    sort(arr.begin(), arr.end(), [](const Element& x, const Element& y) {
        return x.val < y.val;
    });

    static mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    
    vector<Hash> H_a(n);
    vector<Hash> H_s(n);
    Hash current_hash = {0, 0};

    for (int i = 0; i < n; i++) {
        // Assign new random 128-bit hash integer configuration exclusively to new distinct values
        if (i == 0 || arr[i].val != arr[i - 1].val) {
            current_hash = {rng(), rng()};
        }
        H_a[arr[i].id] = current_hash;
        H_s[i] = current_hash;
    }

    vector<Hash> pref_a(n + 1, {0, 0});
    vector<Hash> pref_s(n + 1, {0, 0});
    for (int i = 0; i < n; i++) {
        pref_a[i + 1] = pref_a[i] + H_a[i];
        pref_s[i + 1] = pref_s[i] + H_s[i];
    }

    int ans = -1;
    // Maximum answer search parameter limit fits within 20 iterations (2^21 >> 10^6 max limit condition constraint)
    for (int p = 0; p <= 20; p++) {
        int C = 1 << (p + 1);
        bool ok = true;
        // Prefix multiples block bounds checking logic 
        for (int i = C; i < n; i += C) {
            if (!(pref_a[i] == pref_s[i])) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ans = 1 << p;
            break;
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