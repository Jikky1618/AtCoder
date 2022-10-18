#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        int n,k; string s;
        cin >> n >> k >> s;

        vector<int> ps0(n + 1), ps1(n + 1);
        for(int i = 0; i < n; i++){
            ps1[i + 1] = ps1[i] + (s[i] == '1');
            ps0[i + 1] = ps0[i] + (s[i] == '0');
        }

        int ways = 0;
        for(int i = 0; i < n - k + 1; i++){
            if(ps1[n] == ps1[i + k] - ps1[i]){
                if(ps0[i + k] - ps0[i] == 0) ways++;
            }
        }

        if(ways == 1) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}