#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1<<29;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int a,b,w;
    cin >> a >> b >> w;
    w *= 1000;

    int ans_max = -1,ans_min = INF;
    bool found = false;
    // あり得るみかんの個数で全探索
    for(int i = 1; i <= w; i++){
        // Wになる条件
        if(a * i <= w && w <= b * i){
            ans_max = max(ans_max,i);
            ans_min = min(ans_min,i);
            found = true;
        }
    }
    
    if(found) cout << ans_min << " " << ans_max << endl;
    else cout << "UNSATISFIABLE" << endl;

    return 0;
}