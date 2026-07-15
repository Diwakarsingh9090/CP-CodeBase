#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<ll> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];

        vector<int> hasPost(n + 1, 0);
        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            hasPost[x] = 1;
        }

        vector<ll> dp(2, 0), ndp(2);

        for (int i = 1; i <= n; i++) {
            if (!hasPost[i]) {
                ndp[0] = dp[0] + a[i];
                ndp[1] = dp[1] - a[i];
            } else {
                ndp[0] = max(dp[0] + a[i], dp[1] + a[i]);
                ndp[1] = max(dp[1] - a[i], dp[0] - a[i]);
            }
            dp = ndp;
        }

        cout << dp[0] << '\n';
    }

    return 0;
}