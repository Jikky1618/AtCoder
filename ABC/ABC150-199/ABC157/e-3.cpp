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
    int N, Q;
    string S;
    cin >> N >> S >> Q;

    // st[c] := 文字 c の index の集合
    vector<set<int>> st(26);
    for(int i = 0; i < N; i++) st[S[i] - 'a'].insert(i);

    while(Q--){
        int type; cin >> type;
        if(type == 1){
            int i; char c; cin >> i >> c, i--;
            st[S[i] - 'a'].erase(i);
            st[c - 'a'].insert(i);
            S[i] = c;
        }
        if(type == 2){
            int l, r; cin >> l >> r, l--;
            int ans = 0;
            for(int i = 0; i < 26; i++){
                // st[i] の [l, r) の区間内に文字 i があるか
                auto itr = st[i].lower_bound(l);
                if(itr == st[i].end()) continue;
                if(*st[i].lower_bound(l) < r) ans++;
            }
            cout << ans << '\n';
        }
    }
}