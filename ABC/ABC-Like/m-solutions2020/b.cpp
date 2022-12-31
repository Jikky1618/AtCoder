#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int A, B, C, K;
    cin >> A >> B >> C >> K;

    for(int i = 0; i < K; i++){
        if(B <= A) B *= 2;
        else C *= 2;
    }

    cout << (A < B && B < C ? "Yes" : "No") << endl;
    return 0;
}