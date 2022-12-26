#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    vector<ll> B(3);
    for(int i = 0; i < 3; i++) cin >> B[i];

    if(B[0] % 2 == 0 || B[1] % 2 == 0 || B[2] % 2 == 0){
        cout << 0 << endl;
        return 0;
    }

    sort(B.begin(), B.end(), greater<ll>());
    cout << B[1] * B[2] << endl;
    return 0;
}