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

    int sum = 0;
    for(int i = 0; i < N; i++) sum += a[i];

    // 平均が整数でない
    if(sum % N != 0){
        cout << -1 << endl;
        return 0;
    }

    int ave = sum / N;
    int cnt = 0, val = 0, ans = 0;
    for(int i = 0; i < N; i++){
        cnt++; // 島の数
        val += a[i]; // 人数
        // 平均になっていないなら橋をかける
        if(val != ave * cnt) ans++;
        // 平均になっていたら次のグループへ
        else cnt = 0, val = 0;
    }

    cout << ans << endl;
    return 0;
}