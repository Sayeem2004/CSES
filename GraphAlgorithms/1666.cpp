#include <bits/stdc++.h>

template<typename T> struct disjoint_set {
    std::unordered_map<T, T> TREE; std::unordered_map<T, int> SIZE; // Variables
    disjoint_set(std::vector<T> V = {}) { for (T x : V) add(x); } // Constructor

    bool add(T x) { return TREE.count(x) ? 0 : (TREE[x] = x, SIZE[x] = 1); } // Mutators
    bool unite(T x, T y) { x = get(x), y = get(y); // Union by size
        if (x == y) return 0; if (SIZE[x] < SIZE[y]) swap(x, y);
        TREE[y] = x; SIZE[x] += SIZE[y]; return 1; }

    int size(T x) { return SIZE[get(x)]; } // Accessors
    bool same(T x, T y) { return get(x) == get(y); }
    T get(T x) { return TREE[x] == x ? x : TREE[x] = get(TREE[x]); }
    void print() { for (auto i = TREE.begin(); i != TREE.end(); i++)
        std::printf("%d -> {%d} (%d)\n", i->first, get(i->first), size(i->first)); }
};

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int N, M; std::cin >> N >> M;
    disjoint_set<int> DS;
    for (int i = 0; i < N; i++) DS.add(i);

    for (int i = 0; i < M; i++) {
        int a, b; std::cin >> a >> b;
        DS.unite(a - 1, b - 1);
    }

    int ans = 0;
    std::vector<int> ANS;
    for (int i = 0; i < N; i++) {
        if (DS.same(0, i)) continue;
        ans++; ANS.push_back(i + 1);
        DS.unite(0, i);
    }

    std::cout << ans << "\n";
    for (int x : ANS) std::cout << 1 << " " << x << "\n";
}
