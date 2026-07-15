#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        long long carry = 0;
        long long prev = 0;
        bool ok = true;

        for (int i = 0; i < n; i++) {
            long long current = a[i] + carry;
            long long need = prev + 1;

            if (current < need) {
                ok = false;
                break;
            }

            carry = current - need;
            prev = need;
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }

    return 0;
}