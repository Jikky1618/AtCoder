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

    int ans = 0;
    for(int i = 0; i < N; i++){
        if(a[a[i] - 1] == i + 1) ans++;
    }

    cout << ans / 2 << endl;
    return 0;
}