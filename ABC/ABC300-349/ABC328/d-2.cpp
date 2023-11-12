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
    string S;
    cin >> S;
    
    // deque でやってみる
    deque<char> deq;
    for(auto c: S){
        deq.emplace_back(c);
        // 後ろ 3 文字を見る
        while(deq.size() >= 3){
            int N = deq.size();
            if(deq[N - 1] == 'C' && deq[N - 2] == 'B' && deq[N - 3] == 'A'){
                for(int i = 0; i < 3; i++) deq.pop_back();
            }else{
                break;
            }
        }
    }

    string ans = "";
    for(auto c: deq) ans += c;
    cout << ans << endl;
}