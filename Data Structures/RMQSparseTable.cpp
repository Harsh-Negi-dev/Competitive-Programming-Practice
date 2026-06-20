#include <bits/stdc++.h>
using namespace std;

class SparseTable {
private:
    vector<vector<int>> st;
    vector<int> lg;
    int n;

public:
    SparseTable(vector<int>& arr) {
        n = arr.size();

        int K = log2(n) + 1;

        st.assign(n, vector<int>(K));
        lg.assign(n + 1, 0);

        // Precompute logs
        for (int i = 2; i <= n; i++)
            lg[i] = lg[i / 2] + 1;

        // Length = 1
        for (int i = 0; i < n; i++)
            st[i][0] = arr[i];

        // Build table
        for (int j = 1; j < K; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[i][j] = min(
                    st[i][j - 1],
                    st[i + (1 << (j - 1))][j - 1]
                );
            }
        }
    }

    int query(int L, int R) {
        int len = R - L + 1;
        int k = lg[len];

        return min(
            st[L][k],
            st[R - (1 << k) + 1][k]
        );
    }
};

