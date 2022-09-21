#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<pair<string,string>> name(n);
    for(int i = 0; i < n; i++){
        cin >> name[i].first >> name[i].second;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i != j && name[i] == name[j]){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;

    return 0;
}