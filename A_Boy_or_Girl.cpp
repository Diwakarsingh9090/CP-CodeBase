#include <bits/stdc++.h>
using namespace std;
int main (){
    string str;
    cin >> str;
    unordered_set<char> s;

    for (int i = 0; i < str.size(); i++) 
        s.insert(str[i]);
    
    int n = s.size();
    
    if(n & 1 == 1) 
        cout << "IGNORE HIM!" << endl;
    
    else
        cout << "CHAT WITH HER!" << endl;

return 0;
}