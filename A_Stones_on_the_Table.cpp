#include <iostream>
#include <string>
using namespace std;
int main (){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    for(int i = 1; i < n; i++) {
        if(n == 1){
            cnt = 0;
            break;
        }
        if(s[i] == s[i-1]) cnt++;
        
    }
    cout << cnt << endl;
return 0;
}