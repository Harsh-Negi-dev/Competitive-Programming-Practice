#include <bits/stdc++.h>
using namespace std;

map<string, int> memo;

string encode(const vector<int>& a, const vector<int>& b) {
    string s;
    for (int x : a) {
        s += to_string(x) + ",";
    }
    s += "|";
    for (int x : b) {
        s += to_string(x) + ",";
    }
    return s;
}

int solve(vector<int> a, vector<int> b) {
    if (a.size() == 1) {
        return min(a[0], b[0]);
    }
    
    string key = encode(a, b);
    if (memo.count(key)) {
        return memo[key];
    }
    
    int best = 0;
    int sz = a.size();
    
    for (int i = 0; i < sz - 1; i++) {
        vector<int> S = {a[i], a[i+1], b[i], b[i+1]};
        sort(S.begin(), S.end());
        
        vector<int> new_a, new_b;
        for (int j = 0; j < i; j++) {
            new_a.push_back(a[j]);
            new_b.push_back(b[j]);
        }
        new_a.push_back(S[1]);
        new_b.push_back(S[2]);
        for (int j = i + 2; j < sz; j++) {
            new_a.push_back(a[j]);
            new_b.push_back(b[j]);
        }
        
        best = max(best, solve(new_a, new_b));
    }
    
    return memo[key] = best;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        
        memo.clear();
        cout << solve(a, b) << "\n";
    }
    
    return 0;
}