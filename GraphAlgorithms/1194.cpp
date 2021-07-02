#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#define arr array

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n, m; cin >> n >> m;
    if (n == 1 || m == 1) {
        cout << "YES\n";
        cout << 0 << "\n";
        return 0;
    }
    vector<vector<bool>> C(n,vector<bool>(m));
    arr<ll,2> person;
    vector<arr<ll,2>> monsters;
    vector<arr<ll,2>> exits;
    for (int i = 0; i < n; i++) {
        for (int q = 0; q < m; q++) {
            char c; cin >> c;
            if (c == '#') continue;
            else {
                C[i][q] = true;
                if (c == 'A') {
                    person = {i, q};
                }
                if (c == 'M') {
                    monsters.push_back({i, q});
                }
                if (i == n-1 || i == 0 || q == m-1 || q == 0) {
                    exits.push_back({i, q});
                }
            }
        }
    }
    vector<vector<ll>> MD(n, vector<ll>(m, 1e18));
    vector<arr<ll,2>> M = {{1,0},{0,1},{-1,0},{0,-1}};
    vector<vector<bool>> MV(n, vector<bool>(m));
    queue<arr<ll,2>> MQ;
    for (auto x : monsters) {
        MD[x[0]][x[1]] = 0;
        MQ.push(x);
    }
    while (!MQ.empty()) {
        arr<ll,2> node = MQ.front();
        MQ.pop();
        if (MV[node[0]][node[1]]) continue;
        MV[node[0]][node[1]] = true;
        for (auto d : M) {
            int x = node[0] + d[0];
            int y = node[1] + d[1];
            if (x < 0 || x >= n || y < 0 || y >= m) continue;
            if (MV[x][y] || !C[x][y]) continue;
            MQ.push({x,y});
            MD[x][y] = min(MD[x][y], MD[node[0]][node[1]]+1);
        }
    }
    vector<vector<ll>> D(n, vector<ll>(m, 1e18));
    vector<vector<bool>> V(n, vector<bool>(m));
    queue<arr<ll,2>> Q;
    vector<vector<arr<ll,2>>> P(n, vector<arr<ll,2>>(m, arr<ll,2>{-1,-1}));
    D[person[0]][person[1]] = 0;
    Q.push(person);
    while (!Q.empty()) {
        arr<ll,2> point = Q.front();
        Q.pop();
        if (V[point[0]][point[1]]) continue;
        V[point[0]][point[1]] = true;
        for (auto d : M) {
            ll x = point[0] + d[0];
            ll y = point[1] + d[1];
            if (x < 0 || x >= n || y < 0 || y >= m) continue;
            if (V[x][y] || !C[x][y]) continue;
            D[x][y] = min(D[x][y], D[point[0]][point[1]]+1);
            if (D[x][y] >= MD[x][y]) continue;
            Q.push({x,y});
            P[x][y] = point;
        }
    }
    for (auto e : exits) {
        arr<ll,2> prev = P[e[0]][e[1]];
        if (abs(prev[0]-e[0]) + abs(prev[1]-e[1]) != 1) continue;
        else {
            cout << "YES" << "\n";
            int l = 1;
            string s;
            if (prev[0]-e[0] == 1) s = "U";
            if (prev[0]-e[0] == -1) s = "D";
            if (prev[1]-e[1] == 1) s = "L";
            if (prev[1]-e[1] == -1) s = "R";
            while (prev[0] != person[0] || prev[1] != person[1]) {
                arr<ll,2> nw = P[prev[0]][prev[1]];
                if (nw[0]-prev[0] == 1) s += "U";
                if (nw[0]-prev[0] == -1) s += "D";
                if (nw[1]-prev[1] == 1) s += "L";
                if (nw[1]-prev[1] == -1) s += "R";
                l++;
                prev = nw;
            }
            cout << l << "\n";
            reverse(s.begin(),s.end());
            cout << s << "\n";
            return 0;
        }
    }
    cout << "NO" << "\n";
}
