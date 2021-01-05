#include <bits/stdc++.h>
using namespace std;
#define int64 int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, x; cin >> n >> x;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<pair<int,int>> p(n*(n-1)/2);
    vector<pair<int,int>> ind(n*(n-1)/2);
    int t = 0;
    for (int i = 0; i < n-1; i++) {
        for (int q = i+1; q < n; q++) {
            p[t] = make_pair(v[i]+v[q],t);
            ind[t] = make_pair(i,q);
            t++;
        }
    }
    sort(p.begin(),p.end());
    int i = 0, j = p.size()-1;
    bool br = true;
    while (i < j) {
        if (p[i].first+p[j].first < x) {
            i++;
        } else if (p[i].first+p[j].first > x) {
            j--;
        } else {
            set<int64> s;
            s.insert(ind[p[i].second].first);
            s.insert(ind[p[i].second].second);
            s.insert(ind[p[j].second].first);
            s.insert(ind[p[j].second].second);
            if (s.size() == 4) {
                cout << ind[p[i].second].first+1 << " ";
                cout << ind[p[i].second].second+1 << " ";
                cout << ind[p[j].second].first+1 << " ";
                cout << ind[p[j].second].second+1 << "\n";
                br = false; break;
            } else {
                i++;
            }
        }
    }
    if (br) cout << "IMPOSSIBLE" << "\n";
}
