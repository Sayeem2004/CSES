#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
vector<vector<int>> A(200000);
vector<int> DP1(200000), DP2(200000);

void dfs(int v, int p) {
    for (auto x : A[v]) {
        if (x == p) continue;
        dfs(x, v);
        DP1[v] += max(DP1[x], DP2[x]);
    }
    for (auto x : A[v]) {
        if (x == p) continue;
        DP2[v] = max(DP2[v], DP1[x]+1+DP1[v] - max(DP1[x], DP2[x]) );
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        A[a-1].push_back(b-1);
        A[b-1].push_back(a-1);
    }
    dfs(0, -1);
    cout << max(DP1[0], DP2[0]) << "\n";
}
