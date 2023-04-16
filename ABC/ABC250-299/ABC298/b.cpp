#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

template<class T>
vector<vector<T>> rotate(const vector<vector<T>>& A){
    int h = A.size(), w = A.front().size();
    vector res(w, vector<T>(h));
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            res[w - 1 - j][i] = A[i][j];
        }
    }
    return res;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector A(N, vector<int>(N));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> A[i][j];
        }
    }
    vector B(N, vector<int>(N));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> B[i][j];
        }
    }

    for(int k = 0; k < 4; k++){
        bool flag = true;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(A[i][j] == 1 && B[i][j] == 0) flag = false;
            }
        }

        if(flag){
            cout << "Yes" << endl;
            return 0;
        }

        A = rotate(A);
    }

    cout << "No" << endl;
}