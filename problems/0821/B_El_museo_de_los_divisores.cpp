//  B. El museo de los divisores
/**
 * Problem: B_El_museo_de_los_divisores.cpp
 * Date:    21/08/26
 * Compile: g++ -std=c++23 -O2 B_El_museo_de_los_divisores.cpp -o out
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


ll highest_exp(ll n) {
    map<ll, ll> m;

    for (ll p = 2; p * p <= n; p++) {
        if (n % p == 0) {

            ll exp = 0;
            while (n % p == 0) {
                exp++;
                n /= p;
            }

            m[p] = exp;


        }
    }
    if (n > 1) {
        m[n]++;
    }

    if (m.empty()) return 1;

    ll ans = 1;

    for (auto u: m) {
        ll base = u.first;
        ll exp = u.second;

        // cout << base << "^" << exp << endl;

        ll temp = exp;
        temp *= 2;
        temp++;
        ans *= temp;
        // cout << ans << endl;
    }

    return ans;

}

void solve() {
    ll in;
    cin >> in;

    ll answer = highest_exp(in);
    cout << answer << endl;
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
