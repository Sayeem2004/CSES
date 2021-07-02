#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
vector<bool> V(100000);
vector<int> P(100000, -1);
vector<vector<int>> A(100000, vector<int>());
int s = -1, e = -1;

bool dfs(int v, int p) {
    V[v] = true;
    P[v] = p;
    bool f = false;
    for (auto x : A[v]) {
        if (x == p) continue;
        if (V[x]) {
            e = v;
            s = x;
            return true;
        }
        if (!V[x]) {
            f = f || dfs(x, v);
            if (f) break;
        }
    }
    return f;
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
        if (!V[i]) {
            bool f = dfs(i, -1);
            if (f) {
                vector<int> O;
                O.push_back(e);
                int prev = P[e];
                while (prev != P[s]) {
                    O.push_back(prev);
                    prev = P[prev];
                }
                cout << O.size()+1 << "\n";
                for (int i = O.size()-1; i >= 0; i--)
                    cout << O[i]+1 << " ";
                cout << s+1 << "\n";
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}
