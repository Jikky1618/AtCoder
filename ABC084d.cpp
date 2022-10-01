#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<bool> makeIsPrime(ll x){
    vector<bool> prime(x + 1, true);
    prime[0] = prime[1] = false;
    for(int i = 2; i * i <= x; i++){
        if(!prime[i]) continue;
        for(int j = i * 2; j <= x; j += i){
            prime[j] = false; // iの倍数を削除
        }
    }
    return prime;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int q;
    cin >> q;
    vector<int> l(q),r(q);
    for(int i = 0; i < q; i++) cin >> l[i] >> r[i];

    vector<bool> pt = makeIsPrime(100009);
    // a[i] := 数iが2017に似た数ならば1、そうでないなら0
    vector<int> a(100009);
    for(int i = 1; i <= 100000; i++){
        if(pt[i] && pt[(i + 1) / 2]) a[i] = 1; // 1-indexed
    }

    // s[i] := [0,i]の数の中で2017に似た数の個数
    vector<int> s(100009);
    s[0] = 0;
    for(int i = 0; i <= 100000; i++) s[i + 1] = s[i] + a[i + 1];

    // クエリ
    for(int i = 0; i < q; i++){
        cout << s[r[i]] - s[l[i] - 1] << endl;
    }

    return 0;
}