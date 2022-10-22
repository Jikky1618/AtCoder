#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,x,y;cin >> n >> x >> y;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int px = 0, py = 0;
    for(int i = 0; i < n; i++){
        if(i == 0) px += a[i];
        else if(i % 2 == 0){
            if(px < x) px += a[i];
            else px -= a[i];
        }else{
            if(py < y) py += a[i];
            else py -= a[i];
        }
    }

    cout << px << " " << py << endl;
    if(px == x && py == y) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}