#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int t = 0 ; t < T; t++){
        int N;
        cin >> N;
    
    int maximum = 0;
    for(int i = 0 ; i < N; i++){
        int x;
        cin >> x;
        if(x > maximum){
            maximum = x;
        }
        
    }
    cout << maximum << "\n";
    }

}
