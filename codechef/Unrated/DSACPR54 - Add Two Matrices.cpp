#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	int M;
	cin >> N;
	cin >> M;
	int A[N][M];
	int B[N][M];
	for(int i = 0 ; i < N ; i++){
	    for(int j = 0 ; j < M ; j++){
	        cin >> A[i][j];
	    }
	}
	for(int i = 0 ; i < N ; i++){
	    for(int j = 0 ; j < M ; j++){
	        cin >> B[i][j];
	    }
	}
	int C[N][M];
	for(int i = 0 ; i < N ; i++){
	    for(int j = 0 ; j < M ;j++){
	        C[i][j] = A[i][j] + B[i][j];
	    }
	}
	for(int i = 0 ; i < N ; i++){
	    for(int j = 0; j < M ; j++){
	        cout << C[i][j]<< " ";
	    }
	    cout << endl;
	}
	

}
