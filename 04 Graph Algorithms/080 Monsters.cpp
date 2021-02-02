#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

char field[1000][1000];
bool monsters[1000][1000];
char memory[1000][1000];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout.setf(ios::fixed); cout.precision(20);
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    int n, m; cin >> n >> m;

    queue<pii> enemies;
    queue<pair<pii, char>> player;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> field[i][j];
            if (field[i][j] == 'M') {
                enemies.emplace(i, j);
                field[i][j] = '.';
            } else if (field[i][j] == 'A') {
                player.emplace(pii{i, j}, 'X');
                field[i][j] = '.';
            }
        }
    }

    while (!player.empty()) {
        queue<pii> new_enemies;
        while (!enemies.empty()) {
            auto [x, y] = enemies.front();
            enemies.pop();

            if (x < 0 || x >= n || y < 0 || y >= m || field[x][y] == '#' || monsters[x][y])
                continue;
            monsters[x][y] = true;

            new_enemies.emplace(x + 1, y);
            new_enemies.emplace(x - 1, y);
            new_enemies.emplace(x, y + 1);
            new_enemies.emplace(x, y - 1);
        }

        enemies = move(new_enemies);

        queue<pair<pii, char>> new_player;
        while (!player.empty()) {
            auto [x, y] = player.front().first;
            auto mem = player.front().second;
            player.pop();

            if (x < 0 || x >= n || y < 0 || y >= m) {
                if (x < 0) ++x;
                else if (x >= n) --x;
                else if (y < 0) ++y;
                else --y;

                string answer;
                while (memory[x][y] != 'X') {
                    answer.push_back(memory[x][y]);
                    if (memory[x][y] == 'R') --y;
                    else if (memory[x][y] == 'L') ++y;
                    else if (memory[x][y] == 'U') ++x;
                    else --x;
                }
                reverse(answer.begin(), answer.end());

                cout << "YES" << endl;
                cout << answer.size() << endl;
                cout << answer << endl;

                return 0;
            }

            if (field[x][y] == '#' || memory[x][y] || monsters[x][y]) continue;

            memory[x][y] = mem;

            new_player.emplace(pii{x + 1, y}, 'D');
            new_player.emplace(pii{x - 1, y}, 'U');
            new_player.emplace(pii{x, y + 1}, 'R');
            new_player.emplace(pii{x, y - 1}, 'L');

        }

        player = move(new_player);
    }

    cout << "NO" << endl;

    return 0;
}
