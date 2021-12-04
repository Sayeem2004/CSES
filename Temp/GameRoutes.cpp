#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
vector<ll> DP(100005);
vector<vector<ll>> A(100005);

void dfs(int v, int p) {
    if (p != -1) DP[v] += DP[p];
    for (auto x : A[v]) {
        if (x != p) dfs(x, v);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        ll a, b; cin >> a >> b;
        A[a-1].push_back(b-1);
    }
    DP[0] = 1;
    dfs(0, -1);
    cout << DP[n-1] << "\n";
}
