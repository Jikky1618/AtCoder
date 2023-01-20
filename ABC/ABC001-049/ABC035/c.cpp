#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, Q;
    cin >> N >> Q;
    
    vector<int> imos(N + 1, 0);
    while(Q--){
        int l, r; cin >> l >> r, l--;
        imos[l] ^= 1, imos[r] ^= 1;
    }

    for(int i = 0; i < N; i++){
        imos[i + 1] ^= imos[i];
    }

    for(int i = 0; i < N; i++){
        cout << imos[i] << (i == N - 1 ? "\n" : "");
    }
}