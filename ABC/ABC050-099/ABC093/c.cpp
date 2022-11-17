#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    vector<int> n(3);
    for(int i = 0; i < 3; i++) cin >> n[i];

    int ans = 0;
    while(n[0] != n[1] || n[1] != n[2]){
        sort(n.begin(), n.end());
        if(n[0] + 2 <= n[2]){
            n[0] += 2;
        }else{
            n[0]++, n[1]++;
        }
        ans++;
    }

    cout << ans << endl;
    return 0;
}