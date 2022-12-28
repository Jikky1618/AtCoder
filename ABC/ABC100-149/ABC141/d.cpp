#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    priority_queue<int> pq;
    for(int i = 0; i < N; i++) pq.push(A[i]);
    for(int i = 0; i < M; i++){
        int a = pq.top(); pq.pop();
        a /= 2;
        pq.push(a);
    }

    ll ans = 0;
    for(int i = 0; i < N; i++){
        ans += pq.top(); pq.pop();
    }

    cout << ans << endl;
    return 0;
}