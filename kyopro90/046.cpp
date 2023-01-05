#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<int> A(N), B(N), C(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> B[i];
    for(int i = 0; i < N; i++) cin >> C[i];

    vector<ll> A_cnt(46), B_cnt(46), C_cnt(46);
    for(int i = 0; i < N; i++) A_cnt[A[i] % 46]++;
    for(int i = 0; i < N; i++) B_cnt[B[i] % 46]++;
    for(int i = 0; i < N; i++) C_cnt[C[i] % 46]++;

    ll ans = 0;
    for(int a = 0; a < 46; a++){
        for(int b = 0; b < 46; b++){
            for(int c = 0; c < 46; c++){
                if((a + b + c) % 46 == 0){
                    ans += A_cnt[a] * B_cnt[b] * C_cnt[c];
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}