//  C. Cadenas sin repeticiones consecutivas
/**
 * Problem: C_Cadenas_sin_repeticiones_consecutivas.cpp
 * Date:    14/08/26
 * Compile: g++ -std=c++23 -O2 C_Cadenas_sin_repeticiones_consecutivas.cpp -o out
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
    ll length, k_symb;
    cin >> length >> k_symb;

    ll ans = 1;

	if (length == 1) {
        cout << k_symb % mod << "\n";
	    return;
	} else {
        ans = (k_symb % mod) * exp_bin(k_symb - 1, length - 1) % mod;
        cout << ans << "\n";
	    return;
    }

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