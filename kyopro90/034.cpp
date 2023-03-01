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
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    map<int, int> mp;
    int ans = 0;
    for(int left = 0, right = 0; left < N; left++){
        while(right < N && mp.size() <= K){
            mp[A[right]]++;
            right++;
        }

        ans = max(ans, right - left);
        mp[A[left]]--;
        if(mp[A[left]] == 0) mp.erase(A[left]);
    }

    cout << ans << endl;
}