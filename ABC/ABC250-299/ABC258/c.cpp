#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n,q;
    string s;
    cin >> n >> q >> s;

    int cnt = 0; // 何回rotateしたか
    for(int i = 0; i < q; i++){
        int t,x; cin >> t >> x;
        if(t == 1){
            cnt += x, cnt %= n;
        }
        if(t == 2){
            cout << s[(x - 1 - cnt + n) % n] << endl;
        }
    }
    
    return 0;
}