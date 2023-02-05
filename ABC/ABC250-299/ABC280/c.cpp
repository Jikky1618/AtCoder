#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string s,t;
    cin >> s >> t;

    int n = t.size();
    for(int i = 0; i < n; i++){
        if(s[i] != t[i]){
            cout << i + 1 << endl;
            return 0;
        }
    }
}