#include <iostream>
#include <cmath>
using namespace std;
int main (){
    long long m, n, a;
    cin >> m >> n >> a;

    // Using integer math to simulate ceiling division
    long long flagstonesB = (n + a - 1) / a; //avoid identifier overloading
    long long flagstonesL = (m + a - 1) / a;
    long long totalflagstone = flagstonesB * flagstonesL;

    cout << totalflagstone << endl;

    return 0;
}