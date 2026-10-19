#include <bits/stdc++.h>
using namespace std;

struct node {
    int val;
    node * left;
    node * right;
};

node * node_new(int val) {
    node * temp = new node();
    temp -> val = val;
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
}

node * root;

void insert(int element) {
    if (root == NULL) {
        // Assigning first element of array as root
        root = node_new(element);
        return;
    }
    node * current = root;
    
    // We start traversal to insertion position from root
    while (1) {
        if (element < current -> val) {
            // If the value is lesser, we find in left subtree where to insert
            if (current -> left == NULL) {
                cout << "Inserting " << element << " in left of " << current -> val << "\n";
                current -> left = node_new(element);
                break;
                // End the loop when insertion is done
            }
            else {
                // Repeat the process for left subtree which is also a BST
                current = current -> left;
            }
        }
        else {
            if (current -> right == NULL) {
                cout << "Inserting " << element << " in right of " << current -> val << "\n";
                current -> right = node_new(element);
                break;
            }
            else {
                current = current -> right;
            }
        }
    }
}

int main() {
    vector < int > arr = {8, 3, 10, 1, 6, 14};
    root = NULL;
    for (int i = 0; i < 6; i++) {
        insert(arr[i]);
    }
    cout << "The BST is created!";
    return 0;
}