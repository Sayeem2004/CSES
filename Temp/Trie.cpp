#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#define mod 1000000007

struct Trie {
    bool isLeaf;
    unordered_map<char, Trie*> map;
};

Trie* getNewTrieNode() {
    Trie* node = new Trie;
    node->isLeaf = false;
    return node;
}

void insert(Trie*& head, char* str) {
    if (head == nullptr) head = getNewTrieNode();
    Trie* curr = head;
    while (*str) {
        if (curr->map.find(*str) == curr->map.end())
            curr->map[*str] = getNewTrieNode();
        curr = curr->map[*str];
        str++;
    }
    curr->isLeaf = true;
}

bool haveChildren(Trie const* curr) {
    for (auto it: curr->map) {
        if (it.second != nullptr)
            return true;
    }
    return false;
}

bool deletion(Trie*& curr, char* str) {
    if (curr == nullptr) return false;
    if (*str) {
        if (curr != nullptr && curr->map.find(*str) != curr->map.end() && deletion(curr->map[*str], str + 1) && curr->isLeaf == false) {
            if (!haveChildren(curr)) {
                delete curr;
                curr = nullptr;
                return true;
            } else return false;
        }
    }
    if (*str == '\0' && curr->isLeaf) {
        if (!haveChildren(curr)) {
            delete curr;
            curr = nullptr;
            return true;
        } else {
            curr->isLeaf = false;
            return false;
        }
    }
    return false;
}

bool search(Trie* head, char* str) {
    if (head == nullptr) return false;
    Trie* curr = head;
    while (*str) {
        curr = curr->map[*str];
        if (curr == nullptr) return false;
        str++;
    }
    return curr->isLeaf;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s; cin >> s;
    int n; cin >> n;
    Trie* head = nullptr;
    for (int i = 0; i < n; i++) {
        string a; cin >> a;
        insert(head, &a[0]);
    }
    vector<ll> DP(s.size()+1);
    DP[s.size()] = 1;
    for (int i = s.size()-1; i >= 0; i--) {
        for (int q = 1; q <= s.size()-i; q++) {
            string t = s.substr(i, q);
            if (search(head, &t[0])) {
                DP[i] += DP[i+q];
                DP[i] %= mod;
            }
        }
    }
    cout << DP[0] << "\n";
}
