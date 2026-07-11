#include <iostream>
using namespace std;
int main (){
    int n, wonAnton=0, wonDanik=0;
    string s;
    cin>>n;
    cin>>s;
    for(int i=0;i<n;i++) {
        if(s[i] == 'A') wonAnton++;
        else wonDanik++;
    }
    if(wonAnton > wonDanik) cout << "Anton" << endl;
    else if(wonAnton < wonDanik){
        cout << "Danik" << endl;
    }
    else cout << "Friendship" << endl;
return 0;
}