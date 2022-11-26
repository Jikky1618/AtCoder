#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string s,t;
    cin >> s >> t;
    
    if(s.size() < t.size()){
        cout << "No" << endl;
        return 0;
    }

    for(int i = 0; i < s.size() - t.size() + 1; i++){
        bool same = true;
        for(int j = 0; j < t.size(); j++){
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