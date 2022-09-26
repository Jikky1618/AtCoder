#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dfs(ll hp){
    if(hp == 1) return 1;
    ll sum = 1;
    for(int i = 0; i < 2; i++) sum += dfs(hp / 2);
    return sum;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll h;
    cin >> h;
    cout << dfs(h) << endl;

    return 0;
}