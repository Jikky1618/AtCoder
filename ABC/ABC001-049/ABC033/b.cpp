#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<string> S(N);
    vector<int> P(N);
    for(int i = 0; i < N; i++) cin >> S[i] >> P[i];

    int sum = 0;
    for(int i = 0; i < N; i++) sum += P[i];

    for(int i = 0; i < N; i++){
        if(2 * P[i] > sum){
            cout << S[i] << endl;
            return 0;
        }
    }

    cout << "atcoder" << endl;
    return 0;
}