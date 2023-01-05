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
    for(int i = 0; i < N; i++) cin >> A[i];

    int shift = 0; // 何回シフトしたか
    while(Q--){
        int T, x, y; cin >> T >> x >> y; x--, y--;
        if(T == 1){
            swap(A[(x + shift) % N], A[(y + shift) % N]);
        }
        if(T == 2){
            shift = (shift - 1 + N) % N;
        }
        if(T == 3){
            cout << A[(x + shift) % N] << "\n";
        }
    }
    return 0;
}