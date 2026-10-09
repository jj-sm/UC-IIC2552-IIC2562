//  C. Completar cuadrados
/**
 * Problem: C_Completar_cuadrados.cpp
 * Date:    27/08/26
 * Compile: g++ -std=c++23 -O2 C_Completar_cuadrados.cpp -o out
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

bool perfect_sqrt(int n) {
    int root = static_cast<int>(sqrt(n));
    return root * root == n;
}

void solve() {
    int x;
    cin >> x;

    map<int, int> m;

    for (int p = 2; p * p <= x; p++) {
        if (x % p == 0) {

            int exp = 0;
            while (x % p == 0) {
                exp++;
                x /= p;
            }
            m[p] = exp;
        }
    }

    if (x > 1) {
        m[x]++;
    }

    vi odd_exp_bases;

    for (auto u: m) {
        int base = u.first;
        int exp = u.second;

        if (exp % 2 != 0) {
            odd_exp_bases.pb(base);
        }
    }

    int ans = 1;

    for (int i = 0; i < odd_exp_bases.size(); i++) {
        ans *= odd_exp_bases[i];
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
