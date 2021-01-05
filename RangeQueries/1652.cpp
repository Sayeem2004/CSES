#include <bits/stdc++.h>
using namespace std;
#define int64 int64_t


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> v(n,vector<int>(n,0));
    for (int i = 0; i < n; i++) {
        for (int q = 0; q < n; q++) {
            char c; cin >> c;
            if (c == '*') v[i][q] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int q = 0; q < n; q++) {
            if (i == 0 && q == 0) continue;
            if (q == 0) {
                v[i][q] += v[i-1][q];
                continue;
            }
            if (i == 0) {
                v[i][q] += v[i][q-1];
                continue;
            }
            v[i][q] += v[i-1][q]+v[i][q-1]-v[i-1][q-1];
        }
    }
    for (int i = 0; i < m; i++) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        a--; b--; c--; d--;
        if (a == 0 && b == 0) {
            cout << v[c][d] << "\n";
        } else if (a == 0) {
            cout << v[c][d]-v[c][b-1] << "\n";
        } else if (b == 0) {
            cout << v[c][d]-v[a-1][d] << "\n";
        } else {
            cout << v[c][d]-v[c][b-1]-v[a-1][d]+v[a-1][b-1] << "\n";
        }
    }
}
