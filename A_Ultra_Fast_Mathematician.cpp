#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    string result = "";

    for (int i = 0; i < a.size(); ++i) {
        result += ((a[i] - '0') ^ (b[i] - '0')) + '0';
    }
    cout << result << endl;
    return 0;
}
