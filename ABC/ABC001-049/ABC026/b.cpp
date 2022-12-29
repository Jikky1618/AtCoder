#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const double PI = acos(-1);

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<int> R(N);
    for(int i = 0; i < N; i++) cin >> R[i];

    sort(R.begin(), R.end());
    double ans = 0;
    for(int i = 0; i < N; i++){
        if(i % 2 == 0) ans += R[N - i - 1] * R[N - i - 1] * PI;
        else ans -= R[N - i - 1] * R[N - i - 1] * PI;
    }

    cout << ans << endl;
    return 0;
}