#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

template<class Abel>
struct BinaryIndexedTree {
    int n;
    vector<Abel> dat;
    Abel UNITY_SUM = 0;

    BinaryIndexedTree(int size, Abel unity = 0)
        : n(size), dat(size + 1, unity), UNITY_SUM(unity) {}

    // val[a] += x
    // a is 1-indexed
    void add(int a, Abel x){
        for(int i = a; i <= n; i += i & -i){
            dat[i] += x;
        }
    }

    // val[1] + ... + val[a]
    // a is 1-indexed
    Abel sum(int a){
        Abel res = UNITY_SUM;
        for(int i = a; i > 0; i -= i & -i){
            res += dat[i];
        }
        return res;
    }

    // val[a] + ... + val[b]
    // a, b is 1-indexed
    Abel sum(int a, int b){
        return sum(b) - sum(a - 1);
    }

    Abel all(){
        return dat.front();
    }
};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll N, M;
    cin >> N >> M;
    vector A(N, vector<int>(M));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++) cin >> A[i][j];
    }

    // 座圧
    vector<int> X;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++) X.emplace_back(A[i][j]);
    }
    sort(X.begin(), X.end());
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            A[i][j] = lower_bound(X.begin(), X.end(), A[i][j]) - X.begin();
        }
    }
    
    BinaryIndexedTree<int> BIT(N * M);
    ll ans = (M + 1) * M / 2 * N * (N - 1) / 2;
    for(int i = N - 1; i >= 0; i--){
        for(int j = 0; j < M; j++){
            ans += BIT.sum(A[i][j]);
        }
        for(int j = 0; j < M; j++){
            BIT.add(A[i][j] + 1, 1);
        }
    }

    cout << ans << endl;
}