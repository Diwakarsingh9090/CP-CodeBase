#include <iostream>

// Function to check if the scores for a single half are possible.
bool is_half_possible(int score1, int score2) {
    // Team 1's score must be at most 2 * (Team 2's score + 1).
    // The same must be true for Team 2.
    if (score1 > 2 * (score2 + 1)) {
        return false;
    }
    if (score2 > 2 * (score1 + 1)) {
        return false;
    }
    return true;
}

void solve() {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    // Check if the first half is possible
    bool first_half_ok = is_half_possible(a, b);

    // Calculate goals scored in the second half
    int second_half_a = c - a;
    int second_half_b = d - b;

    // Check if the second half is possible
    bool second_half_ok = is_half_possible(second_half_a, second_half_b);

    if (first_half_ok && second_half_ok) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
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