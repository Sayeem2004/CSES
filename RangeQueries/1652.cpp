#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    long long n, m; cin >> n >> m;
    vector<vector<long long>> V(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int q = 0; q < n; q++) {
            char c; cin >> c;
            if (c == '*') V[i][q] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int q = 1; q < n; q++) {
            V[i][q] += V[i][q-1];
        }
    }
    for (int i = 1; i < n; i++) {
        for (int q = 0; q < n; q++) {
            V[i][q] += V[i-1][q];
        }
    }
    for (int i = 0; i < m; i++) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        a--; b--; c--; d--;
        if (a == 0 && b == 0) cout << V[c][d] << "\n";
        else if (a == 0) cout << V[c][d]-V[c][b-1] << "\n";
        else if (b == 0) cout << V[c][d]-V[a-1][d] << "\n";
        else cout << V[c][d]-V[c][b-1]-V[a-1][d]+V[a-1][b-1] << "\n";
    }
}
