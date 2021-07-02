#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
vector<vector<int>> A(200000);
vector<int> S(200000,0);

void dfs(int node) {
    for (auto x : A[node]) {
        dfs(x);
        S[node] += S[x]+1;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i < n; i++) {
        int a; cin >> a;
        A[a-1].push_back(i);
    }
    dfs(0);
    for (int i = 0; i < n; i++) {
        cout << S[i] << " ";
    }
}
