#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// Function to solve a single test case
void solve() {
    int n;
    long long k;
    cin >> n >> k;

    vector<int> count(n + 1, 0);   // Size n+1 to handle indices 1 to n
    vector<int> prefix_count(n + 1, 0);

    // Read input and populate frequency count
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (a <= n) { // Guard against potential invalid input, though problem says 1 <= ai <= n
            count[a]++;
        }
    }

    // Populate prefix sum array
    for (int i = 1; i <= n; ++i) {
        prefix_count[i] = prefix_count[i - 1] + count[i];
    }

    int max_beauty = 1; // Default answer is 1

    // Iterate d from n down to 2
    for (int d = n; d >= 2; --d) {
        // Calculate the cost (erasures needed) for this d
        long long erasures = 0;
        
        // We only care about numbers < 4*d
        int limit = min(n, 4 * d - 1);

        // Total numbers in the range [1, limit]
        long long total_in_range = prefix_count[limit];

        // Count the multiples of d in the range [1, limit]
        long long multiples_in_range = 0;
        for (int j = 1; j * d <= limit; ++j) {
            multiples_in_range += count[j * d];
        }

        // Erasures needed = (total) - (good ones)
        erasures = total_in_range - multiples_in_range;

        if (erasures <= k) {
            max_beauty = d;
            break; // Found the largest d, so we can stop the process
        }
    }

    cout << max_beauty << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}