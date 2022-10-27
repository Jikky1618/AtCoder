#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 10進数(ll) -> N進数(string)
string dec_to_n(ll num, ll n){
    if(num == 0) return "0";
    string ans;
    while(num > 0){
        char c = ((num % n) + '0');
        ans = c + ans;
        num /= n;
    }
    return ans;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(to_string(i).find('7') != string::npos || dec_to_n(i, 8).find('7') != string::npos) continue;
        ans++;
    }

    cout << ans << endl;
    return 0;
}