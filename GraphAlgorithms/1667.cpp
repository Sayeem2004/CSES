#include <bits/stdc++.h>
using namespace std;
#define ll int64_t


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> A(n, vector<int>(0));
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        A[a-1].push_back(b-1);
        A[b-1].push_back(a-1);
    }
    vector<bool> V(n);
    vector<int> P(n, -1);
    vector<int> D(n, 2000000000);
    queue<int> Q;
    Q.push(0);
    D[0] = 0;
    while (!Q.empty()) {
        int node = Q.front();
        Q.pop();
        if (V[node]) continue;
        V[node] = true;
        for (auto x : A[node]) {
            if (V[x]) continue;
            if (D[node]+1 < D[x]) {
                D[x] = D[node]+1;
                P[x] = node;
                Q.push(x);
            }
        }
    }
    if (D[n-1] == 2000000000) cout << "IMPOSSIBLE\n";
    else {
        vector<int> PT;
        int prev = n-1;
        int l = 1;
        while (prev != 0) {
            PT.push_back(prev);
            prev = P[prev];
            l++;
        }
        reverse(PT.begin(),PT.end());
        cout << l << "\n";
        cout << 1 << " ";
        for (auto x : PT)
            cout << x+1 << " ";
        cout << "\n";
    }
}
