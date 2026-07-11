#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        int ans = 0;

        for (int p = 2; p * p <= n; p++) {
            while (n % p == 0) {
                ans++;
                n /= p;
            }
        }

        if (n > 1) ans++;

        cout << ans << '\n';
    }

    return 0;
}