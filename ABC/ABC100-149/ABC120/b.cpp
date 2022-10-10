#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int a,b,k;
    cin >> a >> b >> k;

    vector<int> ans;
    for(int i = 1; i <= min(a,b); i++){
        if(a % i == 0 && b % i == 0) ans.push_back(i);
    }
    sort(ans.begin(), ans.end(),greater<int>());

    cout << ans[k - 1] << endl;
    return 0;
}