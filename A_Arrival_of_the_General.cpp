#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    int maxHeight = a[0], maxIndex = 0;
    int minHeight = a[0], minIndex = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] > maxHeight) {
            maxHeight = a[i];
            maxIndex = i;
        }
        // for min we want the **last occurrence**
        if (a[i] <= minHeight) {
            minHeight = a[i];
            minIndex = i;
        }
    }

    int swaps = maxIndex + (n - 1 - minIndex);
    if (maxIndex > minIndex) swaps -= 1;

    cout << swaps << endl;
    return 0;
}
