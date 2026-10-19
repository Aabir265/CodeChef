#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
  public:
    bool searchInBST(Node* root, int x) {
        // return true if x is present
        if(root == NULL){
            return false;
        }
        if(root->val == x){
            return true;
        }
        if(x < root->val){
            return searchInBST(root->left , x);
        }
        return searchInBST(root->right , x);

    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, x;
    if (!(cin >> n >> x)) return 0;
    
    Node* root = nullptr;
    if (n == 1) {
        root = new Node(1);
    } else {
        unordered_map<int, Node*> nodeMap;
        unordered_set<int> children;
        
        for (int i = 0; i < n - 1; ++i) {
            int p, c;
            char direction;
            cin >> p >> c >> direction;
            
            if (nodeMap.find(p) == nodeMap.end()) {
                nodeMap[p] = new Node(p);
            }
            if (nodeMap.find(c) == nodeMap.end()) {
                nodeMap[c] = new Node(c);
            }
            
            if (direction == 'L') {
                nodeMap[p]->left = nodeMap[c];
            } else {
                nodeMap[p]->right = nodeMap[c];
            }
            children.insert(c);
        }
        
        for (auto const& [key, val] : nodeMap) {
            if (children.find(key) == children.end()) {
                root = val;
                break;
            }
        }
    }
    
    Solution sol;
    if (sol.searchInBST(root, x)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    
    return 0;
}