#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int max_L = 0;

    for (int i = 0; i < n; i++) {
        vector<bool> seen1(n + 2, false);
        int min1 = a[i], max1 = a[i];
        
        for (int len = 1; i + len - 1 < n; len++) {
            int u = a[i + len - 1];
            if (seen1[u]) break; 
            seen1[u] = true;
            min1 = min(min1, u);
            max1 = max(max1, u);
            
            if (max1 - min1 != len - 1) continue; 
            
            for (int j = i + len; j + len - 1 < n; j++) {
                bool validA = true, validB = true;
                int min2 = a[j], max2 = a[j];
                vector<bool> seen2(n + 2, false);
                
                for (int k = 0; k < len; k++) {
                    int v = a[j + k];
                    if (seen2[v] || v == 0) { validA = false; validB = false; break; }
                    seen2[v] = true;
                    min2 = min(min2, v);
                    max2 = max(max2, v);
                    
                    if (v < max1 + 1 || v > max1 + len) validA = false;
                    if (v < min1 - len || v > min1 - 1) validB = false;
                    if (!validA && !validB) break;
                }
                
                if (validA && (max2 - min2 == len - 1)) {
                    max_L = max(max_L, len);
                }
                if (validB && (max2 - min2 == len - 1)) {
                    max_L = max(max_L, len);
                }
            }
        }
    }

    cout << max_L << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}