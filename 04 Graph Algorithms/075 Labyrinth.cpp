#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 1000;
const int M = 1000;

char field[N][M];
char from[N][M];


int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout.setf(ios::fixed); cout.precision(20);
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> field[i][j];
        }
    }

    pii a_coords, b_coords;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (field[i][j] == 'A') {
                a_coords = {i, j};
            }
            if (field[i][j] == 'B') {
                b_coords = {i, j};
            }
        }
    }

    queue<pair<pii, char>> q;
    q.emplace(a_coords, 0);

    while (!q.empty()) {
        auto [i, j] = q.front().first;
        auto c = q.front().second;
        q.pop();

        if (i < 0 || i >= n || j < 0 || j >= m)
            continue;
        if (field[i][j] == '#')
            continue;
        if (from[i][j] != 0)
            continue;

        from[i][j] = c;

        q.emplace(pii{i - 1, j}, 'U');
        q.emplace(pii{i + 1, j}, 'D');
        q.emplace(pii{i, j - 1}, 'L');
        q.emplace(pii{i, j + 1}, 'R');

    }

    if (from[b_coords.first][b_coords.second] == 0) {
        cout << "NO" << endl;
    } else {
        string path;
        auto [i, j] = b_coords;
        from[a_coords.first][a_coords.second] = 0;
        while (from[i][j] != 0) {
            path.push_back(from[i][j]);
            if (from[i][j] == 'U') i = i + 1;
            else if (from[i][j] == 'D') i = i - 1;
            else if (from[i][j] == 'L') j = j + 1;
            else j = j - 1;
        }

        reverse(path.begin(), path.end());

        cout << "YES" << endl;
        cout << path.size() << endl;
        cout << path << endl;
    }

    return 0;
}
