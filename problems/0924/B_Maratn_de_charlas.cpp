//  B. Maratón de charlas
/**
 * Problem: B_Maratn_de_charlas.cpp
 * Date:    8/10/26
 * Compile: g++ -std=c++23 -O2 B_Maratn_de_charlas.cpp -o out
 * Run:     ./out < input.txt
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

// --- Macros ---
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define sz(x) (int)(x).size()
#define fi first
#define se second

void solve() {
    ll n_charlas, d_tiempo;
    cin >> n_charlas >> d_tiempo;

    vector<pll> schedule(n_charlas);

    for (int i = 0; i < n_charlas; i++) {
        ll s, f;
        cin >> s >> f;

        schedule[i].first = s;
        schedule[i].second = f + d_tiempo;
    }

    // sort(schedule.begin(), schedule.end());

    sort(all(schedule), [](const pll& a, const pll& b) {
        return a.second < b.second;
    });


    int chosen = 0;
    ll free_from = 0;

    for (auto [s,f] : schedule) {
        if (s >= free_from) {
            free_from = f;
            chosen++;
        }
    }

    cout << chosen;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t; 
    while (t--) {
        solve();
    }
    return 0;
}
