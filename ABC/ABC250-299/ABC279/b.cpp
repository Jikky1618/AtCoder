#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string s,t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    
    if(n < m){
        cout << "No" << endl;
        return 0;
    }

    for(int i = 0; i < n - m + 1; i++){
        bool same = true;
        for(int j = 0; j < m; j++){
            if(s[i + j] != t[j]){
                same = false;
            }
        }
        if(same){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}