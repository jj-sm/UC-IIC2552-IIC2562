//  B. Cristian Ruz, su propio jefe
/**
 * Problem: B_Cristian_Ruz_su_propio_jefe.cpp
 * Date:    14/08/26
 * Compile: g++ -std=c++23 -O2 B_Cristian_Ruz_su_propio_jefe.cpp -o out
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

ll mod = 998244353;

ll exp_bin(ll base, ll exp) {
    ll ans = 1;

    if (exp == 0) {
        return ans;
    }

    base %= mod;

    while (exp > 0) {
        if (exp % 2 == 1) {
            ans = ans * base % mod;
        }
        base = base * base % mod;
        exp /= 2;
    }
    return ans;
}

void solve() {
    ll a, n, r;
    cin >> a >> r >> n;

    if (n == 0) {
        cout << a % mod << "\n";
        return;
    }

    ll exp = exp_bin(r, n);
    ll ans = ((a % mod) * exp) % mod;

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t; 
    while(t--) {
        solve();
    }
    return 0;
}