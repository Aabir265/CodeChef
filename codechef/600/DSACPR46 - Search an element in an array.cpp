#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    int X;
    cin >> N;
    cin >> X;
    int A[N];
    for(int i = 0 ; i < N ; i++){
        cin >> A[i];
    }
    bool found= false;
    for(int i =0; i < N ; i++){
        if(A[i] == X){
            found = true;
            break;
        }
    }
    if(found){
        cout << "YES" << "\n";
    }
    else{
        cout << "NO" << "\n";
    }
    return 0;

}
