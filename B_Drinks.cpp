#include<bits/stdc++.h>
using namespace std;
int main (){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    double sum = 0;
    for(int i = 0; i<n; i++){
        sum = sum + arr[i];
    }
    double ans=sum/n;
    cout<<fixed<<setprecision(12)<<ans<<endl;
    return 0;
}