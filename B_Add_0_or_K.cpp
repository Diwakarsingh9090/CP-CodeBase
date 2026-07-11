#include <iostream>
#include <vector>
#include <algorithm>

// This is the correct simple logic for the problem.
void solve() {
    int n;
    long long k;
    std::cin >> n >> k;
    
    // We need to find the minimum number of operations.
    // An operation adds a multiple of k.
    // Let's analyze the number of ops to make everything divisible by a target `d`.
    // For each a_i, we need a_i + c_i*k to be divisible by d.
    // The number of operations is max(c_i).

    // If k is a multiple of 4, the number of ops to make all even is
    // the number of odd elements.
    if (k == 4) {
        int ops = 2; // Max ops needed for k=4 is 2.
        int evens = 0;
        for (int i = 0; i < n; i++) {
            int x;
            std::cin >> x;
            if (x % 2 == 0) evens++;
            ops = std::min(ops, (4 - x % 4) % 4);
        }
        if (evens == n) { // All are even
             ops = std::min(ops, 0);
        } else if (evens == n - 1) { // Exactly one odd
             ops = std::min(ops, 1);
        } else { // >= 2 odds
             ops = std::min(ops, 2);
        }
        std::cout << ops << std::endl;

    } else {
        int min_ops = k;
        for (int i = 0; i < n; ++i) {
            long long a_i;
            std::cin >> a_i;
            min_ops = std::min(min_ops, (int)((k - a_i % k) % k));
        }
        std::cout << min_ops << std::endl;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}