#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    
    int ans = (N + 1) / 2;
    for(int i = 0; i < (N + 1) / 2; i++){
        if(i == 0 && (N + 2) / 2 % 2 == 1) cout << 1 << endl;
        else cout << 2 << endl;
    }
    return 0;
}