#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>> room;
int n, m;

void rmap(int x, int y) {
    if (room[x][y] == 0) {
        room[x][y] = 1;
        if (x < n-1) rmap(x+1,y);
        if (x > 0) rmap(x-1,y);
        if (y < m-1) rmap(x,y+1);
        if (y > 0) rmap(x,y-1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    vector<vector<int>> v(n);
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        vector<int> temp(m);
        for (int q = 0; q < m; q++) {
            if (s[q] == '#') temp[q] = 1;
            else temp[q] = 0;
        }
        v[i] = temp;
    }
    room = v;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int q = 0; q < m; q++) {
            if (room[i][q] == 0) {
                ans++;
                rmap(i,q);
            }
        }
    }
    cout << ans << "\n";
}
