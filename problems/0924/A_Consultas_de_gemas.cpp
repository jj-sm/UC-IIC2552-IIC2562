//  A. Consultas de gemas
/**
 * Problem: A_Consultas_de_gemas.cpp
 * Date:    8/10/26
 * Compile: g++ -std=c++23 -O2 A_Consultas_de_gemas.cpp -o out
 * Run:     ./out < input.txt
 */

#include <iostream>
#include <vector>
#include <algorithm>

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
    int n, q;
    cin >> n >> q;

    vll gems(n);
    for (int i = 0; i < n; i++) {
        cin >> gems[i];
    }

    // O(n log(n))
    sort(gems.begin(), gems.end(), greater<>());
    // 7 4 3 2 1
    // 7 11 14 16 17

    // Prebuild Sum
    // O(n)
    vll sums(n);

    sums[0] = gems[0];

    for (int i = 1; i < n; i++) {
        sums[i] = sums[i - 1] + gems[i];
    }
    // reverse(sums.begin(), sums.end());

    // Consultas
    for (int i = 0; i < q; i++) {
        int m;
        cin >> m;

        cout << sums[m-1] << "\n";
    }
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
