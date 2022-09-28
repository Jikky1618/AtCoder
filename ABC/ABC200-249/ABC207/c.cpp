#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<double> l(n),r(n);
    for(int i = 0; i < n; i++){
        int t; cin >> t;
        cin >> l[i] >> r[i];
        if(t == 2){
            r[i] -= 0.1;
        }
        if(t == 3){
            l[i] += 0.1;
        }
        if(t == 4){
            l[i] += 0.1; r[i] -= 0.1;
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(min(r[i],r[j]) >= max(l[i],l[j])) ans++;
        }
    }

    cout << ans << endl;
    return 0;
}