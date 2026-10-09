//  D. La biblioteca fragmentada
/**
 * Problem: D_La_biblioteca_fragmentada.cpp
 * Date:    9/10/26
 * Compile: g++ -std=c++23 -O2 D_La_biblioteca_fragmentada.cpp -o out
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

void solve() {
    unsigned int n_frags;
    cin >> n_frags;

    priority_queue<ll, vll, greater<ll>> pq;

    for (int i = 0; i < n_frags; ++i) {
        ll x;
        cin >> x;
        pq.push(x);
    }

    ll cost = 0;

    while (pq.size() >= 2) {
        ll first = pq.top();
        pq.pop();
        ll second = pq.top();
        pq.pop();
        ll sum = first + second;
        pq.push(sum);
        cost += sum;
    }

    cout << cost;
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
