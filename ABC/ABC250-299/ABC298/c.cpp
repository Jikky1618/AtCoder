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
    int N, Q;
    cin >> N >> Q;

    // 箱iに入っているカード
    map<int, vector<int>> box;
    // 数iが入っている箱の番号
    map<int, set<int>> num;


    while(Q--){
        int type; cin >> type;
        if(type == 1){
            int i, j; cin >> i >> j;
            box[j].emplace_back(i);
            num[i].insert(j);
        }
        if(type == 2){
            int i; cin >> i;
            int n = box[i].size();
            sort(box[i].begin(), box[i].end());
            for(int j = 0; j < n; j++){
                cout << box[i][j] << " \n"[j == n - 1];
            }
        }
        if(type == 3){
            int i; cin >> i;
            for(auto e: num[i]){
                cout << e << " ";
            }
            cout << "\n";
        }
    }
}