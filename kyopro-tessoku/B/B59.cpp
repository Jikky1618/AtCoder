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

template <class T>
ll inversion_number(vector<T>& A){
    int n = A.size();
    BinaryIndexedTree<ll> bit(n);
    ll res = 0;
    for(int i = 0; i < n; i++){
        res += i - bit.sum(A[i]);
        bit.add(A[i], 1);
    }
    return res;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    cout << inversion_number(A) << endl;
}