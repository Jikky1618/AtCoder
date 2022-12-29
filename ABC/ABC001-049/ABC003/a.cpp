#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;

    int ans = 0;
    for(int i = 1; i <= N; i++){
        ans += i * 10000;
    }

    ans /= N;
    cout << ans << endl;
    return 0;
}