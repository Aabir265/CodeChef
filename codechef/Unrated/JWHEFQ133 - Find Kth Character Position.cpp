#include <bits/stdc++.h>
using namespace std;

int main() {
    string s1;
    char c1;
    int k;
    cin >> s1;
    cin >> c1;
    cin >> k;
    int count = 0;
    for(int i =0 ; i < s1.size() ; i++){
        if(s1[i] == c1){
            count++;
            if(count == k){
                cout << i << endl;
                return 0;
            }
        }
    }
    cout << -1 <<endl;
    return 0;

}
