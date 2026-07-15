#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int ans = 0, cnt = 0;

        for (char c : s) {
            if (c == '#') {
                cnt++;
            } else {
                ans = max(ans, (cnt + 1) / 2);
                cnt = 0;
            }
        }

        ans = max(ans, (cnt + 1) / 2);

        cout << ans << '\n';
    }

    return 0;
}