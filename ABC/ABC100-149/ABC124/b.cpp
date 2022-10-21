#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i = 0; i < n; i++) cin >> h[i];

    int ans = 0;
    for(int i = 0; i < n; i++){
        bool flag = true;
        for(int j = 0; j < i; j++){
            if(h[j] > h[i]) flag = false;
        }
        if(flag) ans++;
    }

    cout << ans << endl;
    return 0;
}