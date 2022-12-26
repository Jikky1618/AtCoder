#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll A, B, C;
    cin >> A >> B >> C;

    auto solve = [&]() -> int {
        for(int i = 0; i < pow(10, 5); i++){
        if(A % 2 == 1 || B % 2 == 1 || C % 2 == 1) return i;
        ll a = (B + C) / 2;
        ll b = (A + C) / 2;
        ll c = (A + B) / 2;
        A = a, B = b, C = c; 
        }
        return -1;
    };

    cout << solve() << endl;
    return 0;
}