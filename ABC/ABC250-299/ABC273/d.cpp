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
    int H, W, rs, cs;
    cin >> H >> W >> rs >> cs, rs--, cs--;
    int N;
    cin >> N;
    vector<int> r(N), c(N);
    for(int i = 0; i < N; i++) cin >> r[i] >> c[i], r[i]--, c[i]--;
    int Q;
    cin >> Q;

    // R[i] := i行目にある壁の列番号
    // C[i] := i列目にある壁の行番号
    map<int, set<int>> R, C;
    for(int i = 0; i < N; i++){
        R[r[i]].insert(c[i]);
        C[c[i]].insert(r[i]);
    }

    while(Q--){
        char d; int l; cin >> d >> l;
        if(d == 'L'){
            // 自分の位置よりも1つ右の壁の位置
            auto itr = R[rs].lower_bound(cs);
            if(itr == R[rs].begin()){
                // いけるのはmax(長さ, 0)
                cs = max(cs - l, 0);
            }else{
                // いけるのはmax(長さ, 1つ左の壁 + 1)
                cs = max(cs - l, *(--itr) + 1);
            }
        }
        if(d == 'R'){
            // 自分の位置よりも1つ右の壁の位置
            auto itr = R[rs].lower_bound(cs);
            if(itr == R[rs].end()){
                // いけるのはmin(長さ, W)
                cs = min(cs + l, W - 1);
            }else{
                // いけるのはmin(長さ, 1つ右の壁 - 1)
                cs = min(cs + l, *itr - 1);
            }
        }
        if(d == 'U'){
            // 自分の位置よりも1つ下の壁の位置
            auto itr = C[cs].lower_bound(rs);
            if(itr == C[cs].begin()){
                // いけるのはmax(長さ, 0)
                rs = max(rs - l, 0);
            }else{
                // いけるのはmax(長さ, 1つ上の壁 + 1)
                rs = max(rs - l, *(--itr) + 1);
            }
        }
        if(d == 'D'){
            // 自分の位置よりも1つ下の壁の位置
            auto itr = C[cs].lower_bound(rs);
            if(itr == C[cs].end()){
                // いけるのはmin(長さ, H - 1)
                rs = min(rs + l, H - 1);
            }else{
                // いけるのはmin(長さ, 1つ下の壁の位置 - 1)
                rs = min(rs + l, *itr - 1);
            }
        }

        cout << rs + 1 << " " << cs + 1 << '\n';
    }
}