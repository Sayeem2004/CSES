#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int N, M; std::cin >> N >> M;
    std::vector<std::vector<bool>> MVIS(N, std::vector<bool>(M, false));
    std::vector<std::vector<bool>> PVIS(N, std::vector<bool>(M, false));
    std::vector<std::pair<int, int>> DIRS = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    std::vector<std::pair<int, int>> MONS, EXITS;
    std::pair<int, int> START;

    for (int i = 0; i < N; i++) {
        std::string s; std::cin >> s;
        for (int q = 0; q < M; q++) {
            MVIS[i][q] = (s[q] == '#');
            PVIS[i][q] = (s[q] == '#');
            if (s[q] == 'M') MONS.push_back({i, q});
            if (s[q] == 'A') START = {i, q};
            if ((i == 0 || i == N - 1) && s[q] != '#') EXITS.push_back({i, q});
            else if ((q == 0 || q == M - 1) && s[q] != '#') EXITS.push_back({i, q});
        }
    }

    std::vector<std::vector<int>> MDIST(N, std::vector<int>(M, 1e9));
    std::queue<std::pair<int, int>> MQ;
    for (std::pair<int, int> mon : MONS) { MQ.push(mon); MDIST[mon.first][mon.second] = 0; }

    while (!MQ.empty()) {
        std::pair<int, int> node = MQ.front(); MQ.pop();
        if (MVIS[node.first][node.second]) continue;
        MVIS[node.first][node.second] = true;

        for (std::pair<int, int> dir : DIRS) {
            int nx = node.first + dir.first, ny = node.second + dir.second;
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

            if (MVIS[nx][ny]) continue;
            if (MDIST[nx][ny] <= MDIST[node.first][node.second] + 1) continue;

            MDIST[nx][ny] = MDIST[node.first][node.second] + 1;
            MQ.push({nx, ny});
        }
    }

    std::vector<std::vector<int>> PDIST(N, std::vector<int>(M, 1e9));
    std::vector<std::vector<std::pair<int, int>>> PREV(N, std::vector<std::pair<int, int>>(M, {-1, -1}));
    std::queue<std::pair<int, int>> PQ;
    PQ.push(START); PDIST[START.first][START.second] = 0;

    while (!PQ.empty()) {
        std::pair<int, int> node = PQ.front(); PQ.pop();
        if (PVIS[node.first][node.second]) continue;
        PVIS[node.first][node.second] = true;

        for (std::pair<int, int> dir : DIRS) {
            int nx = node.first + dir.first, ny = node.second + dir.second;
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

            if (PVIS[nx][ny]) continue;
            if (PDIST[nx][ny] <= PDIST[node.first][node.second] + 1) continue;
            if (MDIST[nx][ny] <= PDIST[node.first][node.second] + 1) continue;

            PDIST[nx][ny] = PDIST[node.first][node.second] + 1;
            PREV[nx][ny] = node; PQ.push({nx, ny});
        }
    }

    for (std::pair<int, int> exit : EXITS) {
        if (PDIST[exit.first][exit.second] == 1e9) continue;
        if (exit.first == START.first && exit.second == START.second) {
            std::cout << "YES\n"; std::cout << 0 << "\n"; return 0;
        }

        if (PREV[exit.first][exit.second].first == -1) continue;
        if (PREV[exit.first][exit.second].second == -1) continue;

        std::string ANS = "";
        while (exit.first != START.first || exit.second != START.second) {
            std::pair<int, int> prev = PREV[exit.first][exit.second];
            if (prev.first == exit.first) { ANS += (prev.second < exit.second ? "R" : "L"); }
            else { ANS += (prev.first < exit.first ? "D" : "U"); }
            exit = prev;
        }

        std::reverse(ANS.begin(), ANS.end());
        std::cout << "YES\n"; std::cout << ANS.size() << "\n"; std::cout << ANS << "\n";
    }

    std::cout << "NO\n";
}
