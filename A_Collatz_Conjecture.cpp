#include <iostream>

// Function to solve a single test case
void solve() {
    // Read the number of iterations (k) and the final value (x).
    // int is sufficient for the input constraints (k, x <= 20).
    int k, x;
    std::cin >> k >> x;
    
    // To find a possible initial value, we can reverse the process.
    // The simplest reverse path is to assume the operation was always x = x / 2.
    // The reverse of this is x = x * 2. Repeating this k times gives x * 2^k.
    // We use 'long long' for the result to avoid overflow, as 20 * 2^20 is large.
    // (1LL << k) is an efficient way to calculate 2^k using bit shifts.
    long long initial_value = (long long)x * (1LL << k);
    
    // Print the calculated initial value.
    std::cout << initial_value << std::endl;
}

int main() {
    // Standard boilerplate for faster C++ I/O in competitive programming.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    // Read the number of test cases.
    int t;
    std::cin >> t;
    
    // Process each test case.
    while (t--) {
        solve();
    }
    
    return 0;
}