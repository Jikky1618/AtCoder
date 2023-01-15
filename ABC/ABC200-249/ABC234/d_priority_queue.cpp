#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, K;
    cin >> N >> K;
    vector<int> P(N);
    for(int i = 0; i < N; i++) cin >> P[i];

    priority_queue<int, vector<int>, greater<int>> pq; // 最小の要素を取り出す
    for(int i = 0; i < K; i++) pq.push(P[i]); // K番目まで挿入

    cout << pq.top() << endl; // i = K番目に大きい値

    for(int i = K; i < N; i++){
        if(pq.top() < P[i]){ // P[i]がK番目より大きい場合
            pq.pop(); // K + 1 番目はpop
            pq.push(P[i]); // P[i] を挿入
        }
        cout << pq.top() << endl;
    }
}