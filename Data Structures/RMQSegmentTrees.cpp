#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
private:
    vector<int> tree;
    int n;

    void build(int node, int start, int end, vector<int>& arr) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = (start + end) / 2;
        build(2 * node, start, mid, arr);
        build(2 * node + 1, mid + 1, end, arr);
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }

    int query(int node, int start, int end, int L, int R) {

        // No overlap
        if (R < start || end < L)
            return INT_MAX;

        // Complete overlap
        if (L <= start && end <= R)
            return tree[node];

        int mid = (start + end) / 2;

        int left =
            query(2 * node, start, mid, L, R);

        int right =
            query(2 * node + 1, mid + 1, end, L, R);

        return min(left, right);
    }

    void update(int node, int start, int end, int idx, int val) {

        if (start == end) {
            tree[node] = val;
            return;
        }

        int mid = (start + end) / 2;

        if (idx <= mid)
            update(2 * node, start, mid, idx, val);
        else
            update(2 * node + 1, mid + 1, end, idx, val);

        tree[node] = min(tree[2 * node], tree[2 * node + 1]
        );
    }

public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();

        tree.resize(4 * n);

        build(1, 0, n - 1, arr);
    }

    int query(int L, int R) {
        return query(1, 0, n - 1, L, R);
    }

    void update(int idx, int val) {
        update(1, 0, n - 1, idx, val);
    }
};