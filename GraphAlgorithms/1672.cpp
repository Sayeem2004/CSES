#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n, m, q; cin >> n >> m >> q;
    vector<vector<ll>> A(n, vector<ll>(n));
    for (int i = 0; i < m; i++) {
        ll a, b, c; cin >> a >> b >> c;
        if (A[a-1][b-1] == 0) A[a-1][b-1] = c;
        else A[a-1][b-1] = min(A[a-1][b-1], c);
        if (A[b-1][a-1] == 0) A[b-1][a-1] = c;
        else A[b-1][a-1] = min(A[b-1][a-1], c);
    }
    vector<vector<ll>> D(n, vector<ll>(n, 1e18));
    for (int i = 0; i < n; i++) {
        for (int q = 0; q < n; q++) {
            if (i == q) D[i][q] = 0;
            if (A[i][q]) D[i][q] = min(D[i][q], A[i][q]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int q = 0; q < n; q++) {
            for (int r = 0; r < n; r++) {
                D[q][r] = min(D[q][r], D[q][i]+D[i][r]);
            }
        }
    }
    for (int i = 0; i < q; i++) {
        ll a, b; cin >> a >> b;
        if (D[a-1][b-1] == 1e18)
            cout << -1 << "\n";
        else
            cout << D[a-1][b-1] << "\n";
    }
}
