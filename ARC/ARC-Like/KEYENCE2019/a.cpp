#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    vector<int> N(4);
    for(int i = 0; i < 4; i++) cin >> N[i];

    sort(N.begin(), N.end());
    if(N[0] == 1 && N[1] == 4 && N[2] == 7 && N[3] == 9){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}