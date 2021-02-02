#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 100 * 1000;

vector<int> g[N + 1];
int colors[N + 1];

bool dfs(int v, int color) {
    if (colors[v] == color) return true;
    if (colors[v] == 3 - color) return false;

    colors[v] = color;
    bool alpha = true;
    for (auto c : g[v]) {
        alpha &= dfs(c, 3 - color);
    }

    return alpha;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout.setf(ios::fixed); cout.precision(20);
    // freopen("test_input.txt", "r", stdin); // freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    bool alpha = true;
    for (int i = 1; i <= n; ++i) {
        if (colors[i] == 0) {
            alpha &= dfs(i, 1);
        }
    }

    if (alpha) {
        for (int i = 1; i <= n; ++i) {
            cout << colors[i] << ' ';
        }
        cout << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}
