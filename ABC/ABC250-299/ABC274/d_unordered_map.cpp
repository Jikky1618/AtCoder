#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int M = 10000;

int main(){
    // input
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,x,y;cin >> n >> x >> y;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    // dpテーブル
    unordered_map<int, int> dpx, dpy, dp_tmp;
    // 初期位置
    dpx[a[0]] = dpy[0] = 1;

    for(int i = 1; i < n; i++){
        for (int j = -M; j <= M; j++) dp_tmp[j] = 0; // 初期化
        // 奇数番目の操作(x方向)の場合
        if(i % 2 == 0){
            for(int j = -M; j <= M - a[i]; j++){
                dp_tmp[j + a[i]] |= dpx[j];
            }
            for(int j = -M + a[i]; j <= M; j++){
                dp_tmp[j - a[i]] |= dpx[j];
            }
            swap(dp_tmp, dpx);
        }
        // 偶数番目の操作(y方向)の場合
        if(i % 2 == 1){
            for(int j = -M; j <= M - a[i]; j++){
                dp_tmp[j + a[i]] |= dpy[j];
            }
            for(int j = -M + a[i]; j <= M; j++){
                dp_tmp[j - a[i]] |= dpy[j];
            }
            swap(dp_tmp, dpy);
        }
    }

    if(dpx[x] && dpy[y]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}