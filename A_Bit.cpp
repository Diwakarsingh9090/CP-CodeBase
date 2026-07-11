#include <iostream>
using namespace std;
int main (){
    int n;
    cin >> n;
    string s;
    int X = 0;
    while(n--) {
        cin>>s;
        if(s[0] == 'X' && s[1] == '+' && s[2] == '+') X+=1;
        else if(s[0] == '+' && s[1] == '+' && s[2] == 'X') X+=1;
        else if(s[0] == 'X' && s[1] == '-' && s[2] == '-') X-=1;
        else if(s[0] == '-' && s[1] == '-' && s[2] == 'X') X-=1;
    }
    cout << X << endl;
return 0;
}