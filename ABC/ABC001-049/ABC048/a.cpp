#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    vector<string> S(3);
    for(int i = 0; i < 3; i++) cin >> S[i];
    
    for(int i = 0; i < 3; i++) cout << S[i].front();
    cout << endl;
    return 0;
}