#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 8;
char field[N][N];

int ways_to_place(int i) {
    if (i == N) return 1;

    int sm = 0;
    for (int j = 0; j < N; ++j) {
        if (field[i][j] == '.') {
            bool can_place = true;

            for (int k = 1; i - k >= 0 && j - k >= 0; ++k) {
                if (field[i - k][j - k] == 'Q') can_place = false;
            }
            for (int k = 1; i - k >= 0 && j + k < N; ++k) {
                if (field[i - k][j + k] == 'Q') can_place = false;
            }
            for (int k = 1; i - k >= 0; ++k) {
                if (field[i - k][j] == 'Q') can_place = false;
            }

            if (can_place) {
                field[i][j] = 'Q';
                sm += ways_to_place(i + 1);
                field[i][j] = '.';
            }
        }
    }

    return sm;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout.setf(ios::fixed); cout.precision(20);
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> field[i][j];
        }
    }

    cout << ways_to_place(0) << endl;


    return 0;
}
