#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        int64 ans = 0;

        for (int b = 1; b <= n; b++) {
            int64 cnt = n / b;
            ans += cnt * cnt;
        }

        cout << ans << '\n';
    }

    return 0;
}