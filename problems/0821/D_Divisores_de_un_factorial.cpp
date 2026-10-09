//  D. Divisores de un factorial
/**
 * Problem: D_Divisores_de_un_factorial.cpp
 * Date:    27/08/26
 * Compile: g++ -std=c++23 -O2 D_Divisores_de_un_factorial.cpp -o out
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

// int mod = 1;
ll mod_ans = 1000000007;

ll exp_pow(ll base, ll exp) {
    ll ans = 1;

    if (exp == 0) {
        return ans;
    }

    // base %= mod;

    while (exp > 0) {
        if (exp % 2 == 1) {
            ans = ans * base;
        }
        base = base * base;
        exp /= 2;
    }
    return ans;
}

bool check_prime(int n) {
    if(n < 2) return false;
    for(int i = 2; i * i <= n; i++){
        if (n % i == 0) return false;
    }
    return true;
}

int find_p_exp(int n, int p) {
    int ans = 0;
    int current = 1;
    int exp = 1;

    while (current > 0) {
        current = n / exp_pow(p, exp);
        ans += current;
        exp++;
    }
    return ans;
}

void solve() {
    int x;
    cin >> x;
    ll ans = 1;

    for (int i = 2; i <= x; i++) {
        if (check_prime(i)) {
            int exp = find_p_exp(x, i);
            ans = ans * (exp + 1) % mod_ans;
        }
    }

    ans %= mod_ans;

    cout << ans << "\n";
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
