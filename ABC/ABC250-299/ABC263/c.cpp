#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n,m;
void dfs(vector<int> a){
    // 終了条件
    if((int)a.size() == n){
        for(int i = 0; i < n; i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
    // 末尾の数字pos
    int pos = 1;
    if(a.size() > 0){ // 数列aが空ではないとき
        pos = a.back() + 1;
    }
    a.push_back(pos);
    // 再起呼び出し
    while(a.back() <= m){
        dfs(a);
        a.back()++;
    }
}
int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> m;

    dfs({});

    return 0;
}