#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int N = 100005;
vector<vector<int>> A(N);
vector<int> V(N, 0), S;

void dfs(int v) {
    V[v] = 1;
    for (int u : A[v]) {
        if (!V[u]) dfs(u);
    }
    S.push_back(v);
}

void topo(int n) {
    V.assign(n, 0);
    S.clear();
    for (int i = 0; i < n; i++) {
        if (!V[i]) dfs(i);
    }
    reverse(S.begin(), S.end());
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        A[a-1].push_back(b-1);
    }
    topo(n);
    for (int i = 0; i < n; i++)
        cout << S[i]+1 << " ";
    cout << "\n";
}
