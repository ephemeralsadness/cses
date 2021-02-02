#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int m = 'z' - 'a' + 1;
int letters[m];
string result;
vector<string> all;

void rec(int index) {
    if (index >= result.size()) {
        all.push_back(result);
    } else {
        for (int i = 0; i < m; ++i) {
            if (letters[i]) {
                --letters[i];
                result[index] = 'a' + i;
                rec(index + 1);
                ++letters[i];
            }
        }
    }
}


int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout.setf(ios::fixed); cout.precision(20);
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    string s; cin >> s;
    for (char c : s) {
        ++letters[c - 'a'];
    }
    result.resize(s.size(), ' ');

    rec(0);

    cout << all.size() << endl;
    for (string& t : all) {
        cout << t << '\n';
    }

    return 0;
}
