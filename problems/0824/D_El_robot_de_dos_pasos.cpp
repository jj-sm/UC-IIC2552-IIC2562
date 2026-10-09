//  D. El robot de dos pasos
/**
 * Problem: D_El_robot_de_dos_pasos.cpp
 * Date:    28/08/26
 * Compile: g++ -std=c++23 -O2 D_El_robot_de_dos_pasos.cpp -o out
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

long long gcd_euclides(long long a, long long b) {
    a = abs(a); b = abs(b);
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long extended_gcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long g = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}

long long mod_inverse(long long a, long long m) {
    long long x, y;
    long long g = extended_gcd(a, m, x, y);
    if (g != 1) return -1;
    return ((x % m) + m) % m; // Normalizamos para evitar residuos negativos en C++
}


void solve() {
    ll l, a, b;
    cin >> l >> a >> b;

    // --- a + b = l
    if (a + b == l) {
        cout << "2" << "\n";
        return;
    }

    // ---- Sólo uno divide
    ll max;
    if (a > b) {
        max = a;
    } else {
        max = b;
    }

    if (a > l && b > l) {
        cout << -1 << "\n";
        return;
    }

    // ---- No se puede, a Y b son mayores a l

    if (l % max == 0) {
        cout << l / max << "\n";
        return;
    }

    // ---- Caso de que no se puede

    ll gcd_ab = gcd_euclides(a, b);
    if (l % gcd_ab != 0) {
        cout << "-1" << "\n";
        return;
    }

    // ---- Cualquier otro caso
    ll x, y;
    ll g = extended_gcd(a, b, x, y);

    ll scale = l / g;
    ll x_m = b / g;
    ll y_m = a / g;

    x = (x % x_m * (scale % x_m)) % x_m;
    if (x < 0) {
        x += x_m;
    }

    ll rem = l - a * x;
    if (rem < 0) {
        cout << -1 << "\n";
        return;
    }

    y = rem / b;

    ll k_max = y / y_m;

    ll ans1 = x + y;
    ll ans2 = (x + k_max * x_m) + (y - k_max * y_m);

    cout << min(ans1, ans2) << "\n";
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
