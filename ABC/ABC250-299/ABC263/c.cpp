#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void dfs(vector<int> &A, int N, int M){
    int size = A.size();
    if(size == N){
        for(auto i: A){
            cout << i << " ";
        }
        cout << endl;
        return;
    };

    int pos = 0;
    if(size != 0) pos = A.back();
    for(int i = pos + 1; i <= M; i++){
        A.push_back(i);
        dfs(A, N, M);
        A.pop_back();
    }
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, M;
    cin >> N >> M;
    
    vector<int> A;
    dfs(A, N, M);
    return 0;
}