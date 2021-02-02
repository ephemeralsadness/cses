#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 1000;
const int M = 1000;
int n;
int m;

char field[N][M];
bool passed[N][M];

void dfs(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m) return;
    if (passed[i][j]) return;
    if (field[i][j] != '.') return;
    passed[i][j] = true;

    dfs(i - 1, j);
    dfs(i + 1, j);
    dfs(i, j - 1);
    dfs(i, j + 1);
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout.setf(ios::fixed); cout.precision(20);
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> field[i][j];
        }
    }

    int ctr = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!passed[i][j] && field[i][j] == '.') {
                dfs(i, j);
                ++ctr;
            }
        }
    }

    cout << ctr << endl;

    return 0;
}
