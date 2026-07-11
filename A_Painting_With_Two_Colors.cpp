#include <iostream>

// Function to solve a single test case
void solve() {
    long long n, a, b;
    std::cin >> n >> a >> b;

    // Condition 1: The parities of n and b must match for the blue
    // segment to be placed symmetrically.
    // (n % 2 == b % 2) is the same as ((n - b) % 2 == 0)
    if ((n - b) % 2 != 0) {
        std::cout << "NO" << std::endl;
        return;
    }

    if ((n - a) % 2 == 0 || a <= b) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}