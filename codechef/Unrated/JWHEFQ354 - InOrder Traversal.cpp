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
    void inOrderTraversal(Node* root) {
        if(root== NULL){
            return;
        }
        inOrderTraversal(root->left);
        cout << root->val <<endl;
        inOrderTraversal(root->right);
        
        
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;
    
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
    sol.inOrderTraversal(root);
    cout << "\n";
    
    return 0;
}