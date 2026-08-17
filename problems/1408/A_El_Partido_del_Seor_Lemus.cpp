//  A. El Partido del Señor Lemus
/**
 * Problem: A_El_Partido_del_Seor_Lemus.cpp
 * Date:    14/08/26
 * Compile: g++ -std=c++23 -O2 A_El_Partido_del_Seor_Lemus.cpp -o out
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

int mod = 998244353;



void solve() {
    ll ans = 1;
    ll a, b;
    cin >> a >> b;

    if (b == 0) {
        cout << ans << "\n";
        return;
    }

    a %= mod;

    while (b > 0) {
        if (b % 2 == 1) {
            ans = ans * a % mod;
        }
        a = a * a % mod;
        b /= 2;
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}