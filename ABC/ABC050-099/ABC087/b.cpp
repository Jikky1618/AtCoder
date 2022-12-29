#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int A, B, C, X;
    cin >> A >> B >> C >> X;

    int ans = 0;
    for(int a = 0; a <= A; a++){
        for(int b = 0; b <= B; b++){
            for(int c = 0; c <= C; c++){
                if(a * 500 + b * 100 + c * 50 == X) ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}