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
    int N, X, Y;
    cin >> N >> X >> Y;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    auto calc = [&](vector<int> B) -> ll {
        int M = B.size();
        // 連続部分列で X, Y 両方含む区間の個数を求める
        ll res = 0, cntx = 0, cnty = 0;
        for(int left = 0, right = 0; left < M; left++){
            while(right < M && (cntx == 0 || cnty == 0)){
                if(B[right] == X) cntx++;
                if(B[right] == Y) cnty++;
                right++;
            }
            // 右端が [right - 1, M) の区間は全て条件を満たす
            if(cntx > 0 && cnty > 0) res += M - (right - 1);

            if(left == right){
                right++;
            }else{
                if(B[left] == X) cntx--;
                if(B[left] == Y) cnty--;
            }
        }
        return res;
    };

    ll ans = 0;
    vector<int> B;
    for(int i = 0; i <= N; i++){
        // X より大きい or Y より小さい A の要素を境目にした配列 B で尺取法
        // 最後の数列を数えるため, i == N のときも数える
        if(i == N || X < A[i] || A[i] < Y){
            ans += calc(B);
            B.clear();
        }else{
            B.emplace_back(A[i]);
        }
    }

    cout << ans << endl;
}