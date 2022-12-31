#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;

    vector<int> ans(N + 1);
    // x, y, z の上界は高々100
    for(int x = 1; x <= 100; x++){
        for(int y = 1; y <= 100; y++){
            for(int z = 1; z <= 100; z++){
                int val = x*x + y*y + z*z + x*y + y*z + z*x;
                if(val <= N) ans[val]++;
            }
        }
    }

    for(int i = 1; i <= N; i++) cout << ans[i] << endl;
    return 0;
}