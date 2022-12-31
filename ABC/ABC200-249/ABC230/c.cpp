#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll N, A, B, P, Q, R, S;
    cin >> N >> A >> B >> P >> Q >> R >> S;

    for(ll i = P; i <= Q; i++){
        for(ll j = R; j <= S; j++){
            cout << ((i - j == A - B || i + j == A + B) ? "#" : ".");
        }
        cout << endl;
    }
    return 0;
}