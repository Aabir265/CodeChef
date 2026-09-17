#include <bits/stdc++.h>
using namespace std;

int main() {
    // Define the array
    int array[] = {3, 5, 2, 9, 7, 1};
    int length = sizeof(array) / sizeof(array[0]);
    bool found = false;

    // Check if 7 is present in the array
    for (int i = 0; i < length; ++i) {
        if (array[i] == 7) {
            found = true;
            break;
        }
    }

    // Print the result
    if (found) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
