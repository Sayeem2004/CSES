#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#define arr array

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<arr<int,2>> V(n);
    vector<arr<int,3>> S(n);
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        V[i] = {a,b};
        S[i] = {a,b,i};
    }
    sort(S.begin(),S.end());
    map<arr<int,3>,int> P;
    for (int i = 0; i < n; i++)
        P[S[i]] = i;
    int mx = 0, curr = 1;
    vector<int> A(n);
    A[0] = 1;
    priority_queue<arr<int,2>> PQ;
    PQ.push({-S[0][1], -curr});
    for (int i = 1; i < n; i++) {
        arr<int,2> room = PQ.top();
        if (-room[0] < S[i][0]) {
            PQ.pop();
            PQ.push({-S[i][1], room[1]});
            A[i] = -room[1];
        } else {
            curr++;
            PQ.push({-S[i][1], -curr});
            A[i] = curr;
        }
        mx = max(mx, curr);
    }
    cout << mx << "\n";
    for (int i = 0; i < n; i++)
        cout << A[P[{V[i][0],V[i][1],i}]] << " ";
    cout << "\n";
}
