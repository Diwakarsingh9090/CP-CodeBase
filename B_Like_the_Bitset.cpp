#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;

    // --- Step 1: Validation ---
    // Check for any contiguous block of k or more '1's.
    int consecutive_ones = 0;
    for (char c : s) {
        if (c == '1') {
            consecutive_ones++;
        } else {
            consecutive_ones = 0;
        }
        if (consecutive_ones >= k) {
            std::cout << "NO\n";
            return;
        }
    }

    std::cout << "YES\n";

    // --- Step 2: Construction ---
    std::vector<int> p(n);
    int current_val = n;
    std::vector<int> ones_group;

    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            ones_group.push_back(i);
        } else { // s[i] == '0'
            // This '0' resolves the preceding group of '1's.
            // Assign the largest value in this component to the '0'.
            p[i] = current_val - ones_group.size();
            
            // Assign the remaining (smaller) values to the '1's.
            int temp_val = current_val;
            for (int one_idx : ones_group) {
                p[one_idx] = temp_val--;
            }
            
            // Update the next available largest value.
            current_val = p[i] - 1;
            ones_group.clear();
        }
    }

    // Handle any trailing group of '1's at the end of the string.
    if (!ones_group.empty()) {
        int temp_val = current_val;
        for (int one_idx : ones_group) {
            p[one_idx] = temp_val--;
        }
    }

    // Print the resulting permutation.
    for (int i = 0; i < n; ++i) {
        std::cout << p[i] << (i == n - 1 ? "" : " ");
    }
    std::cout << "\n";
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