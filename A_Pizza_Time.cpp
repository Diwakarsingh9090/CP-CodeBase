#include <bits/stdc++.h>
using namespace std;

long long maxSlices(long long n) {
    if (n <= 2) return 0;

    long long total = 0;
    while (n > 2) {
        long long m1 = n / 3;                 // smallest group
        long long m2 = m1;                    // middle group
        long long m3 = n - m1 - m2;           // leftover
        total += m1;                          // Hao eats m1
        n = m3;                               // remaining slices
    }
    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        cout << maxSlices(n) << "\n";
    }
    return 0;
}
