#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    vector<ll> V;
    map<int, int> mp;
    for(auto a: A){
        mp[a]++;
        if(mp[a] == 2) mp[a] = 0, V.push_back(a);
    }

    sort(V.begin(), V.end(), greater<ll>());

    ll ans = (V.size() >= 2 ? V[0] * V[1] : 0);
    cout << ans << endl;
}