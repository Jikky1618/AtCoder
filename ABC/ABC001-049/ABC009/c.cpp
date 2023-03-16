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
    string S;
    cin >> N >> K >> S;

    // cnt[i] := Sに使われているiの文字数
    map<char, int> cnt;
    for(auto c: S) cnt[c]++;

    // cnt2[i] := Tに使えるiの文字数
    map<char, int> cnt2 = cnt;
    string T = "";

    for(int i = 0; i < N; i++){
        cnt[S[i]]--;
        // T[i]の文字を決める
        for(char c = 'a'; c <= 'z'; c++){
            if(cnt2[c] == 0) continue; // cが使えないならcontinue

            // remain := 変えることのできる文字数
            int remain = K;
            if(c != S[i]) remain--; // 異なるならremainを1減らす
            cnt2[c]--; // 文字cを使う

            // i番目以降の不一致の数を求める
            for(char d = 'a'; d <= 'z'; d++){
                remain -= max(cnt[d] - cnt2[d], 0);
            }

            // もし変えることができるなら -> 変更する
            if(remain >= 0){
                T += c;
                if(c != S[i]) K--;
                break;
            }
            // 変えることができないなら -> 文字cを使わない
            cnt2[c]++;
        }
    }

    cout << T << endl;
}