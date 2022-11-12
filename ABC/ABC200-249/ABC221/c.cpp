#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string n;
    cin >> n;

    sort(n.begin(), n.end());
    int ans = 0;
    do{
        for(int i = 0; i < n.size(); i++){
            if(n[0] == '0' || n[i] == '0') continue;
            int num1 = stoi(n.substr(0,i));
            int num2 = stoi(n.substr(i));
            
            ans = max(ans, num1 * num2);
        }
    }while(next_permutation(n.begin(), n.end()));

    cout << ans << endl;
    return 0;
}