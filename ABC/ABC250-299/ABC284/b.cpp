#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int T;
    cin >> T;

    while(T--){
        int N;
        cin >> N;
        vector<int> A(N);
        for(int i = 0; i < N; i++) cin >> A[i];

        int cnt = 0;
        for(auto a: A) if(a % 2 == 1) cnt++;

        cout << cnt << "\n";
    }
}