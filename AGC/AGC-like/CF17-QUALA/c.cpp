#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

bool solve(int H, int W, vector<string> a){
    map<char, int> cnt;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++) cnt[a[i][j]]++;
    }

    int c1 = (H % 2 == 1 && W % 2 == 1);
    int c2 = (H % 2 == 1 ? W / 2 : 0) + (W % 2 == 1 ? H / 2 : 0);
    int c4 = H / 2 * W / 2;

    for(char c = 'a'; c <= 'z'; c++){
        while(4 <= cnt[c] && c4 > 0){
            cnt[c] -= 4;
            c4--;
        }
    }
    for(char c = 'a'; c <= 'z'; c++){
        while(2 <= cnt[c] && c2 > 0){
            cnt[c] -= 2;
            c2--;
        }
    }
    for(char c = 'a'; c <= 'z'; c++){
        while(1 <= cnt[c] && c1 > 0){
            cnt[c]--;
            c1--;
        }
    }
    debug(cnt);
    
    for(auto [key, val]: cnt){
        if(0 < val) return false;
    }
    return true;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int H, W;
    cin >> H >> W;
    vector<string> a(H);
    for(int i = 0; i < H; i++) cin >> a[i];
    cout << (solve(H, W, a) ? "Yes" : "No") << endl;
}