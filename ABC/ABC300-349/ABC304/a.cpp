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
    vector<string> S(N);
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> S[i] >> A[i];

    int pos = min_element(A.begin(), A.end()) - A.begin();
    for(int i = 0; i < N; i++){
        cout << S[(i + pos) % N] << endl;
    }
}