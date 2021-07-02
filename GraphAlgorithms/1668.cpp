#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
vector<vector<int>> A(200000);
vector<int> T(200000);
bool e = false;

void dfs(int node, int team) {
    T[node] = team;
    for (auto x : A[node]) {
        if (T[x] == 0)
            dfs(x, 3-team);
        if (T[x] == T[node]) e = true;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        A[a-1].push_back(b-1);
        A[b-1].push_back(a-1);
    }
    for (int i = 0; i < n; i++) {
        if (T[i] == 0)
            dfs(i, 1);
    }
    if (e) {
        cout << "IMPOSSIBLE\n";
    } else {
        for (int i = 0; i < n; i++)
            cout << T[i] << " ";
        cout << "\n";
    }
}
