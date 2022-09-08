#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n,x,y,z;
    cin >> n >> x >> y >> z;
    vector<int> a(n),b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    
    vector<bool> passed(n);
    for(int i = 0; i < x; i++){
        int max = -1;
        for(int j = 0; j < n; j++){
            if(!passed[j]){
                if(max == -1 || a[j] > a[max]) max = j;
            }
        }
        passed[max] = true;
    }

    for(int i = 0; i < y; i++){
        int max = -1;
        for(int j = 0; j < n; j++){
            if(!passed[j]){
                if(max == -1 || b[j] > b[max]) max = j;
            }
        }
        passed[max] = true;
    }
    for(int i = 0; i < z; i++){
        int max = -1;
        for(int j = 0; j < n; j++){
            if(!passed[j]){
                if(max == -1 || a[max] + b[max] < a[j] + b[j]) max = j;
            }
        }
        passed[max] = true;
    }

    for(int i = 0; i < n; i++){
        if(passed[i]) cout << i + 1 << endl;
    }

    return 0;
}