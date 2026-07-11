#include "bits/stdc++.h"
using namespace std;

#define LOCAL // Uncomment for local debugging
#ifdef LOCAL
#include "C:/Users/Hp/OneDrive/Desktop/Judge/debug.hpp" // Uncomment this too when LOCAL is enabled
// #else
#define debug(x...)
#define debug_arr(x...)
#endif

#define returnY cout<<"YES"<<endl; return;
#define returnN cout<<"NO"<<endl; return;

#define endl '\n'
using ld = long double;
using ll = long long;
constexpr long long MOD = 1e9 + 7;__cpp_binary_literals
constexpr long long inf = 1e16;
constexpr int MAXN = 1e5 + 5;

#define int long long

void solve() {
    // Your solution for one test case goes here
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &x : arr) cin >> x;

    int max_val = -inf;
    for (int x : arr) {
        max_val = max(max_val, x);
        debug(max_val); // Trace the current maximum
    }

    cout << max_val << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int32_t testcases = 1;
    cin >> testcases;
    while (testcases--) {
        solve();
    }

    #ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec" << endl;
    #endif
    return 0;
}