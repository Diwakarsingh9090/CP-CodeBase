#include <iostream>
#include <vector>
#include <numeric>

// Function to solve a single test case
void solve() {
    int n;
    std::cin >> n; // Read the size of the array
    std::vector<int> a(n);
    
    int established_value = -1; // To store the first non-`-1` number encountered
    bool is_possible = true;    // Flag to track if the array can be made "good"

    // Read all elements of the array
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    // Process the array based on the derived logic
    for (int current_val : a) {
        // A "good" array cannot contain 0.
        if (current_val == 0) {
            is_possible = false;
            break;
        }
        
        // All existing numbers (non -1) must be the same.
        if (current_val != -1) {
            // If this is the first number we've seen, establish it as the target value.
            if (established_value == -1) {
                established_value = current_val;
            } 
            // If we've already established a value, the current one must match.
            else {
                if (current_val != established_value) {
                    is_possible = false;
                    break;
                }
            }
        }
    }

    // Output the result
    if (is_possible) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

// Main function to handle multiple test cases
int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        solve();
    }

    return 0;
}