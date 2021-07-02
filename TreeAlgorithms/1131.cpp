#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    if (n <= 1) {
        cout << 0 << "\n";
        return 0;
    }
    vector<vector<int>> A(n);
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        A[a-1].push_back(b-1);
        A[b-1].push_back(a-1);
    }
    vector<int> D(n);
    vector<bool> V(n);
    queue<int> Q;
    D[0] = 0;
    Q.push(0);
    while (!Q.empty()) {
        int node = Q.front();
        Q.pop();
        if (V[node]) continue;
        V[node] = true;
        for (auto x : A[node]) {
            if (V[x]) continue;
            Q.push(x);
            D[x] = max(D[x],D[node]+1);
        }
    }
    int mx = 0, pos = -1;
    for (int i = 0; i < n; i++) {
        if (D[i] > mx) {
            mx = D[i];
            pos = i;
        }
    }
    vector<int> D2(n);
    vector<bool> V2(n);
    queue<int> Q2;
    D2[pos] = 0;
    Q2.push(pos);
    while (!Q2.empty()) {
        int node = Q2.front();
        Q2.pop();
        if (V2[node]) continue;
        V2[node] = true;
        for (auto x : A[node]) {
            if (V2[x]) continue;
            Q2.push(x);
            D2[x] = max(D2[x],D2[node]+1);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, D2[i]);
    cout << ans << "\n";
}
