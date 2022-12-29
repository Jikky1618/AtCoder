#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, A, B;
    cin >> N >> A >> B;
    
    int ans = 0;
    for(int i = 0; i < N; i++){
        string s; int d;
        cin >> s >> d;
        if(s == "East"){
            // std::clamp(value, min, max)
            ans -= clamp(d, A, B);
        }else{
            ans += clamp(d, A, B);
        }
    }

    if(ans > 0){
        cout << "West" << " " << ans << endl;
    }else if(ans < 0){
        cout << "East" << " " << abs(ans) << endl;
    }else{
        cout << 0 << endl;
    }
    return 0;
}