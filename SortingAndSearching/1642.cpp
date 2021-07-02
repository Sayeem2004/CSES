#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#define arr array

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, x; cin >> n >> x;
    vector<int> V(n);
    for (int i = 0; i < n; i++)
        cin >> V[i];
    vector<arr<int,2>> S;
    map<arr<int,2>,arr<int,2>> P;
    int t = 0;
    for (int i = 0; i < n-1; i++) {
        for (int q = i+1; q < n; q++) {
            S.push_back({V[i]+V[q], t});
            P[{V[i]+V[q], t}] = {i,q};
            t++;
        }
    }
    sort(S.begin(),S.end());
    int i = 0, j = S.size()-1;
    while (i < j) {
        if (S[i][0]+S[j][0] < x) i++;
        else if (S[i][0]+S[j][0] > x) j--;
        else {
            set<int> T;
            T.insert(P[S[i]][0]);
            T.insert(P[S[i]][1]);
            T.insert(P[S[j]][0]);
            T.insert(P[S[j]][1]);
            if (T.size() == 4) {
                cout << P[S[i]][0]+1 << " ";
                cout << P[S[i]][1]+1 << " ";
                cout << P[S[j]][0]+1 << " ";
                cout << P[S[j]][1]+1 << "\n";
                return 0;
            } else if (S[i+1][0] == S[i][0]) i++;
            else if (S[j-1][0] == S[j][0]) j--;
            else i++;
        }
    }
    cout << "IMPOSSIBLE\n";
}
