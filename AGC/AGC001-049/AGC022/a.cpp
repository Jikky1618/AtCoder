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

    int N = S.size();
    // N が 26未満なら
    if(N < 26){
        set<char> st;
        for(int i = 0; i < N; i++) st.insert(S[i]);

        // N にない最小の文字 nx
        char nx = 'a';
        for(char c = 'a'; c <= 'z'; c++){
            if(st.count(c) == 0){
                nx = c;
                break;
            }
        }

        // 答えは S + nx
        string ans = S + nx;
        cout << ans << endl;
    // N が 26なら
    }else{
        string SNP = S;
        bool check = next_permutation(SNP.begin(), SNP.end());
        // 次の順列に移れなかったら, -1
        if(check == false){
            cout << -1 << endl;
            return 0;
        }

        // 答えは S と SNP が一致している部分 + 一致していないSNPの1文字目
        string ans = "";
        for(int i = 0; i < N; i++){
            if(S[i] == SNP[i]){
                ans += SNP[i];
            }else{
                ans += SNP[i];
                break;
            }
        }

        cout << ans << endl;
    }
}