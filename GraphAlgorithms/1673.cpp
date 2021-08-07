#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define arr array
vector<vector<arr<ll,2>>> R(2500), A(2500);
vector<arr<bool,2>> V(2500);

void dfs(ll v, ll p) {
    V[v][p] = true;
    if (p == 0) {
        for (auto x : R[v]) {
            if (!V[x[0]][p]) dfs(x[0], p);
        }
    } else {
        for (auto x : A[v]) {
            if (!V[x[0]][p]) dfs(x[0], p);
        }
    }
}

int main() {
    ll n, m; cin >> n >> m;
    vector<arr<ll,3>> E;
    for (int i = 0; i < m; i++) {
        ll a, b, c; cin >> a >> b >> c;
        E.push_back({a-1, b-1, c});
        R[b-1].push_back({a-1, c});
        A[a-1].push_back({b-1, c});
    }
    vector<ll> D(n, -1e18);
    D[0] = 0;
    for (int i = 0; i < n; i++) {
        bool br = true;
        for (auto e : E) {
            ll prev = D[e[1]];
            D[e[1]] = max(D[e[1]], D[e[0]]+e[2]);
            if (D[e[1]] != prev) br = false;
        }
        if (br) break;
    }
    vector<ll> M;
    for (auto e : E) {
        ll prev = D[e[1]];
        D[e[1]] = max(D[e[1]], D[e[0]]+e[2]);
        if (D[e[1]] != prev) M.push_back(e[1]);
    }
    dfs(n-1, 0);
    dfs(0, 1);
    for (auto x : M) {
        if (V[x][0] && V[x][1]) {
            cout << -1 << "\n";
            return 0;
        }
    }
    cout << D[n-1] << "\n";
}
