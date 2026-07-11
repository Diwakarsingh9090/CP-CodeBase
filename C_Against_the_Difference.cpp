#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

// Function to speed up C++ I/O
void fast_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
}

// Solves a single test case
void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);

    // Step 1: Pre-compute all positions for each number.
    // positions[v] stores a vector of 0-based indices where a[i] == v.
    // Using unordered_map for O(1) average time complexity for access.
    std::unordered_map<int, std::vector<int>> positions;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        positions[a[i]].push_back(i);
    }

    // dp[i] will store the length of the longest neat subsequence
    // that can be formed using the prefix a[0...i-1].
    std::vector<int> dp(n + 1, 0);

    // current_occurrence[v] = k means we are about to process the (k+1)-th occurrence of v.
    std::unordered_map<int, int> current_occurrence;

    // Step 2: Main DP loop. Iterate from i=1 to n to compute dp[i].
    for (int i = 1; i <= n; ++i) {
        // Case 1: We don't use the element a[i-1].
        // The best length is inherited from the previous prefix.
        dp[i] = dp[i-1];

        int val = a[i-1];
        
        // 'k' is the 0-indexed count of occurrences of 'val' seen so far.
        // For a default-constructed int in a map, this will be 0.
        int k = current_occurrence[val];

        // Case 2: Check if a[i-1] can be the end of a new block of size 'val'.
        // This requires having seen 'val' occurrences of the number 'val'.
        // The current element is the (k+1)-th occurrence.
        if (k + 1 >= val) {
            // A block can be formed. Find its starting index in the original array 'a'.
            // The first element of this block was the (k - val + 2)-th overall occurrence.
            // Its index in the positions[val] vector is (k - val + 1).
            int start_block_pos_list_idx = k - val + 1;
            int start_block_idx_in_a = positions[val][start_block_pos_list_idx];

            // The length of the longest neat subsequence formed *before* this block starts.
            // This subsequence must use elements from a[0...start_block_idx_in_a - 1].
            // The length for that prefix is stored in dp[start_block_idx_in_a].
            int len_before = dp[start_block_idx_in_a];

            // Update dp[i] if using this new block gives a better result.
            dp[i] = std::max(dp[i], len_before + val);
        }

        // Increment the occurrence count for the current value for the next time we see it.
        current_occurrence[val]++;
    }

    // Step 3: The final answer for the entire array is in dp[n].
    std::cout << dp[n] << "\n";
}

int main() {
    fast_io();

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}