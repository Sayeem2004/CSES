#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 7;
bool V[N+2][N+2];
const int Dx[] = {1, -1, 0, 0}, Dy[] = {0, 0, 1, -1};

int solve(string& s, int itr, int x, int y) {
    if (x == N && y == 1) return (itr == N*N-1);
    if (itr == N*N-1) return 0;

    if (((V[x][y+1] && V[x][y-1]) && (!V[x-1][y] && !V[x+1][y])) ||
        ((V[x+1][y] && V[x-1][y]) && (!V[x][y-1] && !V[x][y+1]))) return 0;

    V[x][y] = 1;
    int res = 0;
    for (int i = 0; i < 4; i++) {
        if (s[itr] == 'D' && i != 0) continue;
        if (s[itr] == 'U' && i != 1) continue;
        if (s[itr] == 'R' && i != 2) continue;
        if (s[itr] == 'L' && i != 3) continue;
        int nx = x+Dx[i], ny = y+Dy[i];
        if (nx >= 1 && nx <= N && ny >= 1 && ny <= N && !V[nx][ny])
            res += solve(s, itr+1, nx, ny);
    }
    V[x][y] = 0;
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s; cin >> s;
    for (int i = 0; i <= N+1; i++) {
        for (int q = 0; q <= N+1; q++) {
            if (i == 0 || q == 0 || i == N+1 || q == N+1)
                V[i][q] = 1;
        }
    }
    cout << solve(s, 0, 1, 1) << "\n";
}
