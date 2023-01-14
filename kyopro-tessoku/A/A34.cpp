#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX = 1e6;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, X, Y;
    cin >> N >> X >> Y;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    // grundy[i] := 石の数がi個のときのgrundy数
    vector<int> grundy(MAX + 1);

    for(int i = 0; i <= MAX; i++){
        // transit[i] := grundy数がiのときに遷移できるか
        vector<bool> transit(3, false);
        if(i - X >= 0) transit[grundy[i - X]] = true;
        if(i - Y >= 0) transit[grundy[i - Y]] = true;

        for(int j = 0; j < 3; j++){
            if(transit[j] == false){
                grundy[i] = j;
                break;
            }
        }
    }

    int xor_sum = 0;
    for(int i = 0; i < N; i++) xor_sum ^= grundy[A[i]];

    cout << (xor_sum != 0 ? "First" : "Second") << endl;
}