//  D. Fibonacci
/**
 * Problem: D_Fibonacci.cpp
 * Date:    16/08/26
 * Compile: g++ -std=c++23 -O2 D_Fibonacci.cpp -o out
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

struct matrix {
    ll data[2][2];
};

matrix matrix_multiplication(matrix a, matrix b) {
    matrix c;
    c.data[0][0] = ((a.data[0][0] * b.data[0][0]) + (a.data[0][1] * b.data[1][0])) % mod;
    c.data[0][1] = ((a.data[0][0] * b.data[0][1]) + (a.data[0][1] * b.data[1][1])) % mod;
    c.data[1][0] = ((a.data[1][0] * b.data[0][0]) + (a.data[1][1] * b.data[1][0])) % mod;
    c.data[1][1] = ((a.data[1][0] * b.data[0][1]) + (a.data[1][1] * b.data[1][1])) % mod;
    return c;
}

matrix matrix_exp(matrix base, ll exp) {
    matrix ans;
    ans.data[0][0] = 1;
    ans.data[0][1] = 0;
    ans.data[1][0] = 0;
    ans.data[1][1] = 1;

    if (exp == 0) {
        return ans;
    }

    while (exp > 0) {
        if (exp % 2 == 1) {
            ans = matrix_multiplication(ans, base);
        }
        base = matrix_multiplication(base, base);
        exp /= 2;
    }
    return ans;
}


void solve() {
    ll n;
    cin >> n;
    matrix ans_m;

    matrix A;
    A.data[0][0] = 1;
    A.data[1][0] = 1;
    A.data[1][1] = 0;
    A.data[0][1] = 1;

    if (n == 0) {
        cout << 0 << "\n";
    } else if (n == 1) {
        cout << 1 << "\n";
    } else {
        ans_m = matrix_exp(A, n - 1);
        cout << ans_m.data[0][0] << "\n";
        // cout << ans_m.data[0][0] << " " << ans_m.data[0][1] << "\n";
        // cout << ans_m.data[1][0] << " " << ans_m.data[1][1] << "\n";
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
