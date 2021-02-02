#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout.setf(ios::fixed); cout.precision(20);
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    int n; cin >> n;
    vector<tuple<int, bool, int>> v(n * 2);
    for (int i = 0; i < n; ++i) {
        int a, b; cin >> a >> b;
        v[i * 2] = {a, false, i};
        v[i * 2 + 1] = {b, true, i};
    }
    sort(v.begin(), v.end());

    int rooms_amount = 0;
    vector<int> room_numbers(n);
    vector<int> rooms(n);
    set<int> free_rooms;
    for (int i = 0; i < n * 2; ++i) {
        auto [tm, is_departure, index] = v[i];
        if (is_departure) {
            free_rooms.insert(room_numbers[index]);
        } else {
            if (free_rooms.empty()) {
                room_numbers[index] = rooms_amount;
                ++rooms_amount;
            } else {
                room_numbers[index] = *free_rooms.begin();
                free_rooms.erase(free_rooms.begin());
            }
        }
    }

    cout << rooms_amount << endl;
    for (int i = 0; i < n; ++i) {
        cout << room_numbers[i] + 1 << ' ';
    }


    return 0;
}
