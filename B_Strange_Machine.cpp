#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; 
    if(!(cin >> T)) return 0;
    while(T--){
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        vector<int64> queries(q);
        for(int i=0;i<q;i++) cin >> queries[i];

        // If no B anywhere, each second reduces a by 1
        if(s.find('B') == string::npos){
            for(auto a: queries) cout << a << "\n";
            continue;
        }

        // Precompute distance to next 'B' from each position (0-based)
        vector<int> dist(n, -1);
        for(int i=0;i<n;i++){
            if(s[i]=='B'){ dist[i] = 0; continue; }
            int d = 1;
            while(d < n && s[(i+d) % n] != 'B') ++d;
            if(d < n) dist[i] = d;
            else dist[i] = -1; // shouldn't happen because we checked presence of 'B'
        }

        for(auto a0: queries){
            int64 a = a0;
            int pos = 0; // starting at machine 1 => index 0
            int64 seconds = 0;
            while(a > 0){
                int d = dist[pos];
                if(d == 0){ // current is B
                    a = a / 2;
                    ++seconds;
                    pos = (pos + 1) % n;
                } else {
                    // there is a run of d >= 1 A's before next B
                    if(a <= d){
                        seconds += a;
                        a = 0;
                        break;
                    } else {
                        a -= d;
                        seconds += d;
                        pos = (pos + d) % n; // now at the B
                    }
                }
            }
            cout << seconds << "\n";
        }
    }
    return 0;
}
