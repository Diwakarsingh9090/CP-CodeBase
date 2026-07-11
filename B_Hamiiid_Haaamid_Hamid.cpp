#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void solve() {
    int n;
    int x;
    std::cin >> n >> x;
    std::string s;
    std::cin >> s;

    // Adjust x to be 0-indexed
    x--;

    // Count initial walls and empty cells on both sides of Hamid
    long long walls_left = 0;
    long long empty_left = 0;
    for (int i = 0; i < x; ++i) {
        if (s[i] == '#') {
            walls_left++;
        } else {
            empty_left++;
        }
    }

    long long walls_right = 0;
    long long empty_right = 0;
    for (int i = x + 1; i < n; ++i) {
        if (s[i] == '#') {
            walls_right++;
        } else {
            empty_right++;
        }
    }

    long long obstacles_left = walls_left + empty_left;
    long long obstacles_right = walls_right + empty_right;
    long long days = 0;

    if (walls_left == 0 && walls_right == 0) {
        // Both sides are clear. Mani blocks one, Hamid escapes via the other.
        days = 1;
    } else if (walls_left == 0) {
        // Left is clear, Right has walls. Mani is forced to block left.
        // Hamid then chooses the cheaper path: the newly blocked left side or the original right side.
        long long destructions_needed = std::min(empty_left, obstacles_right);
        days = 1 + destructions_needed;
    } else if (walls_right == 0) {
        // Right is clear, Left has walls. Symmetric to the above case.
        long long destructions_needed = std::min(obstacles_left, empty_right);
        days = 1 + destructions_needed;
    } else {
        // Both sides have walls. It's a race to clear the side with fewer obstacles.
        long long destructions_needed = std::min(obstacles_left, obstacles_right);
        days = 1 + destructions_needed;
    }

    std::cout << days << std::endl;
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