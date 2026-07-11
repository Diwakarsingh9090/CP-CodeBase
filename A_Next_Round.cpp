#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int p[n];

    for (int i = 0; i < n; i++)
        cin >> p[i];

    int count = 0;
    int cutoff = p[k - 1]; // k-th place score

    for (int i = 0; i < n; i++) {
        if (p[i] >= cutoff && p[i] > 0)
            count++;
    }

    cout << count << endl;
    return 0;
}
