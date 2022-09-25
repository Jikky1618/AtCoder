#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> l(n);
    for(int i = 0; i < n; i++) cin >> l[i];

    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                if(l[i] != l[j] && l[j] != l[k] && l[i] != l[k]){
                    int sum = l[i] + l[j] + l[k];
                    int Max = max({l[i],l[j],l[k]});
                    int other = sum - Max;
                    if(other > Max) cnt++;
                }
            }
        }
    }

    cout << cnt << endl;
    
    return 0;
}