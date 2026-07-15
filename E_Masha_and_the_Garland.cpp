#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n, q;
        cin >> n >> q;

        string s;
        cin >> s;
        s = " " + s; // 1-index

        vector<int> mis0(n + 1), mis1(n + 1);
        vector<int> pre0(n + 1), pre1(n + 1);

        for (int i = 1; i <= n; i++) {
            int bit = s[i] - '0';

            int p0 = (i & 1) ? 0 : 1; // 010101...
            int p1 = p0 ^ 1;          // 101010...

            mis0[i] = bit ^ p0;
            mis1[i] = bit ^ p1;
        }

        for (int i = 2; i <= n; i++) {
            pre0[i] = pre0[i - 1] + (mis0[i] ^ mis0[i - 1]);
            pre1[i] = pre1[i - 1] + (mis1[i] ^ mis1[i - 1]);
        }

        while (q--) {
            int l, r, k;
            cin >> l >> r >> k;

            auto calc = [&](vector<int> &mis, vector<int> &pre) {
                int cnt = mis[l] + mis[r] + (pre[r] - pre[l]);
                return cnt / 2;
            };

            int need0, need1;

            if (l & 1) {
                // substring starts with 0 -> global pattern0
                need0 = calc(mis0, pre0);
                need1 = calc(mis1, pre1);
            } else {
                // parity shifts
                need0 = calc(mis1, pre1);
                need1 = calc(mis0, pre0);
            }

            cout << (min(need0, need1) <= k ? "YES" : "NO") << '\n';
        }
    }

    return 0;
}