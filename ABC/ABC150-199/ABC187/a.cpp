#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int s(string num){
    int ans = 0;
    for(int i = 0; i < (int)num.length(); i++){
        ans += num[i] - '0';
    }
    return ans;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string a,b;
    cin >> a >> b;
    cout << max(s(a),s(b)) << endl;

    return 0;
}