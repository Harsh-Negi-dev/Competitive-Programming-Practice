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

vll treeSum;
vi treeCnt;
vll vals;

void update(int node, int l, int r, int idx, ll val) {
    treeCnt[node]++;
    treeSum[node] += val;
    if (l == r) return;
    int mid = l + ((r - l) >> 1);
    if (idx <= mid) update(2 * node, l, mid, idx, val);
    else update(2 * node + 1, mid + 1, r, idx, val);
}

int query(int node, int l, int r, ll target) {
    if (l == r) {
        ll val = vals[l];
        return (target + val - 1) / val;
    }
    int mid = l + ((r - l) >> 1);
    int leftNode = 2 * node;
    int rightNode = 2 * node + 1;
    if (treeSum[rightNode] >= target) return query(rightNode, mid + 1, r, target);
    else return treeCnt[rightNode] + query(leftNode, l, mid, target - treeSum[rightNode]);
}

void solve() {
    // Write your per-test-case logic here
    int n, m;
    cin >> n >> m;
    vll v(n);
    rep(i, 0, n) cin >> v[i];
    vector<vll> a(n, vll(m));
    vals.clear();
    rep(i, 0, n) {
        rep(j, 0, m) {
            cin >> a[i][j];
            vals.pb(a[i][j]);
        }
    }
    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());
    int V = vals.size();
    treeSum.assign(4 * V, 0);
    treeCnt.assign(4 * V, 0);
    int ans = m;
    rev(k, n - 1, 0) {
        rep(j, 0, m) {
            int idx = lower_bound(all(vals), a[k][j]) - vals.begin();
            update(1, 0, V - 1, idx, a[k][j]);
        }
        if (treeSum[1] >= v[k]) {
            int piece = query(1, 0, V - 1, v[k]);
            ans = min(ans, piece);
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