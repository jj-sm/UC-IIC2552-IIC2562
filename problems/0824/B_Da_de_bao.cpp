//  B. Día de baño
/**
 * Problem: B_Da_de_bao.cpp
 * Date:    28/08/26
 * Compile: g++ -std=c++23 -O2 B_Da_de_bao.cpp -o out
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

long long lcm_euclides(long long a, long long b) {
    if (a == 0 || b == 0) return 0;
    return abs(a / gcd_euclides(a, b) * b);
}

void solve() {
    ll a, b, t;
    cin >> a >> b >> t;

    ll gcd_1 = lcm_euclides(a, b);


    ll ans = t / gcd_1;

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
