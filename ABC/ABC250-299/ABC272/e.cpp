#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

template <class T, class U>
T ceil(T x, U y) {
    return (x > 0 ? (x + y - 1) / y : x / y);
}

template <class T, class U>
T floor(T x, U y) {
    return (x > 0 ? x / y : (x - y + 1) / y);
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    // st[i] := i 回目の操作で Mex に関係のある数の集合
    vector<unordered_set<int>> st(M + 1);
    for(int i = 0; i < N; i++){
        if(A[i] + (i + 1) >= N) continue;
        int left = max(1, ceil(-A[i], i + 1));
        int right = min(M + 1, ceil(N - A[i], i + 1));
        // [left, right) までシミュレーション
        for(int j = left; j < right; j++){
            st[j].insert(A[i] + (i + 1) * j);
        }
    }

    debug(st);
    for(int i = 1; i <= M; i++){
        int mex = 0;
        while(st[i].count(mex)) mex++;
        cout << mex << '\n';
    }
}