#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int a_max = 200;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    map<int,int> cnt;
    for(int i = 0; i < n; i++){
        cnt[a[i]]++;
    }
    ll ans = 0;
    for(int i  = -a_max; i <= a_max; i++){
        for(int j = i + 1; j <= a_max; j++){
            ans += pow(j - i,2) * cnt[i] * cnt[j];
        }
    }

    cout << ans << endl;

    return 0;
}