#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    vector<int> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];

    vector<int> ans;
    for(int i = n-1; i >= 0; i--){
        if(i == 0) ans.push_back(s[i]);
        else ans.push_back(s[i] - s[i-1]);
    }

    reverse(ans.begin(), ans.end());

    for(auto i: ans){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}