#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    // プロジェクトの数を決め打ち二分探索
    ll ok = 0, ng = 1e18 / K;
    while(ng - ok > 1){
        ll mid = (ok + ng) / 2, sum = 0;
         // 1つの部署はmid人以上参加できない
        for(auto a: A) sum += min(a, mid);
        // K個のmid人より参加人数が多ければok
        if(sum >= K * mid) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;
    return 0;
}