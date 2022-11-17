#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n,a,b;
    cin >> n >> a >> b;

    int sum = 0;
    for(int i = 1; i <= n; i++){
        string s = to_string(i);
        int m = s.size();
        int cnt = 0;
        for(int j = 0; j < m; j++){
            cnt += s[j] - '0';
        }
        if(a <= cnt && cnt <= b) sum += i;
    }
    

    cout << sum << endl;
    return 0;
}