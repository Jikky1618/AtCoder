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
    int N, K;
    cin >> N >> K;

    auto output = [&](vector<int>& V) -> void {
        cout << "? ";
        for(int i = 0; i < K; i++){
            cout << V[i] << " \n"[i == K - 1];
        }
        cout << flush;
    };

    auto input = []() -> int {
        int in;
        cin >> in;
        return in;
    };

    // A[1], A[2],..., A[K + 1] を求める
    int S = 0;
    vector<int> val(K + 1);
    for(int i = 0; i < K + 1; i++){
        // A[i] を除いた XOR 和を聞く
        vector<int> V;
        for(int j = 0; j < K + 1; j++){
            if(j == i) continue;
            V.emplace_back(j + 1);
        }

        output(V);
        val[i] = input();
        S ^= val[i];
    }

    vector<int> ans(N);
    // S と val[i] の XOR を取ると A[i] となる
    for(int i = 0; i < K + 1; i++){
        ans[i] = S ^ val[i];
    }
    
    // K + 1 以降の項 x は A[0], A[1],..., A[K-1], A[x] の XOR 和を聞く
    // その XOR 和と A[0], A[1],..., A[K-1] の XOR と XOR を取ると A[x] となる
    // A[0], A[1],..., A[K-1] の XOR 和を求める
    int S2 = 0;
    for(int j = 0; j < K - 1; j++) S2 ^= ans[j];

    // A[K + 2], A[K + 3],..., A[N] の XOR を求める
    for(int i = K + 1; i < N; i++){
        // A[0], A[1],..., A[K-1], A[i] の XOR 和を聞く
        vector<int> V;
        for(int j = 0; j < K - 1; j++) V.emplace_back(j + 1);
        V.emplace_back(i + 1);

        output(V);
        // S2 と A[0], A[1],..., A[K-1], A[i] の XOR 和 の XOR を取ると A[i] となる
        ans[i] = input() ^ S2;
    }

    cout << "! ";
    for(int i = 0; i < N; i++){
        cout << ans[i] << " \n"[i == N - 1];
    }
    cout << flush;
}