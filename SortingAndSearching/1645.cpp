#include <bits/stdc++.h>
using namespace std;
#define int64 int64_t


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> v(n);
    stack<pair<int,int>> s;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 0; i < n; i++) {
        while (!s.empty() && s.top().first >= v[i])
            s.pop();
        if (s.empty()) cout << 0 << " ";
        else cout << s.top().second+1 << " ";
        s.push(make_pair(v[i],i));
    }
    cout << "\n";
}
