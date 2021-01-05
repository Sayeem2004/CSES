#include <bits/stdc++.h>
using namespace std;
#define int64 int64_t

int64 n, p;
vector<int64> v(2e5);

void solve() {
    int64 low = 1, high = p*v[0], mid;
    for (int64 i = 0; i < 100; i++) {
        mid = low+(high-low)/2;
        int64 check = 0;
        for (int64 q = 0; q < n; q++)
            check += mid/v[q];
        if (check < p) low = mid+1;
        else high = mid-1;
    }
    cout << mid << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> p;
    for (int64 i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(),v.begin()+n);
    solve();
}
