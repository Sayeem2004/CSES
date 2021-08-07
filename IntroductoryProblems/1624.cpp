#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

vector<vector<int>> B(8, vector<int>(8));
int ans = 0;
vector<int> C(8), D1(15), D2(15);

void solve(int y) {
    if (y == 8) {
        ans++;
    } else {
        for (int x = 0; x < 8; x++) {
            if (C[x] || B[x][y] || D1[x+y] || D2[x-y+7]) continue;
            C[x] = D1[x+y] = D2[x-y+7] = 1;
            solve(y+1);
            C[x] = D1[x+y] = D2[x-y+7] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    for (int i = 0; i < 8; i++) {
        for (int q = 0; q < 8; q++) {
            char c; cin >> c;
            if (c == '*') B[i][q] = 1;
        }
    }
    solve(0);
    cout << ans << "\n";
}
