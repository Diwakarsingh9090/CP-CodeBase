#include <iostream>
#include <set>
using namespace std;

bool hasCommonDigit(int x, int y) {
    set<int> digits_x;

    // extract digits of x and store in a set
    while (x) {
        digits_x.insert(x % 10);
        x /= 10;
    }
    // handle special case: if x has digit 0 and y is also 0
    if (digits_x.count(0) && y == 0) return true;

    // extract digits of y and check if any match with digits of x
    while (y) {
        if (digits_x.count(y % 10)) return true;
        y /= 10;
    }

    return false; // no common digit found
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int x;
        cin >> x;

        // try all y values starting from 0
        for (int y = 0; ; y++) {
            if (hasCommonDigit(x, y)) {
                cout << y << '\n';
                break;
            }
        }
    }
    return 0;
}