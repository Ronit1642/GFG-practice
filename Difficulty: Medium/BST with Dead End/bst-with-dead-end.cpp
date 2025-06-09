class Solution {
  public:
    void LNR(Node *root,vector<int> &v,unordered_map<int,bool> &mp){
        if(root == NULL){
            return;
        }
        
        LNR(root->left,v,mp);
        if(root->left == NULL && root->right == NULL){
            v.push_back(root->data);
        }else{
            mp[root->data] = true;
        }
        LNR(root->right,v,mp);
    }
    bool isDeadEnd(Node *root) {
        // Code here
        unordered_map<int,bool> mp;
        vector<int> v;
        LNR(root,v,mp);
        
        for(auto i : v){
            if((i == 1) && mp[2] == true){
                return true;
            }
            
            if(mp[i-1] == true && mp[i+1] == true){
                return true;
            }
        }
        
        return false;
    }
};