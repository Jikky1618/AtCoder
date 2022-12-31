#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(M);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < M; i++) cin >> B[i];

    map<int, int> mp;
    for(int i = 0; i < N; i++) mp[A[i]]++;
    for(int i = 0; i < M; i++) mp[B[i]]++;

    for(auto [key, val]: mp){
        if(val == 1) cout << key << " ";
    }
    cout << endl;
    return 0;
}