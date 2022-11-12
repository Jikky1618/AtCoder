#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n,q;
    cin >> n >> q;

    vector<int> ball(n);
    vector<int> pos(n);
    for(int i = 0; i < n; i++) ball[i] = pos[i] = i;

    for(int i = 0; i < q; i++){
        // x1入力
        int x1; cin >> x1; x1--;

        // p1 := x1がどこにあるか
        // p2 := x2がどこにあるか
        // x2 := p2の要素
        int p1 = pos[x1];
        int p2 = (p1 < n - 1 ? p1 + 1 : p1 - 1);
        int x2 = ball[p2];
        
        swap(ball[p1], ball[p2]);
        swap(pos[x1],pos[x2]);
    }
    for(auto &&i: ball) cout << i + 1 << " ";
    cout << endl;
}