pair<int, int> findMinMax(int n, const vector<int>& arr) {
    int min = arr[0];
    int max = arr[0];
    for(int i = 1 ; i < n ; i++){
        if(arr[i] < min){
            min = arr[i];
        }
            if(arr[i] > max){
                max = arr[i];
            }
        }
        return{min , max};
    }
