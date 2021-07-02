#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> A(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        A[a-1].push_back(b-1);
        A[b-1].push_back(a-1);
    }
    vector<bool> V(n);
    vector<int> P;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (V[i]) continue;
        ans++;
        P.push_back(i);
        queue<int> Q;
        Q.push(i);
        while (!Q.empty()) {
            int node = Q.front();
            Q.pop();
            if (V[node]) continue;
            V[node] = true;
            for (auto x : A[node]) {
                if (V[x]) continue;
                Q.push(x);
            }
        }
    }
    cout << ans-1 << "\n";
    for (int i = 1; i < P.size(); i++) {
        cout << P[0]+1 << " " << P[i]+1 << "\n";
    }
}
