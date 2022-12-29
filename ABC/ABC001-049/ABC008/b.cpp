#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<string> S(N);
    for(int i = 0; i < N; i++) cin >> S[i];

    map<string, int> mp;
    for(int i = 0; i < N; i++) mp[S[i]]++;

    string ans = "";
    int max = 0;
    for(auto[key, val]: mp){
        if(max < val){
            max = val, ans = key;
        } 
    }

    cout << ans << endl;
    return 0;
}