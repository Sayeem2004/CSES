#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define arr array

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<arr<int,3>> E(m);
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        E[i] = {a-1,b-1,c};
    }
    vector<int> P(n, -1);
    vector<ll> D(n, 1e18);
    ll br = -1;
    for (int i = 0; i < n; i++) {
        for (auto e : E) {
            if (D[e[0]] + e[2] < D[e[1]]) {
                D[e[1]] = D[e[0]]+e[2];
                P[e[1]] = e[0];
                if (i == n-1) br = e[1];
            }
        }
    }
    if (br == -1) cout << "NO\n";
    else {
        for (int i = 0; i < n; ++i)
            br = P[br];
        cout << "YES\n";
        vector<int> A;
        A.push_back(br+1);
        int p = P[br];
        while (p != br) {
            A.push_back(p+1);
            if (p != -1) p = P[p];
        }
        A.push_back(br+1);
        reverse(A.begin(),A.end());
        for (auto x : A)
            cout << x << " ";
        cout << "\n";
    }
}
