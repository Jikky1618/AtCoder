#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,s,d;
    cin >> n >> s >> d;
    vector<int> x(n),y(n);
    for(int i = 0; i < n; i++) cin >> x[i] >> y[i];

    bool attack = false;
    for(int i = 0; i < n; i++){
        if(x[i] < s && y[i] > d) attack = true;
    }

    if(attack) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}