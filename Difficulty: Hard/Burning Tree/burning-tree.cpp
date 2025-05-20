/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int maxDepth(Node* root){
        if(root == NULL){
            return 0;
        }
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
    
    int travel(Node* root, int &ans, int &target){
        // travel return 0 krta hai yeh 1 krta hai yeh humein btayega ki humein target mila ki nhi
        if(root == NULL){
            return 0;
        }
        if(root->data == target){
            int lft = maxDepth(root->left);
            int rgt = maxDepth(root->right);
            ans = max(lft, rgt);
            return 1;
        }
        int lh = travel(root->left, ans, target);
        if(lh){
            ans = max(ans, lh + maxDepth(root->right));
            return 1 + lh;
        }
        int rh = travel(root->right, ans, target);
        if(rh){
            ans = max(ans, rh + maxDepth(root->left));
            return 1 + rh;
        }
        return 0;
    }
    
    int minTime(Node* root, int target) {
        // This will be carry the time taken to burn the farthest node 
        int ans = 0;
        travel(root, ans, target);
        return ans;
    }
};