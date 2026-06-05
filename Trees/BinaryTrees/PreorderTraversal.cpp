class Solution {
private:
    void Preorder(TreeNode*root,vector<int>&ans){

        // base case
        if(root==NULL){
            return;
        }

        // The logic of preorder is NLR
          ans.push_back(root->val);
          Preorder(root->left,ans);
          Preorder(root->right,ans);
    }    
public:
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int>ans;
        Preorder(root,ans);

        return ans;
    }
};
