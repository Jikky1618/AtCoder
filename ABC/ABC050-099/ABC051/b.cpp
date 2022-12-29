#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int K, S;
    cin >> K >> S;

    int ans = 0;
    for(int X = 0; X <= K; X++){
        for(int Y = 0; Y <= K; Y++){
            // for(int Z = 0; Z <= K; Z++){
            //     if(X + Y + Z == S) ans++;
            // }
            int Z = S - X - Y;
            if(0 <= Z && Z <= K) ans++;
        }
    }

    cout << ans << endl;
    return 0;
}