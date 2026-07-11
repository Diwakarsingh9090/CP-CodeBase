#include <iostream>
#include <vector>
#include <queue>

void solve() {
    int n;
    std::cin >> n;
    
    // Max-priority queue for odd-indexed elements (modifiable)
    std::priority_queue<long long> odd_q;
    // Max-priority queue for even-indexed elements (fixed)
    std::priority_queue<long long> even_q;

    long long total_operations = 0;

    for (int i = 0; i < n; ++i) {
        long long val;
        std::cin >> val;

        if ((i + 1) % 2 != 0) { // Odd original index
            odd_q.push(val);
        } else { // Even original index
            even_q.push(val);
        }

        // After adding, check for and fix the most severe imbalance.
        if (!odd_q.empty() && !even_q.empty()) {
            if (odd_q.top() > even_q.top()) {
                long long o_max = odd_q.top();
                odd_q.pop();
                long long e_max = even_q.top();
                even_q.pop();

                // The cost is the amount we must reduce the largest odd element.
                total_operations += o_max - e_max;

                // Conceptually swap their values to restore balance for future steps.
                odd_q.push(e_max);
                even_q.push(o_max);
            }
        }
    }

    std::cout << total_operations << "\n";
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