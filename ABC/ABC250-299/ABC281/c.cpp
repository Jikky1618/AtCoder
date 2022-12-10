#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll N, T;
    cin >> N >> T;
    vector<ll> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    ll sum = 0;
    for(auto &&a: A) sum += a;

    T %= sum;
    for(int i = 0; i < N; i++){
        T -= A[i];
        if(T < 0){
            cout << i + 1 << " " << A[i] - abs(T) << endl;
            return 0;
        }
    }

    return 0;
}