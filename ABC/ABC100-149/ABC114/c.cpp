#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void find_753(int n, ll num, int used, int &cnt){
    if(num > n) return; // nより大きいと終了

    bool flag = true;
    for(int i = 0; i < 3; i++){
        if(!((used >> i) & 1)) flag = false;
    }
    if(flag) cnt++;

    find_753(n, num * 10 + 7, used | (1 << 2), cnt);
    find_753(n, num * 10 + 5, used | (1 << 1), cnt);
    find_753(n, num * 10 + 3, used | (1 << 0), cnt);
}
int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    
    int ans = 0;
    find_753(n, 0, 0, ans);
    cout << ans <<endl;
    return 0;
}