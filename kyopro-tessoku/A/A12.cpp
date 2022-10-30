// めぐる式二分探索を使用

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// index が条件を満たすかどうか
bool check(int index, int key, vector<int> to_search) {
    ll sum = 0;
    for(auto i: to_search) sum += index / i;
    if (sum >= key) return true;
    else return false;
}

// 汎用的な二分探索のテンプレ
int binary_search(int key, vector<int> to_search) {
    ll left = -1;
    ll right = pow(10, 9);
    /* どんな二分探索でもここの書き方を変えずにできる！ */
    while (right - left > 1) {
        ll mid = left + (right - left) / 2;
        if (check(mid, key, to_search)) right = mid;
        else left = mid;
    }
    /* left は条件を満たさない最大の値、right は条件を満たす最小の値になっている */
    return right;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    cout << binary_search(k, a) << endl;
    return 0;
}