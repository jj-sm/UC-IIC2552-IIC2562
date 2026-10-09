//  C. La rana descontrolada
/**
 * Problem: C_La_rana_descontrolada.cpp
 * Date:    28/08/26
 * Compile: g++ -std=c++23 -O2 C_La_rana_descontrolada.cpp -o out
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


// 1. Algoritmo de Euclides (O(log min(a,b)))
// Calcula el máximo común divisor (GCD)
long long gcd_euclides(long long a, long long b) {
    a = abs(a); b = abs(b);
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Calcula el mínimo común múltiplo (LCM)
long long lcm_euclides(long long a, long long b) {
    if (a == 0 || b == 0) return 0;
    return abs(a / gcd_euclides(a, b) * b);
}

// 2. Euclides Extendido y Bézout
// Retorna g y actualiza x, y tal que a*x + b*y = g
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

// 3. Inverso Modular (Euclides Extendido)
// Retorna x tal que (a*x) % m == 1. Existe si gcd(a, m) == 1
long long mod_inverse(long long a, long long m) {
    long long x, y;
    long long g = extended_gcd(a, m, x, y);
    if (g != 1) return -1;
    return ((x % m) + m) % m; // Normalizamos para evitar residuos negativos en C++
}

void solve() {
    ll n, a, b;
    cin >> n >> a >> b;

    ll gcd = gcd_euclides(a, n);

    if (b % gcd != 0) {
        cout << -1 << "\n";
        return;
    }

    a /= gcd;
    b /= gcd;
    n /= gcd;

    if (n == 1) {
        cout << 0 << "\n";
        return;
    }

    ll inv = mod_inverse(a, n);
    ll x = (b * inv % n);


    cout << x << "\n";
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
