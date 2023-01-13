#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<int> a(N);
    for(int i = 0; i < N; i++) cin >> a[i];

    vector<int> cnt(100010);
    for(int i = 0; i < N; i++){
        for(int j = -1; j <= 1; j++){
            if(0 < a[i] + j) cnt[a[i] + j]++;
        }
    }

    int ans = *max_element(cnt.begin(), cnt.end());
    cout << ans << endl;
}