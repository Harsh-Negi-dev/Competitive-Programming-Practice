#include<bits/stdc++.h>
using namespace std;
int coverInWater(string s) {
    if (s.find("...") != string::npos) return 2;
    return count(s.begin(), s.end(), '.');
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << coverInWater(s) << "\n";
    }
    return 0;
}