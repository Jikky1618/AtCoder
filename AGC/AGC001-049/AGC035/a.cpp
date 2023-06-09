#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    map<int, int> mp;
    for(int i = 0; i < N; i++) mp[A[i]]++;

    bool flag = false;
    // N が 3 の倍数のとき
    if(N % 3 == 0){
        // a XOR b XOR c = 0 となるa, b, cならYes
        
        // 1 種類のとき, a = b = c = 0 が条件
        if(mp.size() == 1){
            if(mp[0] == N) flag = true;
        // 2 種類のとき, a = b, c = 0 or a = c, b = 0 or b = c, a = 0
        // すなわち, 0 の個数が N / 3 個が条件
        }else if(mp.size() == 2){
            if(mp[0] == N / 3) flag = true;
        // 3 種類のとき, a XOR b XOR c = 0 かつ, それぞれ N / 3 個なのが条件
        }else if(mp.size() == 3){
            vector<int> v;
            for(auto [key, val]: mp) v.emplace_back(key);

            if((v[0] ^ v[1] ^ v[2]) == 0 && mp[v[0]] == N / 3 && mp[v[1]] == N / 3 && mp[v[2]] == N / 3){
                flag = true;
            }
        }
    // N が 3 の倍数でない場合
    }else{
        // すべて XOR の単位元である 0 でないと条件を満たさない
        flag = (mp[0] == N);
    }

    cout << (flag ? "Yes" : "No") << endl;
}