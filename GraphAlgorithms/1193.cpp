#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#define arr array

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<bool>> C(n,vector<bool>(m));
    arr<int,2> start, end;
    for (int i = 0; i < n; i++) {
        for (int q = 0; q < m; q++) {
            char c; cin >> c;
            if (c == '#') continue;
            else {
                C[i][q] = true;
                if (c == 'A') {
                    start[0] = i;
                    start[1] = q;
                }
                if (c == 'B') {
                    end[0] = i;
                    end[1] = q;
                }
            }
        }
    }
    vector<vector<bool>> V(n, vector<bool>(m));
    vector<vector<arr<int,2>>> P(n, vector<arr<int,2>>(m, arr<int,2>{0,0}));
    vector<arr<int,2>> D = {{1,0},{0,1},{-1,0},{0,-1}};
    queue<arr<int,2>> Q;
    Q.push(start);
    while (!Q.empty()) {
        arr<int,2> point = Q.front();
        Q.pop();
        if (V[point[0]][point[1]]) continue;
        else V[point[0]][point[1]] = true;
        for (auto d : D) {
            int x = point[0] + d[0];
            int y = point[1] + d[1];
            if (x < 0 || x >= n || y < 0 || y >= m) continue;
            if (V[x][y] || !C[x][y]) continue;
            Q.push({x,y});
            P[x][y] = point;
        }
    }
    arr<int,2> prev = P[end[0]][end[1]];
    if (abs(prev[0]-end[0]) + abs(prev[1]-end[1]) != 1) cout << "NO" << "\n";
    else {
        cout << "YES" << "\n";
        int l = 1;
        string s;
        if (prev[0]-end[0] == 1) s = "U";
        if (prev[0]-end[0] == -1) s = "D";
        if (prev[1]-end[1] == 1) s = "L";
        if (prev[1]-end[1] == -1) s = "R";
        while (prev[0] != start[0] || prev[1] != start[1]) {
            arr<int,2> nw = P[prev[0]][prev[1]];
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
    }
}
