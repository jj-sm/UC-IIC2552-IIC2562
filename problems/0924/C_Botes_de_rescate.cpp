//  C. Botes de rescate
/**
 * Problem: C_Botes_de_rescate.cpp
 * Date:    9/10/26
 * Compile: g++ -std=c++23 -O2 C_Botes_de_rescate.cpp -o out
 * Run:     ./out < input.txt
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <iomanip>
#include <numeric>

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
    ll n_personas, L_MAX_WEIGHT;
    cin >> n_personas >> L_MAX_WEIGHT;

    vll weights_overlimit;
    vll weights_under_limit;
    int n_boats = 0;


    for (int i = 0; i < n_personas; i++) {
        ll temp_weight;
        cin >> temp_weight;

        if (temp_weight >= L_MAX_WEIGHT) {
            weights_overlimit.pb(temp_weight);
            n_boats++;
        } else {
            weights_under_limit.pb(temp_weight);
        }
    }

    sort(all(weights_under_limit));
    deque<ll> dq(all(weights_under_limit));
    int n_pp = size(weights_under_limit);

    int init_idx = 0;
    while (n_pp >= 1) {
        ll first = dq.front();
        ll last  = dq.back();

        if ((first + last) <= L_MAX_WEIGHT) {
            n_boats++;
            dq.pop_back();
            dq.pop_front();
            n_pp -= 2;
        } else {
            n_boats++;
            dq.pop_back();
            n_pp--;
        }
    }

    cout << n_boats;


    // 20 30 40 50 60 70 80 90 100 110 120
    // max 100: 20 + 90

    // 100 120 110 out = 3
    // 20 30 40 50 60 70 80 90
    // tries 20 + 90 < 100, -> FALSE -> 90 n += 1 and pop
    // tries 20 + 80 < 100, -> TRUE -> pop both n += 1
    // tries 30 + 70 ok
    // ties 40 + 60
    // tries 50 ok



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
