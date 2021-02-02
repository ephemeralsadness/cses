#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 100 * 1000;

vector<int> g[N + 1];
int passed[N + 1];
int memory[N + 1];

bool found = false;

void dfs(int v, int from) {
    if (found) return;
    if (passed[v]) {
        found = true;

        vector<int> p;
        p.push_back(v);
        while (from != v) {
            p.push_back(from);
            from = memory[from];
        }
        p.push_back(v);

        cout << p.size() << endl;
        for (auto c : p) {
            cout << c << ' ';
        }
        cout << endl;
    }

    memory[v] = from;
    passed[v] = true;
    for (auto to : g[v]) {
        if (to != from) {
            dfs(to, v);
        }
    }

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

    for (int i = 1; !found && i <= n; ++i) {
        if (!passed[i]) {
            dfs(i, 0);
        }
    }

    if (!found) {
        cout << "IMPOSSIBLE" << endl;
    }


    return 0;
}
