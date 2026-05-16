#include<bits/stdc++.h>
using namespace std;
int targetPractice(vector<vector<char>> arr) {
    int score = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (arr[i][j] == 'X') {
                int layer = min({i, j, 9 - i, 9 - j});
                score += layer + 1;
            }
        }
    }
    return score;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<vector<char>> arr(10, vector<char>(10));
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                cin >> arr[i][j];
            }
        }
        cout << targetPractice(arr) << "\n";
    }
    return 0;
}