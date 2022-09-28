#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    
    bool can = false;
    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++){
            if(i * j == n) can = true;
        }
    }

    if(can) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}