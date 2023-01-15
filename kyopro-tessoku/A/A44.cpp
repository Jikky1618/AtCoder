#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, Q;
    cin >> N >> Q;

    vector<int> A(N);
    iota(A.begin(), A.end(), 1); // 0, 1, ...

    bool rev = false; // 反転しているかどうかのflag
    while(Q--){
        int Query; cin >> Query;
        if(Query == 1){
            int x, y; cin >> x >> y, x--;
            (rev ? A[N - x - 1] : A[x]) = y;
        }
        if(Query == 2){
            rev = !rev;
        }
        if(Query == 3){
            int x; cin >> x, x--;
            cout << (rev ? A[N - x - 1] : A[x]) << "\n";
        }
    }
}