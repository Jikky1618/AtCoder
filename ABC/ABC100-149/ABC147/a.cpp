#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    vector<int> a(3);
    for(int i = 0; i < 3; i++) cin >> a[i];

    int sum = 0;
    for(int i = 0; i < 3; i++) sum += a[i];

    if(22 <= sum) cout << "bust" << endl;
    else cout << "win" << endl;
    
    return 0;
}