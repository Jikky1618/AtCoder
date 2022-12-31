#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    map<int, int> mp;
    for(int i = 0; i < N; i++) mp[A[i]]++;
    
    int ans = 0, min = INF;
    for(auto [key, val]: mp){
        if(0 < val && val < min){
            min = val, ans = key;
        }
    }

    cout << ans << endl;
    return 0;
}