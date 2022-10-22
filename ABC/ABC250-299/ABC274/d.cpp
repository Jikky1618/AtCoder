#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// dpの添え字が負の値を取らないようにする
const int M = 10000;


int main(){
    // input
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,x,y;cin >> n >> x >> y;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    // dpテーブル
    vector<int> dpx(2 * M + 1), dpy(2 * M + 1), dp_tmp(2 * M + 1);
    // 初期位置
    dpx[a[0] + M] = dpy[0 + M] = 1;

    for(int i = 1; i < n; i++){
        for (int j = -M; j <= M; j++) dp_tmp[j + M] = 0; // 初期化
        // 奇数番目の操作(x方向)の場合
        if(i % 2 == 0){
            for(int j = -M; j <= M - a[i]; j++){
                dp_tmp[j + a[i] + M] |= dpx[j + M];
            }
            for(int j = -M + a[i]; j <= M; j++){
                dp_tmp[j - a[i] + M] |= dpx[j + M];
            }
            swap(dp_tmp, dpx);
        }
        // 偶数番目の操作(y方向)の場合
        if(i % 2 == 1){
            for(int j = -M; j <= M - a[i]; j++){
                dp_tmp[j + a[i] + M] |= dpy[j + M];
            }
            for(int j = -M + a[i]; j <= M; j++){
                dp_tmp[j - a[i] + M] |= dpy[j + M];
            }
            swap(dp_tmp, dpy);
        }
    }

    if(dpx[x + M] && dpy[y + M]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}