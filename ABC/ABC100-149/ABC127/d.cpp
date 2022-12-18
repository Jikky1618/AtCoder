#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, M;
    cin >> N >> M;
    vector<ll> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    vector<pair<ll, ll>> BC(M);
    for(int i = 0; i < M; i++) cin >> BC[i].first >> BC[i].second;

    sort(A.begin(), A.end());
    // second 基準の降順ソート
    sort(BC.begin(), BC.end(), [](const auto& left, const auto& right){
        return left.second > right.second;});

    ll cnt = 0;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < BC[i].first; j++){
            if(cnt + j < N && A[cnt + j] < BC[i].second) A[cnt + j] = BC[i].second;
        }
        cnt += BC[i].first;
        if(N <= cnt) break;
    }

    ll ans = 0;
    for(auto a: A) ans += a;
    cout << ans << endl;
    return 0;
}