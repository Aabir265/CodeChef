#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int val) {
        this->val = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    void preOrderTraversal(Node* root) {
        if(root == NULL){
            return;
        }
        cout << root->val<<endl;
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
        }
        
    
};

void inOrder(Node* root, vector<int> &nodes){
    if(root == NULL)
      return;
    inOrder(root -> left, nodes);
    nodes.push_back(root->val);
    inOrder(root -> right, nodes);
}

Node* buildBinaryTree(vector<pair<pair<int, int>, char>>& edges) {
    map<int, Node*> nodes;
    set<Node*> children;

    // Create nodes for each edge
    for (const auto& edge : edges) {
        int parentVal = edge.first.first, childVal = edge.first.second;
        char direction = edge.second;

        Node* parentNode;
        Node* childNode;

        // Check if the parent node already exists
        if (nodes.find(parentVal) == nodes.end()) {
            parentNode = new Node(parentVal);
            nodes[parentVal] = parentNode;
        } else {
            parentNode = nodes[parentVal];
        }

        // Similarly create the child node if not already created
        if(nodes.find(childVal) == nodes.end()) {
          childNode = new Node(childVal);
          nodes[childVal] = childNode;
        }
        else {
          childNode = nodes[childVal];
        }
        

        // Attach the child node to the parent based on the direction
        if (direction == 'L') {
            parentNode->left = childNode;
        } else {
            parentNode->right = childNode;
        }

        // Update the set with the child node
        children.insert(childNode);
    }

    // The root of the binary tree is the node without a parent
    Node* root = NULL;
    for (const auto& it : nodes) {
        if (children.find(it.second) == children.end()) {
            root = it.second;
            break;
        }
    }
    return root;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);  
    int nodes;
    cin >> nodes;
    assert(nodes >= 1 && nodes <= 10000);
    vector<int> bt_nodes;
    vector<pair<pair<int, int>, char > > edges;

    set<int> unique_nodes;
 
    for(int i = 1; i < nodes; i++){
        int p, c;
        char r;
        cin >> p >> c >> r;
        assert(p >= 1 && p <= 100000);
        assert(c >= 1 && c <= 100000);
        assert(r == 'L' || r == 'R');
        unique_nodes.insert(p);
        unique_nodes.insert(c);
        edges.push_back({{p, c}, r});
    }
    
    
    Node* root = buildBinaryTree(edges);

 
    inOrder(root, bt_nodes);


    assert(unique_nodes.size() == nodes);
    assert(bt_nodes.size() == nodes);
   

    Solution sol;
    sol.preOrderTraversal(root);
    
    bt_nodes.clear();

    inOrder(root, bt_nodes);
    assert(unique_nodes.size() == nodes); 
    assert(bt_nodes.size() == nodes);

    return 0;
}
