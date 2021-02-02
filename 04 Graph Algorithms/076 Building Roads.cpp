#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 100 * 1000;

vector<int> g[N + 1];
bool passed[N + 1];

void dfs(int n) {
    if (passed[n]) return;
    passed[n] = true;
    for (auto v : g[n]) {
        dfs(v);
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout.setf(ios::fixed); cout.precision(20);
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> cities;
    for (int i = 1; i <= n; ++i) {
        if (!passed[i]) {
            dfs(i);
            cities.push_back(i);
        }
    }

    cout << (int)cities.size() - 1 << endl;
    for (int i = 1; i < (int)cities.size(); ++i) {
        cout << cities[i - 1] << ' ' << cities[i] << endl;
    }

    return 0;
}
